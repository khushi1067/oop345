#pragma once
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
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
        Interjection,
    };

    struct Word {
        std::string m_word{};
        std::string m_definition{};
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    class Dictionary {
        Word* m_words{ nullptr };
        size_t m_size{ 0 };
        size_t m_capacity{ 0 };

        void resize();

    public:

        //default constructor
        Dictionary();

        //constructor to load dictionary file
        Dictionary(const char* filename);

        //destructor
        ~Dictionary();

        //method to search word 
        void searchWord(const char* word);
    };
}

#endif // DICTIONARY_H

//namespace seneca {
//	enum class PartOfSpeech
//	{
//		Unknown,
//		Noun,
//		Pronoun,
//		Adjective,
//		Adverb,
//		Verb,
//		Preposition,
//		Conjunction,
//		Interjection,
//	};
//	struct Word {
//		std::string m_word;
//		std::string m_definition;
//		PartOfSpeech m_pos = PartOfSpeech::Unknown;
//	};
//
//	class Dictionary {
//		std::vector<Word> m_words;
//		Word* words{}; //
//
//	public:
//		PartOfSpeech parsePOS(const std::string& pos);
//		Dictionary() = default;
//		Dictionary(const char* filename);
//		void searchWord(const char* word);
//	};
//
//}
//#endif // !DICTIONARY_H