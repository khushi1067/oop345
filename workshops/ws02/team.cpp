#include "team.h"
#include "character.h"
#include "weapons.h"

#include <iostream>
#include <string>

namespace seneca {

    Team::Team() {
        teamName = "";
        members = nullptr;
        numMembers = 0;
        capacity = 0;
    }
       

    Team::Team(const char* name) {
        teamName = name;
        members = nullptr;
        numMembers = 0;
        capacity = 0;
    }
       

    Team::~Team() {
        for (size_t i = 0; i < numMembers; ++i) {
            delete members[i];//delete each character
        }
        delete[] members; //delete member array
    }

    Team::Team(const Team& other) {
        teamName = other.teamName;
        numMembers = other.numMembers;
        capacity = other.capacity;

        members = new Character * [capacity];

        for (size_t i = 0; i < numMembers; i++){
            members[i] = other.members[i]->clone();

        }
    }
        
    Team& Team::operator=(const Team& other) {

        //check for self allocation
        if (this != &other) {
            //clean up previously allocated memory
            for (size_t i = 0; i < numMembers; ++i) {
                //delete memeory
                delete members[i];
            }
            delete[] members;

            //copy shallow
            teamName = other.teamName;
            numMembers = other.numMembers;
            capacity = other.capacity;

            //allocate new memeory
            members = new Character * [capacity];

            //deep copy
            for (size_t i = 0; i < numMembers; ++i) {

                members[i] = other.members[i]->clone();
                //members[i] = other.members[i]->clone();
            }
        }
        return *this;
    }

    Team::Team(Team&& other) noexcept {
        
        //move data
        teamName = std::move(other.teamName);
        members = other.members;
        numMembers = other.numMembers;
        capacity = other.capacity;

        //previous data to null free up previously allocated memory
        other.members = nullptr;
        other.numMembers = 0;
        other.capacity = 0;

    }
        

    Team& Team::operator=(Team&& other) noexcept {
        //check for self assignment
        if (this != &other) {

            //free up previously allocated memory
            for (size_t i = 0; i < numMembers; ++i) {

                //clean up
                delete members[i];
            }
            delete[] members;

            //move 
            teamName = std::move(other.teamName);
            members = other.members;
            numMembers = other.numMembers;
            capacity = other.capacity;

            //previously allocated memory to null
            other.members = nullptr;
            other.numMembers = 0;
            other.capacity = 0;
        }
        return *this;
    }

   /* void Team::resize(size_t newCapacity) {
        Character** temp = new Character * [newCapacity];
        for (size_t i = 0; i < numMembers; ++i) {
            temp[i] = members[i];
        }
        delete[] members;
        members = temp;
        capacity = newCapacity;
    }*/

    void Team::resize(size_t newCapacity) {

        //allocate new array
        Character** temp = new Character * [newCapacity];
        
        //move data 
        for (size_t i = 0; i < numMembers; ++i) {
            temp[i] = members[i];
            //temp[i] = members[i];
        }
        //delete previously allocated memory
        delete[] members;

        //point to new allocated array
        members = temp;

        //update capacity
        capacity = newCapacity;
    }

   /* void Team::addMember(const Character* c) {
        if (!c) return;

        for (size_t i = 0; i < numMembers; ++i) {
            if (members[i]->getName() == c->getName()) {
                return;
            }
        }

        if (numMembers >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }

        members[numMembers++] = c->clone();
    }*/

    void Team::addMember(const Character* c) {

        if (!c) {
            return;
        }

        for (size_t i = 0; i < numMembers; ++i) {
            if (members[i]->getName() == c->getName()) {
                std::cout << "Member with name " << c->getName() << " already exists.\n";
                return;
            }
        }
        if (numMembers >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        members[numMembers++] = c->clone();
    }


    void Team::removeMember(const std::string& c) {

        for (size_t i = 0; i < numMembers; ++i) {
        
            if (members[i]->getName() == c) {
            
                //delete members
                delete members[i];

                for (size_t j = i; j < numMembers - 1; ++j) {
                    members[j] = members[j + 1];
                }

                //decrease number of memeber after deletion
                --numMembers;
                return;
            }
        }
    }

    Character* Team::operator[](size_t idx) const {
        return (idx < numMembers) ? members[idx] : nullptr;
    }

    void Team::showMembers() const {

        if (numMembers == 0) {
            std::cout << "No team." << std::endl;
            return;
        }

        std::cout << "[Team] " << teamName << std::endl;
        for (size_t i = 0; i < numMembers; ++i) {
            std::cout << "    " << (i + 1) << ": " << *members[i] << std::endl;
        }
    }

} // namespace seneca

