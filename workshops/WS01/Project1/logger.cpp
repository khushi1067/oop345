#include "logger.h"
#include "event.h"
#include <utility>

namespace seneca {

	//default constructor
	Logger::Logger() {
		m_events = nullptr;
		m_capacity = 0;
		m_size = 0;
	}

	//destructor
	Logger::~Logger() {
		//clean allocated memory
		delete[] m_events;
	}

	Logger::Logger(Logger&& other) noexcept
	{
		*this = std::move(other);

	}

	Logger& Logger::operator=(Logger&& other) noexcept {
		if (this != &other) {

			//clean exixting memory
			delete[] m_events;

			m_events = other.m_events;
			m_size = other.m_size;
			m_capacity = other.m_capacity;

			other.m_events = nullptr;
			other.m_size = 0;
			other.m_capacity = 0;
		}
		return *this;
	}

	void Logger::addEvent(const Event& event)
	{
		if (m_size >= m_capacity) {
			size_t new_capacity = m_capacity ? m_capacity * 2 : 1;

			Event* new_events = new Event[new_capacity];

			for (size_t i = 0; i < m_size; ++i) {
				new_events[i] = std::move(m_events[i]);
			}
			delete[] m_events;
			m_events = new_events;
			m_capacity = new_capacity;
		}
		m_events[m_size++] = event;
	}

	std::ostream& operator<<(std::ostream& os, const Logger& logger) {
		for (size_t i = 0; i < logger.m_size; ++i)
		{
			os << logger.m_events[i];


		}
		return os;
	}
}



	//void Logger::resize() {
	//	//if(capacity)=0 set to 1 else double
	//	if (m_capacity == 0) {
	//		m_capacity = 1;
	//	}
	//	else
	//	{
	//		m_capacity = m_capacity * 2;
	//	}

	//	//allocate new array 
	//	Event* newEvents = new Event[m_capacity];

	//	//copy
	//	for (size_t i = 0; i < m_size; ++i) {
	//		newEvents[i] = m_events[i];
	//	}
	//	//delete previously allocated memory
	//	delete[] m_events;

	//	m_events = newEvents;
	//}











//	seneca::Logger::Logger() :
//		m_events(nullptr), m_size(0), m_capacity(0) {}
//
//	//destructor
//	Logger::~Logger()
//	{
//		//clean memory
//		delete[] m_events;
//	}
//
//	void Logger::resize() {
//		//if capacity 0 set to 1 or double the capacity
//		m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
//		
//
//		//allocate memory
//		Event* newEvents = new Event[m_capacity];
//
//		//copy existing events to new array
//		for (size_t i = 0; i < m_size; ++i) {
//			newEvents[i] = m_events[i]; // Copy each event
//		}
//
//		//free prevoiusly allocated memory
//		delete[] m_events;
//
//		//reassign pointer to new array
//		m_events = newEvents;
//	}
//
//	Logger::Logger(Logger&& other) :m_events(other.m_events), m_capacity(other.m_capacity), m_size(other.m_size) {
//		//set the arguments events to nullptr
//		other.m_events = nullptr;
//
//		//reset capacity to 
//		other.m_capacity = 0;
//
//		//reset sie to 0
//		other.m_size = 0;
//	
//	}
//	//move assignment operator
//	
//	Logger& Logger::operator=(Logger&& other) {
//		//check of exist
//		if (this != &other) {
//			//clean previously allocated memory
//			delete[] m_events;
//
//			//move
//			m_events = other.m_events;
//
//			//transfer capacity
//			m_capacity = other.m_capacity;
//
//			//transfer size
//			m_size = other.m_size;
//
//			//reset other resourses
//			other.m_events = nullptr;
//			other.m_capacity = 0;
//			other.m_size = 0;
//		}
//		//return instance
//		return *this;
//	}
//
//
//
//
//
//
//
//	////move operation
//	//Logger& Logger::operator=(Logger&& src) 
//	//{
//	//	if (this != &src) {
//	//		delete[] m_events; // Clean up the existing resources
//	//		m_events = src.m_events; // Transfer ownership
//	//		m_size = src.m_size;
//	//		m_capacity = src.m_capacity; // Also transfer the capacity
//
//	//		src.m_events = nullptr; // Reset the source's pointer to avoid double deletion
//	//		src.m_size = 0; // Reset the size
//	//		src.m_capacity = 0; // Reset the capacity
//	//	}
//	//	return *this;
//	//}
//
//	Logger::Logger(Logger&& src) 
//	{
//		*this = std::move(src);
//	}
//
//
//	void Logger::resize() {
//
//		size_t new_capacity = (m_capacity == 0) ? 1 : (m_capacity * 2);
//		
//		//dynamically allocate memory
//		Event* new_events = new Event[new_capacity]; 
//
//		for (size_t i = 0; i < m_size; ++i) {
//			//move 
//			new_events[i] = std::move(m_events[i]); 
//		}
//
//		//delete previously allocated memory 
//		delete[] m_events; 
//		//move to new location
//		m_events = new_events; 
//
//		//update mew_capacity
//		m_capacity = new_capacity; // Update capacity
//	}
//
//	//add array a copy of event received as parameter
//	void Logger::addEvent(const Event& event) {
//		if (m_size >= m_capacity) {
//			resize();
//		}
//		m_events[m_size++] = event;
//	}
//
//
//	std::ostream& operator<<(std::ostream& os, const Logger& logger)
//	{
//		for (size_t i = 0; i < logger.m_size; ++i) {
//            os << logger.m_events[i] << std::endl;
//
////			os << logger.m_events[i];/////
//		}
//		return os;
//	}
//}
//


//
//namespace seneca {
//    Logger::Logger() : m_events{ nullptr }, m_size{ 0 }, m_capacity{ 1 } {
//        m_events = new Event[m_capacity];
//    }
//
//    Logger::~Logger() {
//        delete[] m_events;
//    }
//
//    Logger::Logger(Logger&& other) noexcept
//        : m_events{ other.m_events }, m_size{ other.m_size }, m_capacity{ other.m_capacity } {
//        other.m_events = nullptr;
//        other.m_size = 0;
//        other.m_capacity = 0;
//    }
//
//    Logger& Logger::operator=(Logger&& other) noexcept {
//        if (this != &other) {
//            delete[] m_events;
//            m_events = other.m_events;
//            m_size = other.m_size;
//            m_capacity = other.m_capacity;
//
//            other.m_events = nullptr;
//            other.m_size = 0;
//            other.m_capacity = 0;
//        }
//        return *this;
//    }
//
//    void Logger::resize() {
//        m_capacity *= 2;
//        Event* new_events = new Event[m_capacity];
//        for (size_t i = 0; i < m_size; ++i) {
//            new_events[i] = std::move(m_events[i]);
//        }
//        delete[] m_events;
//        m_events = new_events;
//    }
//
//    void Logger::addEvent(const Event& event) {
//        if (m_size >= m_capacity) {
//            resize();
//        }
//        m_events[m_size++] = event;
//    }
//
//    std::ostream& operator<<(std::ostream& os, const Logger& logger) {
//        for (size_t i = 0; i < logger.m_size; ++i) {
//            os << logger.m_events[i] << std::endl;
//        }
//        return os;
//    }
//}

//#include "logger.h"
//#include <iostream>
//
//namespace seneca {
//    Logger::Logger() : m_events(nullptr), m_size(0), m_capacity(0) {}
//
//    Logger::~Logger() {
//        delete[] m_events;
//    }
//
//    //move constructor
//    Logger::Logger(Logger&& other) noexcept {
//        *this = std::move(other);
//    }
//
//    Logger& Logger::operator=(Logger&& other) noexcept {
//        
//        //check for self assignment
//        if (this != &other) 
//        {
//            //delete previously allocated memory
//            delete[] m_events;
//            //set it to nullptr
//            m_events = nullptr;
//
//            //shallow copy
//            m_events = other.m_events;
//            m_size = other.m_size;
//            m_capacity = other.m_capacity;
//
//            //make previous location to nullptr
//            other.m_events = nullptr;
//            other.m_size = 0;
//            other.m_capacity = 0;
//        }
//        //return same obj
//        return *this;
//    }
//
//    void Logger::addEvent(const Event& event) {
//        if (m_size == m_capacity) {
//            size_t new_capacity = m_capacity ? m_capacity * 2 : 1;
//            Event* temp = new Event[new_capacity];
//            for (size_t i = 0; i < m_size; ++i) {
//                temp[i] = m_events[i];
//            }
//            delete[] m_events;
//            m_events = temp;
//            m_capacity = new_capacity;
//        }
//        m_events[m_size++] = event;
//    }
//
//    std::ostream& operator<<(std::ostream& os, const Logger& logger) {
//        for (size_t i = 0; i < logger.m_size; ++i) {
//            os << logger.m_events[i];
//        }
//        return os;
//    }
//}
