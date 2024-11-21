#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <string>
#include <vector>
#include "mediaItem.h"

namespace seneca
{


	//module to manage a collection of all media items
	
	class Collection {
		//name
		std::string m_name;
		std::vector<MediaItem*> m_items;

		//observes event 
		void (*m_observer)(const Collection&, const MediaItem&);

	public:

		//sets name of collection to sting 
		Collection(const std::string& name);

		//copy constructor prevent copy
		Collection(const Collection& other) = delete;

		//copy assignment 
		Collection& operator=(const Collection& other) = delete;
		
		//move constructore ptrvent move
		Collection(Collection&& other) noexcept = delete;

		//move assignment operator
		Collection& operator=(Collection&& other) noexcept = delete;

		//destructor
		~Collection();

		// Returns the name of the collection 
		const std::string& name() const;

		// Returns the size of the collection 
		size_t size() const;

		void setObserver(void (*observer)(const Collection&, const MediaItem&));


		// operator overload to add item
		Collection& operator+=(MediaItem* item);

		//get media item from collection by index
		MediaItem* operator[](size_t idx) const;

		//get media item from collection by title
		MediaItem* operator[](const std::string& title) const;

		// Removes quotes
		void removeQuotes();

		// Sorts the collection
		void sort(const std::string& field);
	};

	std::ostream& operator<<(std::ostream& os, const Collection& collection);

}

#endif