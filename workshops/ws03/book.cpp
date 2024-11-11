// book.cpp
#include "mediaItem.h"
#include "book.h"
#include "settings.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace seneca {
    Book::Book(const std::string& author, const std::string& title, const std::string& country,
        double price, int year, const std::string& summary)
        : MediaItem(title, year, summary), m_author(author), m_country(country), m_price(price) {}

    void Book::display(std::ostream& out) const {
        if (g_settings.m_tableView) {
            out << "B | " << std::left << std::setw(50) << getTitle() << " | "
                << std::setw(2) << m_country << " | "
                << std::setw(4) << getYear() << " | " << getSummary().substr(0, g_settings.m_maxSummaryWidth) << "\n";
        }
        else {
            out << getTitle() << " [" << getYear() << "] [" << m_author << "] [" << m_country << "] [" << m_price << "]\n";
        }
    }

    Book* Book::createItem(const std::string& strBook) {
        if (strBook.empty() || strBook[0] == '#')
            throw std::invalid_argument("Not a valid book.");
        std::istringstream stream(strBook);
        std::string author, title, country, priceStr, yearStr, summary;
        double price;
        int year;

        std::getline(stream, author, ',');
        std::getline(stream, title, ',');
        std::getline(stream, country, ',');
        std::getline(stream, priceStr, ',');
        std::getline(stream, yearStr, ',');
        std::getline(stream, summary);

        author.erase(0, author.find_first_not_of(" "));
        title.erase(0, title.find_first_not_of(" "));
        country.erase(0, country.find_first_not_of(" "));
        price = std::stod(priceStr);
        year = std::stoi(yearStr);

        return new Book(author, title, country, price, year, summary);
    }
}



