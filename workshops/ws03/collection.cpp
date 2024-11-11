#pragma once
#include "Collection.h"
#include "Book.h"
#include "Movie.h"
#include "TVShow.h"
#include <fstream>
#include <iostream>

void Collection::addItem(MediaItem* item) {
    m_items.push_back(item);
}

void Collection::display() const {
    for (const auto& item : m_items) {
        item->display();
    }
}

void Collection::searchByTitle(const std::string& title) const {
    for (const auto& item : m_items) {
        if (item->getTitle() == title) {
            item->display();
            return;
        }
    }
    std::cout << "Item not found." << std::endl;
}

void Collection::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        if (line.starts_with("Book")) {
            m_items.push_back(Book::createItem(line));
        }
        else if (line.starts_with("Movie")) {
            m_items.push_back(Movie::createItem(line));
        }
        else if (line.starts_with("TVShow")) {
            m_items.push_back(TvShow::createItem(line));
        }
    }
}
