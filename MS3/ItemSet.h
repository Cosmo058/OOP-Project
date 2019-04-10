// Milestone 3
// ItemSet.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 9/Apr/2019

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H

#include "Utilities.h"

namespace sict {
	class ItemSet {
		std::string name;
		unsigned int serial_num;
		unsigned int quantity;
		std::string desc;

	public:
		ItemSet(const std::string);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream&, bool) const;
	};
}

#endif // !SICT_ITEMSET_H
