#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"
#include <string>

namespace seneca {

    class Guild {
        // Current number of members
        size_t m_count;

        // Capacity of the array
        size_t m_capacity;

        // Array of pointers to Character
        Character** m_members;

        // Name of the guild
        std::string m_name;


    public:
        // Default constructor
        Guild();

        // Constructor with guild name
        Guild(const char* name);

        // Copy constructor
        Guild(const Guild& other);

        // Copy assignment operator
        Guild& operator=(const Guild& other);


        // Move constructor
        Guild(Guild&& other) noexcept;

        // move assignment operator
        Guild& operator=(Guild&& other) noexcept;

        // Destructor
        ~Guild();

        // Add member to the guild
        void addMember(Character* c);

        // Remove member from the guild
        void removeMember(const std::string& c);

        // Access member by index
        Character* operator[](size_t idx) const;

        // Display members of the guild
        void showMembers() const;
    };

} // namespace seneca

#endif // SENECA_GUILD_H

