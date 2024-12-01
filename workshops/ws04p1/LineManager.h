#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Workstation.h"

namespace seneca {

	//manage assembly line of active stations

	class LineManager {

		//collection of workstation for current assembly line
		std::vector<Workstation*> m_activeLine;

		//count customer order
		size_t m_cntCustomerOrder{ 0 };

		//ptr to point first active stattion on current line
		Workstation* m_firstStation{ nullptr };
	public:

		//receives name of file, identify active station, collection of workstations available
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);

		//record workstation
		void reorderStations();

		//perform operation on all workstations
		bool run(std::ostream& os);

		//display function
		void display(std::ostream& os) const;
	};

} // namespace seneca

#endif // !SENECA_LINEMANAGER_H