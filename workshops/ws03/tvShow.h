// tvShow.h
#ifndef TVSHOW_H
#define TVSHOW_H

#include <vector>
#include "mediaItem.h"

namespace seneca {
    struct TvEpisode {
        const TvShow* m_show{};
        unsigned short m_numberOverall{};
        unsigned short m_season{};
        unsigned short m_numberInSeason{};
        std::string m_airDate{};
        unsigned int m_length{};
        std::string m_title{};
        std::string m_summary{};
    };

    class TvShow : public MediaItem {
        int m_id;
        std::vector<TvEpisode> m_episodes;

        TvShow(int id, const std::string& title, int year, const std::string& summary);

    public:
        void display(std::ostream& out) const override;
    };
}

#endif
