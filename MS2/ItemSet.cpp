// Workshop 6
// ItemSet.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 12/Mar/2019

#include "ItemSet.h"

namespace sict {
	ItemSet::ItemSet(const std::string str) {

		size_t pos = 0u;

		Utilities u;
		name = u.extractToken(str, pos);

		std::string tmp = u.extractToken(str, pos);
		serial_num = std::stoi(tmp);

		tmp = u.extractToken(str, pos);
		quantity = std::stoi(tmp);

		desc = u.extractToken(str, pos);
	}

	const std::string& ItemSet::getName() const {
		return name;
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return serial_num;
	}

	const unsigned int ItemSet::getQuantity() const {
		return quantity;
	}

	ItemSet& ItemSet::operator--() {
		quantity--;
		serial_num++;
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {
		if (full) {
			os << std::left << std::setw(12) << getName() << " [" <<
				std::setw(5) << getSerialNumber() << "] Quantity " <<
				std::setw(3) << getQuantity() << " Description: " <<
				desc << std::endl;
		}else {
			os << std::left << std::setw(Utilities::getFieldWidth()) << getName() << " [" <<
				std::setw(5) << getSerialNumber() << "]" << std::endl;
		}
	}
}