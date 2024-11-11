// book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "mediaItem.h"

namespace seneca {
    class Book : public MediaItem {
        std::string m_author;
        std::string m_country;
        double m_price;

        Book(const std::string& author, const std::string& title, const std::string& country,
            double price, int year, const std::string& summary);

    public:
        void display(std::ostream& out) const override;
        static Book* createItem(const std::string& strBook);
    };
}

#endif
