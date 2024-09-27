#include "logger.h"
#include "event.h"
#include <utility>

namespace seneca {

	//default constructor
	Logger::Logger() {

		//set to null 
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
		//move operation
		*this = std::move(other);

	}

	Logger& Logger::operator=(Logger&& other) noexcept {
		
		//check for self allocation
		if (this != &other) {

			//clean exixting memory
			delete[] m_events;

			//move 
			m_events = other.m_events;
			m_size = other.m_size;
			m_capacity = other.m_capacity;

			//set previously allocated memory to null
			other.m_events = nullptr;
			other.m_size = 0;
			other.m_capacity = 0;
		}
		//return *this
		return *this;
	}

	//add to array copy of event received as parameter
	void Logger::addEvent(const Event& event)
	{
		//of size is >= capacity
		if (m_size >= m_capacity) {

			size_t new_capacity;

			//if capacity ==0
			if (m_capacity == 0) {
				//set capacity to 1
				new_capacity = 1;
			}
			else {
				//set capacity to double of m_capacity
				new_capacity = m_capacity * 2;
			}

			//allocate new memory
			Event* new_events = new Event[new_capacity];

			for (size_t i = 0; i < m_size; ++i) {
				//move operation
				new_events[i] = std::move(m_events[i]);
			}

			//delete prevously allocated memory
			delete[] m_events;

			//set m_events and m_capacity to newly allocated memory
			m_events = new_events;
			m_capacity = new_capacity;
		}
		m_events[m_size++] = event;
	}

	std::ostream& operator<<(std::ostream& os, const Logger& logger) {
		for (size_t i = 0; i < logger.m_size; ++i)
		{
			//print event
			os << logger.m_events[i];


		}
		return os;
	}
}

