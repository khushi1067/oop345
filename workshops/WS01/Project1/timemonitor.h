#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include "event.h"
#include "logger.h"
#include <chrono>
#include <functional>




namespace seneca {
    class TimeMonitor {
        const char* m_event_name;
        std::chrono::steady_clock::time_point m_start;

    public:
        void startEvent(const char* name);
        Event stopEvent();
    };
}

#endif // TIMEMONITOR_H






        //class TimeMonitor {
        //    Logger m_logger;

        //public:
        //    TimeMonitor() = default;

        //    template<typename Func>
        //    auto monitor(const char* event_name, Func func) -> decltype(func()) {
        //        using namespace std::chrono;

        //        auto start_time = high_resolution_clock::now();
        //        auto result = func(); // Execute the function being monitored
        //        auto end_time = high_resolution_clock::now();

        //        auto duration = duration_cast<nanoseconds>(end_time - start_time);
        //        m_logger.addEvent(Event(event_name, duration));

        //        return result; // Return the result of the monitored function
        //    }

        //    const Logger& logger() const {
        //        return m_logger;
        //    }
        //};

 // TIMEMONITOR_H
