// Workshop 6
// Utilities.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 12/Mar/2019

#include "Utilities.h"

namespace sict {
	static size_t fw;
	static char delimiter;

	Utilities::Utilities() {
		fw = 0;
		delimiter = '|';
	}

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string tmpStr = str.substr(next_pos);
		size_t pos = tmpStr.find(getDelimiter());
		std::string tkn;

		if (pos >= 0 && (pos < tmpStr.length())) {
			tkn = tmpStr.substr(0, pos);
		}else {
			tkn = tmpStr;
		}

		if (getFieldWidth() < tkn.length()) {
			setFieldWidth(tkn.length());
		}

		next_pos += tkn.length() + 1;
		return tkn;
	}

	const char Utilities::getDelimiter() const {
		return delimiter;
	}

	size_t Utilities::getFieldWidth() {
		return fw;
	}

	void Utilities::setDelimiter(const char d) {
		delimiter = d;
	}

	void Utilities::setFieldWidth(size_t f) {
		fw = f;
	}
}