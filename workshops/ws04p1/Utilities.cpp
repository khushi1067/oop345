#include "Utilities.h"
#include <string>
#include <iostream>

namespace seneca {

    Utilities::Utilities() : m_delimiter(','), m_widthField(1) {}

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        std::string token;
        size_t start_pos = next_pos;

        while (next_pos < str.size() && str[next_pos] != m_delimiter) {
            token += str[next_pos++];
        }

        if (next_pos < str.size() && str[next_pos] == m_delimiter) {
            next_pos++; // Skip the delimiter
        }

        if (token.empty()) {
            more = false;
        }

        if (token.size() > m_widthField) {
            m_widthField = token.size();
        }

        return token;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

} // namespace seneca
