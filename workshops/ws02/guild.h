#pragma once
#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"
#include <iostream>
#include <string>

namespace seneca
{
	class Guild
	{
	private:
		Character** m_members; // Array of pointers to Character
		size_t m_count; // Current number of members
		size_t m_capacity; // Capacity of the array
		std::string m_name; // Name of the guild

		void resize(); // Resize the array when needed

	public:
		Guild(); // Default constructor
		Guild(const char* name); // Constructor with guild name
		Guild(const Guild& other); // Copy constructor
		Guild(Guild&& other) noexcept; // Move constructor
		Guild& operator=(const Guild& other); // Copy assignment
		Guild& operator=(Guild&& other) noexcept; // Move assignment
		~Guild(); // Destructor

		void addMember(Character* c); // Add member to the guild
		void removeMember(const std::string& c); // Remove member from the guild
		Character* operator[](size_t idx) const; // Access member by index
		void showMembers() const; // Display members of the guild
	};
}

#endif
