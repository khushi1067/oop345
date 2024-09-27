#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include "event.h"
#include "logger.h"
#include <chrono>
#include <functional>




namespace seneca {

    //measuring duration of events
    class TimeMonitor {

        // stores name of event
        const char* m_event_name;

        //steady_clock to set start time of event
        std::chrono::steady_clock::time_point m_start;

    public:

        //start event function
        void startEvent(const char* name);
        
        //stop event function
        Event stopEvent();
    };
}

#endif // TIMEMONITOR_H

