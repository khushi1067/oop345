#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include "Settings.h"

#include <string>
#include <chrono>
#include <iostream>

namespace seneca {
    //stores info about a single event during program execution
    class Event {


        //stores name of event
        std::string m_name;
        //stores duration of event in nanoseconds
        std::chrono::nanoseconds m_duration;
    
    public:
    
        //default constructor
        Event()=default;

        //parameterized constructor
        Event(const char* name, const std::chrono::nanoseconds& duration) {};
        /*Event(const char* name, const std::chrono::nanoseconds& duration)
            : m_name(name), m_duration(duration) {}*/
        // Event(const char* name, const std::chrono::nanoseconds& duration);

        //friend function operator overload <<
        friend std::ostream& operator<<(std::ostream& os, const Event& event);
    };
}

#endif // EVENT_H


//#ifndef SENECA_EVENT_H
//#define SENECA_EVENT_H
//
//#include "settings.h"
//
//#include<iostream>
//#include <string>
//#include <chrono>
//
//using namespace std;
//
//namespace seneca {
//	class Event {
//		std::string m_name;
//		std::chrono::nanoseconds m_duration;
//
//	public:
//		Event() = default;
//		Event(const char* name,const std::chrono::nanoseconds& duration)
//			:m_name(name),m_duration(duration){}
//
//		friend std::ostream& operator<<(std::ostream& os, const Event& event);
//
//
//	};
//}
//
//
//#endif // !EVENT_H
