#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <string>
#include "mediaItem.h"

namespace seneca
{
    class Movie : public MediaItem {
    public:
        
        //default constructor
        Movie();
       
        //constructor and initialization
        Movie(const std::string& title, 
            unsigned short year, 
            const std::string& summary);
        
        //display function
        void display(std::ostream& out) const override;
        
        //reading data
        static Movie* createItem(const std::string& strMovie);
    };

}

#endif