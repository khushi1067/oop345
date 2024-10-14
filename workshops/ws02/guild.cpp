#include "guild.h"
#include <iostream>

namespace seneca {

    //initialize default constructor
    Guild::Guild() {
        m_count = 0;
        m_capacity = 2;
        m_members = new Character * [m_capacity];
        m_name = "";
    }
       
    //parameterized constructor
    Guild::Guild(const char* name) {
        m_count = 0;
        m_capacity=2;
        m_members = new Character * [m_capacity];
        m_name = name;

    }
       
    //copy constructor
    Guild::Guild(const Guild& other) {
        //shallow copy
        m_count = other.m_count;
        m_capacity = other.m_capacity;
        
        //allocate new memory
        m_members = new Character * [m_capacity];
        
        //deep copy
        for (size_t i = 0; i < m_count; ++i) {
            m_members[i] = other.m_members[i];
        }
        
        m_name = other.m_name;
    }

    //copy assignment operator
    Guild& Guild::operator=(const Guild& other) {

        //check for self assignment
        if (this != &other) {
            
            //delete preciously allocated memory
            delete[] m_members;
            
            //copy
            m_count = other.m_count;
            m_capacity = other.m_capacity;
            
            //allocate memory
            m_members = new Character * [m_capacity];
            
            //deep copy
            for (size_t i = 0; i < m_count; ++i) {
                m_members[i] = other.m_members[i];
            }
            m_name = other.m_name;
        }
        return *this;
    }

    //move constructor
    Guild::Guild(Guild&& other) noexcept 

        //move operation
        : m_count(other.m_count),
        m_capacity(other.m_capacity), 
        m_members(other.m_members), 
        m_name(other.m_name) {
        
        //set previous memory to null
        other.m_count = 0;
        other.m_capacity = 0;
        other.m_members = nullptr;
        other.m_name = "";
    }

    //move assignment operator
    Guild& Guild::operator=(Guild&& other) noexcept {
       
        if (this != &other) {
            
            delete[] m_members;
            
            m_count = other.m_count;
            m_capacity = other.m_capacity;
            m_members = other.m_members;
            m_name = other.m_name;
            
            other.m_count = 0;
            other.m_capacity = 0;
            other.m_members = nullptr;
            other.m_name = "";
        }
        return *this;
    }

    //destructor
    Guild::~Guild() {
        delete[] m_members;
    }

 
    //add memeber to guild
    void Guild::addMember(Character* c) {

        //loop through members 
        for (size_t i = 0; i < m_count; ++i) {

            //if memeber exist exit
            if (m_members[i]->getName() == c->getName()) {
                return;
            }
        }

        //if m_count=m_capacity is full
        if (m_count == m_capacity) {
            //resize
            m_capacity *= 2;

            //allocate memory
            Character** temp = new Character * [m_capacity];
            
            for (size_t i = 0; i < m_count; ++i) {
                temp[i] = m_members[i];
            }

            delete[] m_members;
            m_members = temp;
        }
        //set heatthmax + 300
        c->setHealthMax(c->getHealthMax() + 300);
        
        //set health to max health
        c->setHealth(c->getHealthMax());

        //increment members
        m_members[m_count++] = c;
    }

    //remove memebers
    void Guild::removeMember(const std::string& c) {
        // Initialize the index 
        int index = -1;
       
        // Search for the member by name

        for (size_t i = 0; i < m_count; ++i) {

            // if Found member
            if (m_members[i]->getName() == c) {

               // store the index
                index = i;
                break;
            }
        }

        //// If the member was not found
        if (index == -1) {
            return;
        }

        // Adjust the member's health attributes

        m_members[index]->setHealthMax(m_members[index]->getHealthMax() - 300);
        m_members[index]->setHealth(m_members[index]->getHealthMax());
        for (size_t i = index; i < m_count - 1; ++i) {
            m_members[i] = m_members[i + 1];
        }

        // Decrement the count of members in the guild
        m_count--;
    }


    Character* Guild::operator[](size_t idx) const {
        //if idx<m_count
        if (idx < m_count) {
            //return
            return m_members[idx];
        }
        else
        {
            return nullptr;
        }
        //return (idx < m_count) ? m_members[idx] : nullptr;
    }

    void Guild::showMembers() const {
        //if capacity is 0
        if (m_capacity == 0) {
            //print no guild name
            std::cout << "No guild" << m_name << ".\n";
            return;
        }
        //print
        std::cout << "[Guild] " << m_name << "\n";
        
        for (size_t i = 0; i < m_count; ++i) {
            std::cout << "    " << i + 1 << ": " << *m_members[i] << "\n";
        }
    }

} // namespace seneca
