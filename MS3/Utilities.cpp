// Milestone 3
// Utilities.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 9/Apr/2019

#include "Utilities.h"

namespace sict {
	static size_t fw;
	static char delimiter;

	Utilities::Utilities() {
		fw = 0;
		delimiter = '|';
	}

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string tempStr = str.substr(next_pos);
		size_t pos = tempStr.find(getDelimiter());
		std::string tkn;
		bool isLastField = false;
		if (pos >= 0 && (pos < tempStr.length()))
			tkn = tempStr.substr(0, pos);
		else {
			tkn = tempStr;
			isLastField = true;
		}

		if (getFieldWidth() < tkn.length()) {
			setFieldWidth(tkn.length());
		}

		next_pos = next_pos + tkn.length() + 1;

		if (isLastField) {
			next_pos--;
		}
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