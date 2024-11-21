#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <string>
#include <iostream>

namespace seneca {

    class Utilities;  // Forward declaration to avoid circular dependency

    class Station {
        int m_id;
        std::string m_itemName;
        std::string m_description;
        size_t m_serialNumber;
        size_t m_quantity;

        static size_t m_widthField;
        static int id_generator;

    public:
        // Custom constructor
        Station(const std::string& record);

        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };

} // namespace seneca

#endif
