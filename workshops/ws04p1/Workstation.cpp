/*
    Name: Khushi Abhay Bhandari
    Email-kabhandari@myseneca.ca
    Student ID: 106774235
    Date: 01/12/2024
*/
#include <iostream>
#include <deque>
#include <string>


#include "Workstation.h"
#include "Station.h"
#include "CustomerOrder.h"
#include "LineManager.h"
#include "Utilities.h"


namespace seneca {

    //hold oreder at assembly line at first station
    std::deque<CustomerOrder> g_pending;
    //hold order that have removed from last station and are completely filled
    std::deque<CustomerOrder> g_completed;
    //removed and are incomplete
    std::deque<CustomerOrder> g_incomplete;


    void Workstation::fill(std::ostream& os) {
        //fill order 
        //check for empty
        if (!m_orders.empty()) {
            
            m_orders.front().fillItem(*this, os);
        }
    }

    bool Workstation::attemptToMoveOrder() {

    // Check if there are any orders in the queue
        if (!m_orders.empty()) {

            // Check if the front order's item is filled or not in quantity
            if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
               
                // If  next workstation move order there
                if (m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                }
                else {
                    // If no next station check order is filled
                    if (m_orders.front().isOrderFilled()) {

                        // Add order to complete list
                        g_completed.push_back(std::move(m_orders.front()));
                    }
                    else {
                        // add order to incomplete list
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }

                //remove order 
                m_orders.pop_front();
                return true;
            }
        }
        return false;
    }

    void Workstation::setNextStation(Workstation* station) {

        //station as obj ptr
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        
        //return address of next station
        return m_pNextStation;
    }

    //display
    void Workstation::display(std::ostream& os) const {
        //`ITEM_NAME --> End of Line`
        os << getItemName() << " --> "
            << (m_pNextStation ? m_pNextStation->getItemName() : "End of Line")
            << '\n';
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        //move new order in queue
        m_orders.push_back(std::move(newOrder));
        return *this;
    }

} // namespace seneca
