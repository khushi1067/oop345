#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>
#include "mediaItem.h"

namespace seneca
{
	class Book : public MediaItem
	{
		std::string m_author{};
		std::string m_country{};
		
		double m_price{};

		//default constructore
		Book();
		
		//initialied constructor
		Book(const std::string& title, const std::string& summary, unsigned short year,
			const std::string& author, const std::string& country, double price)
			: MediaItem(title, summary, year), m_author(author), m_country(country), m_price(price) {}

	public:

		//display function
		void display(std::ostream& out) const override;
		
		static Book* createItem(const std::string& strBook);

	};



}

#endif