#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <string>

namespace seneca {

    class Utilities {
        char m_delimiter;
        size_t m_widthField;

    public:
        Utilities();
        void setDelimiter(char newDelimiter);
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        size_t getFieldWidth() const;
    };

} // namespace seneca

#endif
