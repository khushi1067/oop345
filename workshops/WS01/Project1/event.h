#pragma 

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include<chrono>
#include<string>
#include<iomanip>
#include<iostream>

namespace seneca {

	//class event
	class Event {
		//store name of event as string
		std::string m_name;

		//store duration
		std::chrono::nanoseconds m_duration;


	public:
		//default constructor
		Event() = default;

		Event(const char* name, const std::chrono::nanoseconds& duration);

		//helper function operator overload <<
		friend std::ostream& operator<<(std::ostream& os, const Event& event);
	};
}


#endif
