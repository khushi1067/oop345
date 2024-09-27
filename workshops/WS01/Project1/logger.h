#pragma once
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include<iostream>
#include "event.h"
namespace seneca {
	//class that manages dynamically allocated collection of events

	class Logger {

		Event* m_events=nullptr;
		size_t m_size = 0;
		size_t m_capacity = 0;
		
	public:
		//default constructor
		Logger();

		//destructor
		~Logger();

		//move constructor
		Logger(Logger&& other) noexcept;

		//move assignment operator		
		Logger& operator=(Logger&& other) noexcept;

		//disable copy assignment operator
		Logger& operator=(const Logger&) = delete;

		//method to add event
		void addEvent(const Event& event);

		//operator overload <<
		friend std::ostream& operator<<(std::ostream& os, const Logger& logger);
		




	};
}
#endif
