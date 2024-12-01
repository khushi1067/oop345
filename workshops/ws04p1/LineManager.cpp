#include "LineManager.h"
#include <sstream>

namespace seneca {

    //read data
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
       //open file
        std::ifstream inputFile(file);
        //if cannot open file throw error
        if (!inputFile) {
            throw std::runtime_error("Error: Unable to open file " + file);
        }

        std::string line;

        // Read the file line by line
        while (std::getline(inputFile, line)) {

            std::istringstream record(line);
            std::string currentStation, nextStation;

            //read data use deliminator
            std::getline(record, currentStation, '|');
            std::getline(record, nextStation);
            
            //find current station in list of stations
            auto currentIt = std::find_if(stations.begin(), stations.end(),
                [&currentStation](Workstation* station) {
                    return station->getItemName() == currentStation;
                });

            //find next station in list of station
            auto nextIt = std::find_if(stations.begin(), stations.end(),
                [&nextStation](Workstation* station) {
                    return station->getItemName() == nextStation;
                });

            //add current station to active line if exist
            if (currentIt != stations.end()) {
                m_activeLine.push_back(*currentIt);

                //id station exist
                if (nextIt != stations.end()) {
                    //set next station
                    (*currentIt)->setNextStation(*nextIt);
                }
            }
        }

        //if first
        m_firstStation = *std::find_if(stations.begin(), stations.end(),
            [&stations](Workstation* station) {
                return std::none_of(stations.begin(), stations.end(),
                [station](Workstation* other) {
                        return other->getNextStation() == station;
                    });
            });

        //set count of customer orders as size ppending orders
        m_cntCustomerOrder = g_pending.size();
    }

    //record workstation and store recorded collection
    void LineManager::reorderStations() {

        std::vector<Workstation*> reordered;
        
        //start recording from first
        Workstation* current = m_firstStation;

        while (current) {
        //add all station in list
            reordered.push_back(current);
            current = current->getNextStation();
        }

        //replace active line with recorder line
        m_activeLine = std::move(reordered);
    }

    bool LineManager::run(std::ostream& os) {

        //keep tract of iteration
        static size_t iteration = 0;
        ++iteration;
        

        //print -`Line Manager Iteration: COUNT<endl>`
        os << "Line Manager Iteration: " << iteration << std::endl;
       
        //if oreders are pending 
        if (!g_pending.empty()) {
            //move first to first sttion
            *m_firstStation += std::move(g_pending.front());

            //remove from pending
            g_pending.pop_front();
        }

        //fill orders at every station active
        std::for_each(m_activeLine.begin(), m_activeLine.end(),
            [&os](Workstation* station) {
                station->fill(os);
            });

        //move order from eact station to active line
        std::for_each(m_activeLine.begin(), m_activeLine.end(),
            [](Workstation* station) {
                station->attemptToMoveOrder();
            });

        //check if all customer orders are completed 
        return (g_completed.size() + g_incomplete.size() == m_cntCustomerOrder);
    }

    void LineManager::display(std::ostream& os) const {

        //display all station
        std::for_each(m_activeLine.begin(), m_activeLine.end(),
            [&os](Workstation* station) {
                station->display(os);
            });
    }

} // namespace seneca