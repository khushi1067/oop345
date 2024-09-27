#include "timeMonitor.h"

namespace seneca {

    // start tracking time of event 
    void TimeMonitor::startEvent(const char* name) {
        //to store name of event
        m_event_name = name;

        //store start time set start time as current time (now())
        m_start = std::chrono::steady_clock::now();
    }

    //stop event function
    Event TimeMonitor::stopEvent() {

        //record end time as current time
        auto end = std::chrono::steady_clock::now();

        //calcutalte duration in nanoseconds
        std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start);
        
        //return event name and duration
        return Event(m_event_name, duration);
    }
}
