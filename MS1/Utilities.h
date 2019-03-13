// Workshop 6
// Utilities.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 12/Mar/2019

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H

#include<string>
#include<iomanip>

namespace sict {

	class Utilities {

	public:
		Utilities();
		const std::string extractToken(const std::string&, size_t&);
		const char getDelimiter() const;
		static size_t getFieldWidth();
		static void setDelimiter(const char);
		void setFieldWidth(size_t);
	};
}

#endif // !SICT_UTILITIES_H
