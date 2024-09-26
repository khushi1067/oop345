#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <iostream>
#include <string>



using namespace std;
namespace seneca {

	//structure settigs
	struct Settings {

		//boolean attribute default-false
		bool m_show_all = false;
		bool m_verbose = true;

		//stores time units 
		std::string m_time_units = "nanoseconds";

	};

	//global variable 
	extern Settings g_settings;

}


#endif
