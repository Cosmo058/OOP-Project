// Milestone 3
// Station.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 22/Mar/2019

#ifndef SICT_STATION_H
#define SICT_STATION_H


#include <iostream>
#include <string>
#include <queue>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
	class Station {
		std::queue<CustomerOrder> customerOrder;
		ItemSet itemSet;

	public:
		Station(const std::string&);
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;

		Station(const Station& s) = delete;
		Station& operator=(const Station& s) = delete;
		Station(Station&& s) = delete;
		Station& operator=(Station&& s) = delete;
	};
}

#endif //SICT_STATION_H
