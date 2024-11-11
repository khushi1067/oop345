#pragma once
// tvShow.cpp

#include "mediaItem.h"
#include "tvShow.h"
#include "settings.h"
#include <iomanip>

namespace seneca {
    TvShow::TvShow(int id, const std::string& title, int year, const std::string& summary)
        : MediaItem(title, year, summary), m_id(id) {}

    void TvShow::display(std::ostream& out) const {
        if (g_settings.m_tableView) {
            out << "S | " << std::left << std::setw(50) << getTitle() << " | "
                << std::setw(2) << m_episodes.size() << " | "
                << std::setw(4) << getYear() << " | " << getSummary().substr(0, g_settings.m_maxSummaryWidth) << "\n";
        }
        else {
            out << getTitle() << " [" << getYear() << "]\n";
            for (const auto& ep : m_episodes) {
                out << "    S" << ep.m_season << "E" << ep.m_numberInSeason << " " << ep.m_title << "\n";
            }
        }
    }
}
