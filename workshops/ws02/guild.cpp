#include "guild.h"
#include "character.h"
#include <iostream>
#include <string>

// Default constructor
seneca::Guild::Guild() {
    m_members = nullptr;
    m_count = 0;
    m_capacity = 0;
    m_name = "Unnamed Guild";
}


// Constructor with name parameter
seneca::Guild::Guild(const char* name) {
    m_members = nullptr;
    m_count = 0;
    m_capacity = 0;
    m_name = name;
}
  

// Resize the array when necessary
void seneca::Guild::resize()
{
    size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2; // Double the capacity
    Character** newMembers = new Character * [newCapacity];

    for (size_t i = 0; i < m_count; ++i)
    {
        newMembers[i] = m_members[i]; // Copy existing members
    }

    delete[] m_members; // Free old array
    m_members = newMembers; // Point to new array
    m_capacity = newCapacity; // Update capacity
}

// Copy constructor
seneca::Guild::Guild(const Guild& other) {
    m_count = other.m_count;
    m_capacity = other.m_capacity;
    m_name = other.m_name;

    m_members = new Character * [m_capacity];
    for (size_t i = 0; i < m_count; ++i)
    {
        m_members[i] = other.m_members[i]->clone(); // Clone characters
    }
}

// Move constructor
seneca::Guild::Guild(Guild&& other) noexcept {
    m_members = other.m_members;
    m_count = other.m_count;
    m_capacity = other.m_capacity;
    m_name = std::move(other.m_name);

    other.m_members = nullptr;
    other.m_count = 0;
    other.m_capacity = 0;
}

// Copy assignment operator
seneca::Guild& seneca::Guild::operator=(const Guild& other)
{
    if (this != &other) // Self-assignment check
    {
        for (size_t i = 0; i < m_count; ++i)
        {
            delete m_members[i]; // Clean up current members
        }
        delete[] m_members;

        m_count = other.m_count;
        m_capacity = other.m_capacity;
        m_name = other.m_name;
        m_members = new Character * [m_capacity];

        for (size_t i = 0; i < m_count; ++i)
        {
            m_members[i] = other.m_members[i]->clone(); // Clone characters
        }
    }
    return *this;
}

// Move assignment operator
seneca::Guild& seneca::Guild::operator=(Guild&& other) noexcept
{
    if (this != &other) // Self-assignment check
    {
        for (size_t i = 0; i < m_count; ++i)
        {
            delete m_members[i]; // Clean up current members
        }
        delete[] m_members;

        m_members = other.m_members;
        m_count = other.m_count;
        m_capacity = other.m_capacity;
        m_name = std::move(other.m_name);

        other.m_members = nullptr;
        other.m_count = 0;
        other.m_capacity = 0;
    }
    return *this;
}

// Destructor
seneca::Guild::~Guild()
{
    for (size_t i = 0; i < m_count; ++i)
    {
        delete m_members[i]; // Clean up members
    }
    delete[] m_members; // Free array
}

// Add member to the guild
void seneca::Guild::addMember(Character* c)
{
    if (!c) return; // Null check

    for (size_t i = 0; i < m_count; ++i)
    {
        if (m_members[i]->getName() == c->getName())
            return; // Character already in guild
    }

    if (m_count >= m_capacity)
    {
        resize(); // Resize if needed
    }

    m_members[m_count++] = c->clone(); // Add cloned member
    m_members[m_count - 1]->setHealthMax(m_members[m_count - 1]->getHealthMax() + 300); // Increase health
}

// Remove member from the guild
void seneca::Guild::removeMember(const std::string& name)
{
    for (size_t i = 0; i < m_count; ++i)
    {
        if (m_members[i]->getName() == name) // Found member
        {
            m_members[i]->setHealthMax(m_members[i]->getHealthMax() - 300); // Decrease health
            delete m_members[i]; // Delete character
           
            m_members[i] = m_members[--m_count]; // Replace with last member
            return;
        }
    }
}

// Access member by index
seneca::Character* seneca::Guild::operator[](size_t idx) const
{
    return (idx < m_count) ? m_members[idx] : nullptr;
}

// Show members of the guild
void seneca::Guild::showMembers() const
{
    std::cout << "[Guild] " << m_name << std::endl;
    if (m_count == 0)
    {
        std::cout << "No guild." << std::endl;
    }
    else
    {
        for (size_t i = 0; i < m_count; ++i)
        {
            std::cout << "    " << (i + 1) << ": " << *m_members[i] << std::endl;
        }
    }
}

