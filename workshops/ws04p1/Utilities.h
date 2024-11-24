#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

namespace seneca
{
	class Utilities
	{
		size_t m_widthField{ 1 };
		static char m_delimiter;

	public:
		// sets the field width of the current object to the value of parameter newWidth
		void setFieldWidth(size_t newWidth);

		// returns the field width of the current object
		size_t getFieldWidth() const;

		// extracts a token from string str referred to by the first parameter.
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		// class function
		// sets the delimiter for this class to the character received
		static void setDelimiter(char newDelimiter);

		// returns the delimiter for this class.
		static char getDelimiter();
	};

}

#endif


