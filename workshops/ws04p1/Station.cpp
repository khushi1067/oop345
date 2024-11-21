#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>
#include <string>

namespace seneca {

    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    // Custom constructor
    Station::Station(const std::string& record) {
        Utilities util;
        size_t next_pos = 0;
        bool more = true;

        m_id = ++id_generator;

        m_itemName = util.extractToken(record, next_pos, more);
        m_serialNumber = std::stoul(util.extractToken(record, next_pos, more));
        m_quantity = std::stoul(util.extractToken(record, next_pos, more));
        m_description = util.extractToken(record, next_pos, more);

        if (m_widthField < util.getFieldWidth()) {
            m_widthField = util.getFieldWidth();
        }
    }

    const std::string& Station::getItemName() const {
        return m_itemName;
    }

    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const {
        return m_quantity;
    }

    void Station::updateQuantity() {
        if (m_quantity > 0) {
            --m_quantity;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        os << "[" << std::setw(3) << std::setfill('0') << m_id << "] ";
        os << "Item: " << std::setw(m_widthField) << std::left << m_itemName;
        os << " [" << std::setw(6) << std::setfill('0') << m_serialNumber << "]";

        if (full) {
            os << " Quantity: " << std::setw(4) << std::right << m_quantity;
            os << " Description: " << m_description;
        }
        os << std::endl;
    }

} // namespace seneca
