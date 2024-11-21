#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
#include "mediaItem.h"
#include <iostream>
#include <iomanip>
#include <fstream>

namespace seneca
{
	struct Settings
	{
		int m_maxSummaryWidth{ 80 };
		bool m_tableView{ false };
	};

	extern Settings g_settings;
}

#endif