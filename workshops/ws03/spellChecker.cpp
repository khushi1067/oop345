#pragma once

#include "SpellChecker.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

namespace seneca {

    // Constructor to initialize SpellChecker with words from a file
    SpellChecker::SpellChecker(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        int i = 0;

        // Check if the file was opened successfully
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        // Read words from the file and populate the arrays
        while (std::getline(file, line) && i < 5) {
            m_goodWords[i] = line;  // Assuming file contains good words
            ++i;
        }

        // Add some bad words for demonstration purposes
        m_badWords[0] = "misspelled";
        m_badWords[1] = "definately";
        m_badWords[2] = "recieve";
        m_badWords[3] = "teh";
        m_badWords[4] = "occurence";
    }

    // Operator() for spellchecking text
    void SpellChecker::operator()(std::string& text) const {
        // For demonstration: process the text and replace bad words with "corrected"
        for (size_t i = 0; i < 5; ++i) {
            size_t pos = 0;
            while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
                text.replace(pos, m_badWords[i].length(), "corrected");
                pos += 9; // Move past the replacement word
            }
        }
    }

    // Show statistics: count bad and good words processed
    void SpellChecker::showStatistics(std::ostream& out) const {
        int badCount = 0;
        int goodCount = 0;

        for (size_t i = 0; i < 5; ++i) {
            if (!m_badWords[i].empty()) ++badCount;
            if (!m_goodWords[i].empty()) ++goodCount;
        }

        out << "Bad words: " << badCount << std::endl;
        out << "Good words: " << goodCount << std::endl;
    }
}

