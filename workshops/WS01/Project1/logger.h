#pragma once
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H
#include<iostream>
#include "event.h"
namespace seneca {
	class Logger {
		Event* m_events=nullptr;
		size_t m_size = 0;
		size_t m_capacity = 0;

		//helper function to resize array
		//void resize();
		
	public:
		//constructor
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

		//move assignment operator
		//Logger(const Logger&) = delete;


		
		friend std::ostream& operator<<(std::ostream& os, const Logger& logger);
		




	};
}
#endif

// Logger & Logger::operator=(Logger&&) noexcept;

//copy the event receivd as parameter

//Logger(const Logger&) = delete; // Disable copy constructor


		//Logger(Logger&&) noexcept;
		//Logger& operator=(Logger&&) noexcept;
//#ifndef SENECA_LOGGER_H
//#define SENECA_LOGGER_H
//
//#include "event.h"
//
//namespace seneca {
//    //manage dynamically allocated collection of events
//
//    class Logger {
//        
//        Event* m_events;
//        size_t m_size;
//        size_t m_capacity;
//
//        void resize();
//
//    public:
//
//        //default constructor
//        Logger();
//        //destructor
//        ~Logger();
//
//        Logger(Logger&& other);
//        Logger& operator=(Logger&& other);
//
//        //add to array a copy
//        void addEvent(const Event& event);
//
//        //friend operator
//        friend std::ostream& operator<<(std::ostream& os, const Logger& logger);
//    };
//}
//
//#endif // LOGGER_H
//
//
//
////#ifndef SENECA_LOGGER_H
////#define SENECA_LOGGER_H
////
////#include "event.h"
////
////namespace seneca {
////    class Logger {
////        //array of events
////        Event* m_events{ nullptr };
////        size_t m_size{ 0 };
////        size_t m_capacity{ 0 };
////
////    public:
////        //constructor
////        Logger();
////
////        //destructor
////        ~Logger();
////
////        //copy constructor disable copy
////        Logger(const Logger&) = delete;
////        Logger& operator=(const Logger&) = delete; 
////
////        //move constructor
////        Logger(Logger&&) noexcept;                 
////
////        //move assignmant
////        Logger& operator=(Logger&&) noexcept;      
////
////        void addEvent(const Event& event);
////
////        friend std::ostream& operator<<(std::ostream& os, const Logger& logger);
////    };
////}
////#endif
