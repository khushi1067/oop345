#include "Team.h"
#include "weapons.h"
#include <iostream>

namespace seneca {

    // Default constructor initialize
    Team::Team() 
        : teamName(""),
        members(nullptr),
        numMembers(0), 
        capacity(0) {}


    // Constructor that initialize
    Team::Team(const char* name)
        : teamName(name), 
        members(nullptr), 
        numMembers(0), 
        capacity(0) {}


    // Destructor 
    Team::~Team() {
        for (size_t i = 0; i < numMembers; ++i) {
            delete members[i]; 
        }
        delete[] members;      
    }

    // Copy constructor 
    Team::Team(const Team& other) 
        : teamName(other.teamName), 
        numMembers(other.numMembers), 
        capacity(other.capacity) {
        //allocate new array
        members = new Character * [capacity];
        //deep copy
        for (size_t i = 0; i < numMembers; ++i) {
            members[i] = other.members[i]->clone(); 
        }
    }

    // Copy assignment operator
    Team& Team::operator=(const Team& other) {

        //check for self assignment
        if (this != &other) { 
            // Delete previously allocated memory
            for (size_t i = 0; i < numMembers; ++i) {
                //delete memory
                delete members[i];
            }
            delete[] members;

            // shallow copy
            teamName = other.teamName;
            numMembers = other.numMembers;
            capacity = other.capacity;

            //allocate new memory
            members = new Character * [capacity];

            //deep copy
            for (size_t i = 0; i < numMembers; ++i) {
                members[i] = other.members[i]->clone();
            }
        }

        //return instance
        return *this;
    }

    // Move constructor 
    Team::Team(Team&& other) noexcept 
        : teamName(std::move(other.teamName)),
        members(other.members), 
        numMembers(other.numMembers), 
        capacity(other.capacity) {

        //set previously allocated memory to null
        other.members = nullptr; 
        other.numMembers = 0;
        other.capacity = 0;
    }

    // Move assignment operator 
    Team& Team::operator=(Team&& other) noexcept {

        //check self assifnment
        if (this != &other) {
            // Delete previously allocated memory
            for (size_t i = 0; i < numMembers; ++i) {

                delete members[i];
            }
            delete[] members;

            // move
            teamName = std::move(other.teamName);
            members = other.members;
            numMembers = other.numMembers;
            capacity = other.capacity;

            // set previous elements to null
            other.members = nullptr;
            other.numMembers = 0;
            other.capacity = 0;
        }

        //return instance
        return *this;
    }

    // Resizes the members array to the specified new capacity
    void Team::resize(size_t newCapacity) {
        Character** temp = new Character * [newCapacity]; // Allocate new array
        for (size_t i = 0; i < numMembers; ++i) {
            temp[i] = members[i]; // Copy existing members to new array
        }
        delete[] members; // Delete old array
        members = temp;   // Point to new array
        capacity = newCapacity;
    }

    // Adds member
    void Team::addMember(const Character* c) {
        //check for null ptr
        if (!c) return;

        // Check for duplicate
        for (size_t i = 0; i < numMembers; ++i) {
            if (members[i]->getName() == c->getName()) {
                return; // Exit if character already exists
            }
        }

        // Resize if needed
        if (numMembers >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2); // Double the capacity
        }

        members[numMembers++] = c->clone(); // Add clone of the character
    }

    // Removes a Character from the team by name
    void Team::removeMember(const std::string& c) {
        for (size_t i = 0; i < numMembers; ++i) {
            if (members[i]->getName() == c) {
                delete members[i]; // Delete the character

                // Shift remaining members
                for (size_t j = i; j < numMembers - 1; ++j) {
                    members[j] = members[j + 1];
                }
                --numMembers; // Decrease member count
                return;
            }
        }
    }

    // Overloaded subscript operator to access a Character by index
    Character* Team::operator[](size_t idx) const {
        if (idx < numMembers) {
            return members[idx]; // Return member if index is valid
        }
        return nullptr; // Return nullptr if out of bounds
    }

    // Displays the members of the team
    void Team::showMembers() const {
        if (numMembers == 0) {
            std::cout << "No team." << std::endl; // Print if team is empty
            return;
        }

        std::cout << "[Team] " << teamName << std::endl;
        for (size_t i = 0; i < numMembers; ++i) {
            std::cout << "    " << (i + 1) << ": " << *members[i] << std::endl; // Print each member
        }
    }

}
