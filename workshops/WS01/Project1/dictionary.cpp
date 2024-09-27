#define _CRT_SECURE_NO_WARNINGS
#include "dictionary.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<cstring>
#include<iomanip>
namespace seneca {


    // Copy constructor 
    Dictionary::Dictionary(const Dictionary& other) {
        //initilaize properties
        m_size = other.m_size;
        m_words = nullptr; 

        //copy words if the other dictionary has words
        if (other.m_words) {
            //allocate new memory
            m_words = new Word[m_size];
            for (size_t i = 0; i < m_size; ++i) {
                m_words[i] = other.m_words[i]; 
            }
        }
    }

    // copy Assignment operator
    Dictionary& Dictionary::operator=(const Dictionary& other) {
        // Check for self-assignment
        if (this != &other) {

            //delete previously allocated memory
            delete[] m_words;

            // Initialize properties
            m_size = other.m_size;
            m_words = nullptr;

            // Allocate new memory and copy words 
            if (other.m_words) {
                m_words = new Word[m_size];
                for (size_t i = 0; i < m_size; ++i) {
                    m_words[i].m_word = other.m_words[i].m_word;
                    m_words[i].m_definition = other.m_words[i].m_definition;
                    m_words[i].m_pos = other.m_words[i].m_pos;
                }
            }
        }
        return *this;
    }

    // Move constructor 
    Dictionary::Dictionary(Dictionary&& other) noexcept {
        
        //set m_size and m_words to arguments object
        m_size = other.m_size;
        m_words = other.m_words;

        //set preprties to default values
        other.m_size = 0;
        other.m_words = nullptr;
    }

    // Move assignment operator 
    Dictionary& Dictionary::operator=(Dictionary&& other) noexcept {
        
        // Check for self-assignment
        if (this != &other) {

            //delete previously allocated memory
            delete[] m_words;

            //set to new location
            m_words = other.m_words;
            m_size = other.m_size;

            //set previous allocated elements to null
            other.m_words = nullptr;
            other.m_size = 0;
        }

        return *this;
    }

    // Load dictionary words from a file
    void Dictionary::loadFromFile(const char* filename)
    {
        //read file
        std::ifstream file(filename);
        if (!file.is_open()) {
            return;
        }

        Word* words = nullptr;
        size_t capacity = 0;
        size_t size = 0;

        std::string line;

        //read line
        while (std::getline(file, line)) {

            //if size>=capacity
            if (size >= capacity) {

                if (capacity == 0) {
                    capacity = 1; 
                }
                else {
                    capacity *= 2; 
                }

                // Allocate new storage
                Word* newWords = new Word[capacity];
                if (words) {

                    // Copy existing words
                    std::copy(words, words + size, newWords);

                    // Free old storage
                    delete[] words;
                }

                // Point to new storage
                words = newWords;
            }
            std::istringstream iss(line);
            std::string word, pos, definition;

            if (std::getline(iss, word, ',') && std::getline(iss, pos, ',') && std::getline(iss, definition)) {
                words[size++] = { word, definition, parsePartOfSpeech(pos) };
            }
        }

        m_words = words;
        m_size = size;
    }

    // Parse part of speech from a string
    PartOfSpeech Dictionary::parsePartOfSpeech(const std::string& pos)
    {
        // Determine the part of speech
        if (pos == "n." || pos == "n. pl.") {
            return PartOfSpeech::Noun;
        }
        if (pos == "adv.") {
            return PartOfSpeech::Adverb;
        }
        if (pos == "a.") {
            return PartOfSpeech::Adjective;
        }
        if (pos.find("v.") == 0) {
            return PartOfSpeech::Verb;
        }
        if (pos == "prep.") {
            return PartOfSpeech::Preposition;
        }
        if (pos == "pron.") {
            return PartOfSpeech::Pronoun;
        }
        if (pos == "conj.") {
            return PartOfSpeech::Conjunction;
        }
        if (pos == "interj.") {
            return PartOfSpeech::Interjection;
        }
        return PartOfSpeech::Unknown;
    }

    // Constructor to load dictionary from file
    Dictionary::Dictionary(const char* filename)
    {
        loadFromFile(filename);
    }

    //destructor
    Dictionary::~Dictionary()
    {
        delete[] m_words;
    }

    // Search for a word in the dictionary and prin
    void Dictionary::searchWord(const char* word)
    {
        static const char* pso[] = {
        "unknown",     // PartOfSpeech::Unknown
        "noun",        // PartOfSpeech::Noun
        "pronoun",     // PartOfSpeech::Pronoun
        "adjective",   // PartOfSpeech::Adjective
        "adverb",      // PartOfSpeech::Adverb
        "verb",        // PartOfSpeech::Verb
        "preposition", // PartOfSpeech::Preposition
        "conjunction", // PartOfSpeech::Conjunction
        "interjection" // PartOfSpeech::Interjection
        };
       

        //set ti false
        bool found = false;

        for (size_t i = 0; i < m_size; ++i) {

            if (std::strcmp(m_words[i].m_word.c_str(), word) == 0) {
                if (!found) {
                    std::cout << m_words[i].m_word;
                }
                else {
                    std::cout << std::setw(std::strlen(word)) << " ";
                }

                std::cout << " - ";

                if (seneca::g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown) {
                    std::cout << "(" << pso[static_cast<int>(m_words[i].m_pos)] << ") ";
                }

                std::cout << m_words[i].m_definition << std::endl;
                found = true;

                if (!seneca::g_settings.m_show_all) {
                    break;
                }
            }
        }

        if (!found) {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }


    }


}
