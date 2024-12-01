#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <iostream>
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace seneca {

	//hold oreder at assembly line at first station
	extern std::deque<seneca::CustomerOrder> g_pending;

	//hold order that have removed from last station and are completely filled
	extern std::deque<seneca::CustomerOrder> g_completed;

	//removed and are incomplete
	extern std::deque<seneca::CustomerOrder> g_incomplete;

	class Workstation : public Station {

		//already received orders
		std::deque<CustomerOrder> m_orders;

		//ptr to next workstation assembly
		Workstation* m_pNextStation = nullptr;
	
	public:
	
		// arg constructor receives str 
		Workstation(const std::string& str) : Station(str) {}

		//fills order 
		void fill(std::ostream& os);
		
		//move order
		bool attemptToMoveOrder();
		
		//store address reference
		void setNextStation(Workstation* station);
		
		//returns address of next station
		Workstation* getNextStation() const;
		
		
		Workstation(Workstation&&) = delete;
		
		//display
		void display(std::ostream& os) const;
	
		//operator overload
		Workstation& operator+=(CustomerOrder&& newOrder);
		Workstation& operator=(Workstation&&) = delete;
	};

} // namespace seneca

#endif // !SENECA_WORKSTATION_H