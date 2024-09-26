#include "event.h"
#include "settings.h"

namespace seneca {

    //default constructor
    seneca::Event::Event(const char* name, const std::chrono::nanoseconds& duration)
    {
        //initialize instance with parameters
        m_name = name;
        m_duration = duration;
    }


    //operator overload <<
    std::ostream& operator<<(std::ostream& os, const Event& event) {
        //static counter
        static int counter = 0;
        ++counter;

        //print   COUNTER: EVENT_NAME -> DURATION TIME_UNITS

        //print counter
        os.width(2);
        os << counter << ": ";

        //print event name
        os.width(40);
        os << event.m_name << " -> ";


        os.width(11); // default to nanoseconds size
        if (g_settings.m_time_units == "seconds") {
            os.width(2);
        }
        else if (g_settings.m_time_units == "milliseconds") {
            os.width(5);
        }
        else if (g_settings.m_time_units == "microseconds") {
            os.width(8);
        }

        os << event.m_duration.count() << " " << g_settings.m_time_units;
        return os;
    }
}

//#include "event.h"
//#include "settings.h"
//
//#include <iostream>
//#include <string>
//#include <iomanip>
//
//namespace seneca {
//    std::ostream& operator<<(std::ostream& os, const Event& event) {
//        static int counter = 0;
//        counter++;
//
//        //use duration cast and .count()
//        
//        // Determine the correct time unit field size and value
//        long long duration_value;
//        int field_size;
//        if (g_settings.m_time_units == "seconds") {
//            duration_value = std::chrono::duration_cast<std::chrono::seconds>(event.m_duration).count();
//            field_size = 2;
//        }
//        else if (g_settings.m_time_units == "milliseconds") {
//            duration_value = std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration).count();
//            field_size = 5;
//        }
//        else if (g_settings.m_time_units == "microseconds") {
//            duration_value = std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration).count();
//            field_size = 8;
//        }
//        else { // nanoseconds by default
//            duration_value = event.m_duration.count();
//            field_size = 11;
//        }
//
//        // Output the event in the required format
//        os << std::right << std::setw(2) << counter << ": "
//            << std::right << std::setw(40) << event.m_name << " -> "
//            << std::right << std::setw(field_size) << duration_value << " "
//            << g_settings.m_time_units << "\n";
//
//        return os;
//    }
//}





