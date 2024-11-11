// movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "mediaItem.h"

namespace seneca {
    class Movie : public MediaItem {
        Movie(const std::string& title, int year, const std::string& summary);

    public:
        void display(std::ostream& out) const override;
        static Movie* createItem(const std::string& strMovie);
    };
}

#endif
