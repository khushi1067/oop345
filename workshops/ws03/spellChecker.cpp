#include <iostream>
#include <fstream>
#include <iomanip>
#include "book.h"
#include "collection.h"
#include "mediaItem.h"
#include "movie.h"
#include "settings.h"
#include "spellChecker.h"
#include "tvShow.h"

using namespace std;

namespace seneca
{

	//Constructor that initializes the spell checker
	SpellChecker::SpellChecker(const char* filename) {

		// // Initialize the misCount array to zero
		for (size_t i = 0; i < 6; i++) {
			m_misCount[i] = 0;
		}

		// Open the file containing bad and good word pairs
		std::ifstream file(filename);

		// if the file cannot open throw error
		if (!file) {
			throw std::runtime_error("Could not open file: " + std::string(filename));
		}

		size_t i = 0;
		std::string line;

		// Read the bad and good words
		while (std::getline(file, line)) {

			//if lenghth(words)>6 or empty stop reading
			if (i >= 6 || line.empty()) {
				//stop reading break
				break;
			}

			// Format: "BAD_WORD GOOD_WORD"
			std::stringstream ss(line);
			ss >> m_badWords[i] >> m_goodWords[i];
			i++;
		}
	}

	// Operator() overload
	void SpellChecker::operator()(std::string& text) {

		// Loop through all bad word pairs
		for (size_t i = 0; i < 6; i++) {
			std::string::size_type pos = 0;

			// Find and replace allbad words with good words
			while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
				//replace bad wiht good words
				text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
				pos += m_goodWords[i].length();

				// Increment the count of replacements
				m_misCount[i]++;
			}
		}
	}


	// Displays the spell-check statistics 
	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics\n";

		// replace bad word 
		for (size_t i = 0; i < 6; i++) {

			//add replacement at bad words
			out << std::left << std::setw(15) << m_badWords[i] << ": " << m_misCount[i]
				<< " replacements\n";
		}
	}



}