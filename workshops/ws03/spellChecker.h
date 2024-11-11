#pragma once
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <string>
#include <iostream>

namespace seneca {

    // Class responsible for spell checking
    class SpellChecker {
        std::string m_badWords[5];   // Fixed array for bad words (demonstration purpose)
        std::string m_goodWords[5];  // Fixed array for good words (demonstration purpose)

    public:
        // Constructor to initialize the SpellChecker with a dictionary file
        SpellChecker(const std::string& filename);

        // Operator to process the input text and perform spell-checking
        void operator()(std::string& text) const;

        // Show statistics about the spell checking process (e.g., counts)
        void showStatistics(std::ostream& out) const;
    };

}

#endif
