// Milestone 3
// Station.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 22/Mar/2019

#include "Station.h"

namespace sict {
	Station::Station(const std::string& inStr) : itemSet(inStr) {}

	void Station::display(std::ostream& os) const {
		itemSet.display(os, true);
	}

	void Station::fill(std::ostream& os) {
		if (!customerOrder.empty()) {
			customerOrder.back().fillItem(itemSet, os);
		}
	}

	const std::string& Station::getName() const {
		return itemSet.getName();
	}

	bool Station::hasAnOrderToRelease() const {
		bool response = false;
		if (!customerOrder.empty()) {
			if (customerOrder.front().isItemFilled(itemSet.getName()) || itemSet.getQuantity() == 0) {
				response = true;
			}
		}
		return response;
	}

	Station& Station::operator--() {
		--itemSet;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		customerOrder.push(std::move(order));
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		bool response = false;
		if (!customerOrder.empty()){
			response = (customerOrder.front()).isFilled();
			ready = std::move(customerOrder.front());
			customerOrder.pop();
		}
		return response;
	}

	void Station::validate(std::ostream& os) const {
		os << " getName(): " << itemSet.getName() << std::endl;
		os << " getSerialNumber(): " << itemSet.getSerialNumber() << std::endl;
		os << " getQuantity(): " << itemSet.getQuantity() << std::endl;
	}
}
