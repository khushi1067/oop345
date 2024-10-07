#pragma once
#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <iostream>
#include <string>
#include "Character.h"

namespace seneca {


    class Team {

        //team name
        std::string teamName;
        //array of pointer of Character
        Character** members;
        //store number of members on team
        size_t numMembers;
        //store capacity of array
        size_t capacity;

        void resize(size_t newCapacity);  // Helper function to resize the array

    public:
        // Default constructor
        Team();          

        // Constructor with team name
        Team(const char* name);


        // Rule of 5

        //destructor
        ~Team();

        //copy constructor
        Team(const Team& other);

        //copy assignment operator
        Team& operator=(const Team& other);

        //move constructor
        Team(Team&& other) noexcept;

        //move assignment operator
        Team& operator=(Team&& other) noexcept;


        // Add member if name is unique, resize if necessary
        void addMember(const Character* c);

        // Remove member by name
        void removeMember(const std::string& c);

        // Access operator (read-only)
        Character* operator[](size_t idx) const;

        // Show team members
        void showMembers() const;
    };
}
#endif