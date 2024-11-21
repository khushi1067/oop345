#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>
#include <string>
#include "book.h"
#include "collection.h"
#include "mediaItem.h"
#include "movie.h"
#include "settings.h"
#include "spellChecker.h"
#include "tvShow.h"


//module to hold parallel array 
namespace seneca {
	class SpellChecker {

		//hold misspelled word max-6
		std::string m_badWords[6];
		//hold good wors max-6
		std::string m_goodWords[6];


		size_t m_misCount[6];

	public:

		//hold names of files contain misspleed words
		SpellChecker(const char* filename);

		//overload operator
		void operator()(std::string& text);

		//shoe no misspelled 
		void showStatistics(std::ostream& out) const;
	};
}

#endif