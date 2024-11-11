#pragma once
// movie.cpp

#include "mediaItem.h"
#include "movie.h"
#include "settings.h"
#include <sstream>
#include <stdexcept>

namespace seneca {
    Movie::Movie(const std::string& title, int year, const std::string& summary)
        : MediaItem(title, year, summary) {}

    void Movie::display(std::ostream& out) const {
        if (g_settings.m_tableView) {
            out << "M | " << std::left << std::setw(50) << getTitle() << " | "
                << std::setw(9) << getYear() << " | " << getSummary().substr(0, g_settings.m_maxSummaryWidth) << "\n";
        }
        else {
            out << getTitle() << " [" << getYear() << "]\n";
        }
    }

    Movie* Movie::createItem(const std::string& strMovie) {
        if (strMovie.empty() || strMovie[0] == '#')
            throw std::invalid_argument("Not a valid movie.");

        std::istringstream stream(strMovie);
        std::string title, yearStr, summary;
        int year;

        std::getline(stream, title, ',');
        std::getline(stream, yearStr, ',');
        std::getline(stream, summary);

        title.erase(0, title.find_first_not_of(" "));
        year = std::stoi(yearStr);

        return new Movie(title, year, summary);
    }
}
