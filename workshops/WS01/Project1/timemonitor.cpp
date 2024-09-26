#include "timeMonitor.h"

namespace seneca {
    void TimeMonitor::startEvent(const char* name) {
        m_event_name = name;
        m_start = std::chrono::steady_clock::now();
    }

    Event TimeMonitor::stopEvent() {
        auto end = std::chrono::steady_clock::now();
        std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start);
        return Event(m_event_name, duration);
    }
}
