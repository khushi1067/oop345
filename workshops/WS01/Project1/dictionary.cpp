#define _CRT_SECURE_NO_WARNINGS

#include "dictionary.h"
#include "settings.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

namespace seneca {
    Dictionary::Dictionary() : m_words{ nullptr }, m_size{ 0 }, m_capacity{ 0 } {}

    Dictionary::Dictionary(const char* filename) : Dictionary() {
        std::ifstream file(filename);
        if (!file) {
            return; // empty state
        }

        std::string line;
        while (getline(file, line)) {
            if (m_size >= m_capacity) {
                resize();
            }

            // Parse word, pos, definition
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            m_words[m_size].m_word = line.substr(0, pos1);
            std::string pos = line.substr(pos1 + 1, pos2 - pos1 - 1);
            m_words[m_size].m_definition = line.substr(pos2 + 1);

            // Identify the part of speech
            if (pos == "n." || pos == "n. pl.") {
                m_words[m_size].m_pos = PartOfSpeech::Noun;
            }
            else if (pos == "adv.") {
                m_words[m_size].m_pos = PartOfSpeech::Adverb;
            }
            else if (pos == "a.") {
                m_words[m_size].m_pos = PartOfSpeech::Adjective;
            }
            else if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") {
                m_words[m_size].m_pos = PartOfSpeech::Verb;
            }
            else if (pos == "prep.") {
                m_words[m_size].m_pos = PartOfSpeech::Preposition;
            }
            else if (pos == "pron.") {
                m_words[m_size].m_pos = PartOfSpeech::Pronoun;
            }
            else if (pos == "conj.") {
                m_words[m_size].m_pos = PartOfSpeech::Conjunction;
            }
            else if (pos == "interj.") {
                m_words[m_size].m_pos = PartOfSpeech::Interjection;
            }
            else {
                m_words[m_size].m_pos = PartOfSpeech::Unknown;
            }
            ++m_size;
        }
    }

    Dictionary::~Dictionary() {
        delete[] m_words;
    }

    void Dictionary::resize() {
        m_capacity = m_capacity ? m_capacity * 2 : 1;
        Word* new_words = new Word[m_capacity];

        for (size_t i = 0; i < m_size; ++i) {
            new_words[i] = std::move(m_words[i]);
        }
        delete[] m_words;
        m_words = new_words;
    }

    void Dictionary::searchWord(const char* word) {
        bool found = false;
        for (size_t i = 0; i < m_size; ++i) {
            if (m_words[i].m_word == word) {
                found = true;
                if (Settings::m_show_all) {
                    // Print all definitions
                    printWordDefinition(i);

                    // Check for additional definitions
                    for (size_t j = i + 1; j < m_size; ++j) {
                        if (m_words[j].m_word == word) {
                            std::cout << std::string(m_words[i].m_word.length(), ' ') << " - ";
                            if (Settings::m_verbose && m_words[j].m_pos != PartOfSpeech::Unknown) {
                                std::cout << "(" << toString(m_words[j].m_pos) << ") ";
                            }
                            std::cout << m_words[j].m_definition << std::endl;
                        }
                    }
                }
                else {
                    // Print only the first definition
                    printWordDefinition(i);
                }
                break; // Exit loop after finding the word
            }
        }

        if (!found) {
            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
        }
    }

    // Helper function to convert PartOfSpeech enum to string
    std::string Dictionary::toString(PartOfSpeech pos) {
        switch (pos) {
        case PartOfSpeech::Noun: return "Noun";
        case PartOfSpeech::Adverb: return "Adverb";
        case PartOfSpeech::Adjective: return "Adjective";
        case PartOfSpeech::Verb: return "Verb";
        case PartOfSpeech::Preposition: return "Preposition";
        case PartOfSpeech::Pronoun: return "Pronoun";
        case PartOfSpeech::Conjunction: return "Conjunction";
        case PartOfSpeech::Interjection: return "Interjection";
        default: return "Unknown";
        }
    }

    void Dictionary::printWordDefinition(size_t index) {
        std::cout << "Word: " << m_words[index].m_word;
        if (Settings::m_verbose && m_words[index].m_pos != PartOfSpeech::Unknown) {
            std::cout << " - (" << toString(m_words[index].m_pos) << ")";
        }
        std::cout << " " << m_words[index].m_definition << std::endl;
    }
}

//#define _CRT_SECURE_NO_WARNINGS
//
//#include "dictionary.h"
//#include "Settings.h"
//#include "logger.h"
//#include "timemonitor.h"
//#include "event.h"
//
//#include <fstream>
//#include <iostream>
//#include <cstring>
//#include <string>
//
//namespace seneca {
//    Dictionary::Dictionary() : m_words{ nullptr }, m_size{ 0 }, m_capacity{ 0 } {}
//
//    Dictionary::Dictionary(const char* filename) : Dictionary() {
//        std::ifstream file(filename);
//        if (!file) {
//            return; // empty state
//        }
//
//        std::string line;
//        while (getline(file, line)) {
//            if (m_size >= m_capacity) {
//                resize();
//            }
//
//            // Parse word, pos, definition
//            size_t pos1 = line.find(',');
//            size_t pos2 = line.find(',', pos1 + 1);
//
//            m_words[m_size].m_word = line.substr(0, pos1);
//            std::string pos = line.substr(pos1 + 1, pos2 - pos1 - 1);
//            m_words[m_size].m_definition = line.substr(pos2 + 1);
//
//            // Identify the part of speech
//            if (pos == "n." || pos == "n. pl.") {
//                m_words[m_size].m_pos = PartOfSpeech::Noun;
//            }
//            else if (pos == "adv.") {
//                m_words[m_size].m_pos = PartOfSpeech::Adverb;
//            }
//            else if (pos == "a.") {
//                m_words[m_size].m_pos = PartOfSpeech::Adjective;
//            }
//            else if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") {
//                m_words[m_size].m_pos = PartOfSpeech::Verb;
//            }
//            else if (pos == "prep.") {
//                m_words[m_size].m_pos = PartOfSpeech::Preposition;
//            }
//            else if (pos == "pron.") {
//                m_words[m_size].m_pos = PartOfSpeech::Pronoun;
//            }
//            else if (pos == "conj.") {
//                m_words[m_size].m_pos = PartOfSpeech::Conjunction;
//            }
//            else if (pos == "interj.") {
//                m_words[m_size].m_pos = PartOfSpeech::Interjection;
//            }
//            else {
//                m_words[m_size].m_pos = PartOfSpeech::Unknown;
//            }
//            ++m_size;
//        }
//    }
//
//    Dictionary::~Dictionary() {
//        delete[] m_words;
//    }
//
//    void Dictionary::resize() {
//        m_capacity = m_capacity ? m_capacity * 2 : 1;
//        Word* new_words = new Word[m_capacity];
//
//        for (size_t i = 0; i < m_size; ++i) {
//            new_words[i] = std::move(m_words[i]);
//        }
//        delete[] m_words;
//        m_words = new_words;
//    }
//
//    void Dictionary::searchWord(const char* word) {
//        bool found = false;
//        for (size_t i = 0; i < m_size; ++i) {
//            if (m_words[i].m_word == word) {
//                found = true;
//                if (Settings::m_show_all) {
//                    // Print all definitions
//                    std::cout << "Word: " << m_words[i].m_word;
//                    if (Settings::m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown) {
//                        std::cout << " - (" << toString(m_words[i].m_pos) << ")";
//                    }
//                    std::cout << " " << m_words[i].m_definition << std::endl;
//
//                    // Check for additional definitions
//                    for (size_t j = i + 1; j < m_size; ++j) {
//                        if (m_words[j].m_word == word) {
//                            std::cout << std::string(m_words[i].m_word.length(), ' ') << " - ";
//                            if (Settings::m_verbose && m_words[j].m_pos != PartOfSpeech::Unknown) {
//                                std::cout << "(" << toString(m_words[j].m_pos) << ") ";
//                            }
//                            std::cout << m_words[j].m_definition << std::endl;
//                        }
//                    }
//                }
//                else {
//                    // Print only the first definition
//                    std::cout << "Word: " << m_words[i].m_word;
//                    if (Settings::m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown) {
//                        std::cout << " - (" << toString(m_words[i].m_pos) << ")";
//                    }
//                    std::cout << " " << m_words[i].m_definition << std::endl;
//                }
//                break; // Exit loop after finding the word
//            }
//        }
//
//        if (!found) {
//            std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
//        }
//
//        // Helper function to convert PartOfSpeech enum to string
//        std::string toString(PartOfSpeech pos) {
//            switch (pos) {
//            case PartOfSpeech::Noun: return "Noun";
//            case PartOfSpeech::Adverb: return "Adverb";
//            case PartOfSpeech::Adjective: return "Adjective";
//            case PartOfSpeech::Verb: return "Verb";
//            case PartOfSpeech::Preposition: return "Preposition";
//            case PartOfSpeech::Pronoun: return "Pronoun";
//            case PartOfSpeech::Conjunction: return "Conjunction";
//            case PartOfSpeech::Interjection: return "Interjection";
//            default: return "Unknown";
//            }
//        }
//
//        void Dictionary::printWordDefinition(size_t index) {
//            std::cout << "Word: " << m_words[index].m_word;
//            if (Settings::m_verbose && m_words[index].m_pos != PartOfSpeech::Unknown) {
//                std::cout << " - (" << toString(m_words[index].m_pos) << ")";
//            }
//            std::cout << " " << m_words[index].m_definition << std::endl;
//        }
//    }
//}
//
//    //void Dictionary::searchWord(const char* word) {
//    //    bool found = false;
//    //    for (size_t i = 0; i < m_size; ++i) {
//    //        if (m_words[i].m_word == word) {
//    //            found = true; ///////
//    //            if (Settings::m_show_all) {
//
//    //            
//    //            std::cout << "Word: " << m_words[i].m_word << std::endl;
//    //            std::cout << "Definition: " << m_words[i].m_definition << std::endl;
//    //            std::cout << "Part of Speech: ";
//
//    //            switch (m_words[i].m_pos) {
//    //            case PartOfSpeech::Noun:
//    //                std::cout << "Noun";
//    //                break;
//    //            case PartOfSpeech::Adverb:
//    //                std::cout << "Adverb";
//    //                break;
//    //            case PartOfSpeech::Adjective:
//    //                std::cout << "Adjective";
//    //                break;
//    //            case PartOfSpeech::Verb:
//    //                std::cout << "Verb";
//    //                break;
//    //            case PartOfSpeech::Preposition:
//    //                std::cout << "Preposition";
//    //                break;
//    //            case PartOfSpeech::Pronoun:
//    //                std::cout << "Pronoun";
//    //                break;
//    //            case PartOfSpeech::Conjunction:
//    //                std::cout << "Conjunction";
//    //                break;
//    //            case PartOfSpeech::Interjection:
//    //                std::cout << "Interjection";
//    //                break;
//    //            default:
//    //                std::cout << "Unknown";
//    //                break;
//    //            }
//    //            std::cout << std::endl;
//    //            found = true;
//    //            ////////
//    //            
//    //            break;
//    //        }
//    //    }
//
//    //    if (!found) {
//    //        std::cout << "Word not found!" << std::endl;
//    //    }
//    //}
//
//
//
//
////#include "dictionary.h"
////#include <string>
////
////
////namespace seneca {
////
////    PartOfSpeech seneca::Dictionary::parsePOS(const std::string& pos)
////    {
////        if (pos == "n." || pos == "n. pl.") return PartOfSpeech::Noun;
////        if (pos == "adv.") return PartOfSpeech::Adverb;
////        if (pos == "a.") return PartOfSpeech::Adjective;
////        if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") return PartOfSpeech::Verb;
////        if (pos == "prep.") return PartOfSpeech::Preposition;
////        if (pos == "pron.") return PartOfSpeech::Pronoun;
////        if (pos == "conj.") return PartOfSpeech::Conjunction;
////        if (pos == "interj.") return PartOfSpeech::Interjection;
////        return PartOfSpeech::Unknown;
////
////    }
////    Dictionary::Dictionary(const char* filename)
////    {
////        std::ifstream file(filename);
////        if (!file.is_open()) return;
////
////        std::string line;
////        while (std::getline(file, line)) {
////            size_t firstComma = line.find(',');
////            size_t secondComma = line.find(',', firstComma + 1);
////            if (firstComma == std::string::npos || secondComma == std::string::npos) continue;
////
////            Word word;
////            word.m_word = line.substr(0, firstComma);
////            word.m_pos = parsePOS(line.substr(firstComma + 1, secondComma - firstComma - 1));
////            word.m_definition = line.substr(secondComma + 1);
////            m_words.push_back(word);
////        }
////    }
////    void Dictionary::searchWord(const char* word)
////    {
////        for (const auto& w : m_words) {
////            if (w.m_word == word) {
////                std::cout << w.m_word;
////                if (g_settings.m_verbose && w.m_pos != PartOfSpeech::Unknown) {
////                    std::cout << " - (" << static_cast<int>(w.m_pos) << ")";
////                }
////                std::cout << " " << w.m_definition << std::endl;
////                return;
////            }
////        }
////        std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
////    }
////}