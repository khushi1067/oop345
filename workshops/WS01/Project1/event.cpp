#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include "settings.h"
#include<chrono>
#include<iomanip>
#include<string>

namespace seneca {

    // Enum for time units
    enum class TimeUnits {
        Seconds,
        Milliseconds,
        Microseconds,
        Default
    };

    // Function to map time unit strings to the enum
    TimeUnits getTimeUnit(const std::string& time_unit) {
        if (time_unit == "seconds") return TimeUnits::Seconds;
        else if (time_unit == "milliseconds") return TimeUnits::Milliseconds;
        else if (time_unit == "microseconds") return TimeUnits::Microseconds;
        else return TimeUnits::Default;
    }

    // Constructor to initialize Event
    seneca::Event::Event(const char* name, const std::chrono::nanoseconds& duration) {
        m_name = name;
        m_duration = duration;
    }

    // Overloaded operator<< to output event details
    std::ostream& operator<<(std::ostream& os, const Event& event) {
        static int counter = 0;
        counter++;

        long long duration_value;
        int field_size;

        // Get the time unit enum based on the g_settings.m_time_units string
        TimeUnits unit = getTimeUnit(g_settings.m_time_units);

        // Use switch-case to handle the different time units
        switch (unit) {
        case TimeUnits::Seconds:
            duration_value = std::chrono::duration_cast<std::chrono::seconds>(event.m_duration).count();
            field_size = 2;
            break;
        case TimeUnits::Milliseconds:
            duration_value = std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration).count();
            field_size = 5;
            break;
        case TimeUnits::Microseconds:
            duration_value = std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration).count();
            field_size = 8;
            break;
        default:
            duration_value = event.m_duration.count();
            field_size = 11;
            break;
        }

        // Print COUNTER : EVENT_NAME -> DURATION TIME_UNITS
        os << std::right << std::setw(2) << counter << ": "
            << std::right << std::setw(40) << event.m_name << " -> "
            << std::right << std::setw(field_size) << duration_value << " "
            << g_settings.m_time_units << "\n";

        return os;
    }

}
