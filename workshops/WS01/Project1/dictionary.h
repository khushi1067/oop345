#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "settings.h"

namespace seneca {

    enum class PartOfSpeech {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection
    };

    struct Word {
        std::string m_word{};
        std::string m_definition{};
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    //manage dynamically allocated objects 
    class Dictionary {

    private:
 
        //stores number of words
        size_t m_size = 0;
        //dynamically allocate array for stiring words
        Word* m_words = nullptr;

    public:

        //default constructor
        Dictionary() {};

        //copy constructor
        Dictionary(const Dictionary& other);

        //copy assignment operator
        Dictionary& operator=(const Dictionary& other);

        //move constructor
        Dictionary(Dictionary&& other) noexcept;
        
        //move assignment operator
        Dictionary& operator=(Dictionary&& other) noexcept;
        
        // Loads words & definitions from file
        void loadFromFile(const char* filename);

        //string to determine the part of speech
        PartOfSpeech parsePartOfSpeech(const std::string& pos);

        //constructor to initialize dictionary
        Dictionary(const char* filename);

        //destructor
        ~Dictionary();

        //function to search word
        void searchWord(const char* word);


    };

} // namespace seneca

#endif
