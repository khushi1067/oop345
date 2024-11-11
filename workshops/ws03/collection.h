#pragma once
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include "mediaItem.h"
#include <string>

namespace seneca {
    class Collection {
        std::string m_name{};
        MediaItem** m_items{ nullptr }; // array of pointers to MediaItems
        size_t m_size{ 0 };
        void (*m_observer)(const Collection&, const MediaItem&) { nullptr };

    public:
        Collection(const std::string& name) : m_name(name) {}

        ~Collection() {
            for (size_t i = 0; i < m_size; ++i) delete m_items[i];
            delete[] m_items;
        }

        void setObserver(void (*observer)(const Collection&, const MediaItem&)) {
            m_observer = observer;
        }

        Collection& operator+=(MediaItem* item) {
            auto temp = new MediaItem * [m_size + 1];
            for (size_t i = 0; i < m_size; ++i) temp[i] = m_items[i];
            temp[m_size] = item;
            delete[] m_items;
            m_items = temp;
            ++m_size;
            if (m_observer) m_observer(*this, *item);
            return *this;
        }

        const MediaItem* operator[](const char* title) const;
        size_t size() const { return m_size; }

        void display(std::ostream& out) const {
            for (size_t i = 0; i < m_size; ++i) out << *m_items[i] << "\n";
        }
    };

    inline std::ostream& operator<<(std::ostream& out, const Collection& col) {
        col.display(out);
        return out;
    }
}

#endif
