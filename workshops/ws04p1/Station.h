#ifndef SENECA_STATION_H
#define SENECA_STATION_H

/*
	Name: Khushi Abhay Bhandari
	Email-kabhandari@myseneca.ca
	Student ID: 106774235
	Date: 01/12/2024
*/
#include <string>

namespace seneca {

	//mange station on assembly line
	//hold item, fill customer order


	class Station {

		//store station id
		size_t m_id{};

		//name
		std::string m_name{ "" };
		
		//description station
		std::string m_desc{ "" };

		//serial number assigneed to item at station
		size_t m_serialNumber{};

		//stock uqnatity
		size_t m_qtyInStock{};

		//print screen item
		static size_t m_widthField;

		//generat id
		static size_t id_generator;
	public:

		//default constructor
		Station() = default;

		//constructor with str argu
		Station(const std::string& str);


		size_t getId() const;
		
		//return name of current station
		const std::string& getItemName() const;

		//returns serial number 
		size_t getNextSerialNumber();

		//returns remaining quantity
		size_t getQuantity() const;

		//subtract 1 from available quantity min=0
		void updateQuantity();

		//display function
		void display(std::ostream& os, bool full) const;
	};

} // namespace seneca

#endif // !SENECA_STATION_H