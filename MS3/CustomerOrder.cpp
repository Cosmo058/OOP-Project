// Milestone 3
// CustomerOrder.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 22/Mar/2019

#include "CustomerOrder.h"
#include "Utilities.h"
#include <algorithm>

using namespace std;

namespace sict {
	size_t CustomerOrder::FW = 12;

	CustomerOrder::CustomerOrder() {
		customer_name = "";
		product_assambled = "";
		num_Items = 0;
		items = nullptr;
	}

	CustomerOrder::CustomerOrder(const string& inStr) {
		num_Items = 0;
		size_t pos = 0;
		Utilities util;
		customer_name = util.extractToken(inStr, pos);
		product_assambled = util.extractToken(inStr, pos);
		if (FW < customer_name.length()) {
			FW = customer_name.length() + 1;
		}
		num_Items = count(inStr.begin(), inStr.end(), '|') - 1;
		if (num_Items > 0) {
			items = new ItemInfo[num_Items];
			for (size_t i = 0; i < num_Items; i++) {
				items[i].name = util.extractToken(inStr, pos);
				items[i].filled = false;
				items[i].order_no = 0;
			}
		}
		else {
			throw "***No items are found***";
		}
	}

	CustomerOrder::~CustomerOrder() {
		delete[] items;
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {

		for (size_t i = 0; i < num_Items; i++) {
			if (items[i].name == item.getName()) {
				if (items[i].filled == false) {
					if (item.getQuantity() > 0) {
						items[i].order_no = item.getSerialNumber();
						items[i].filled = true;
						item.operator--();
						os << " Filled " << getNameProduct() << "[" << items[i].name << "][" << item.getSerialNumber() << "]" << endl;
					}
					else {
						os << " Unable to fill " << getNameProduct() << "[" << items[i].name << "][" << items[i].order_no << "]" << " out of stock" << endl;
					}
				}
				else {
					os << " Unable to fill " << getNameProduct() << "[" << items[i].name << "][" << items[i].order_no << "]" << " already filled" << endl;
				}
			}
		}
	}

	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < num_Items; i++) {
			if (items[i].filled == false) {
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const {
		for (size_t i = 0; i < num_Items; i++) {
			if (items[i].name == item) {
				if (items[i].filled == false) {
					return false;
				}
			}
		}
		return true;
	}

	std::string CustomerOrder::getNameProduct() const {
		return customer_name + " [" + product_assambled + "]";
	}

	void CustomerOrder::display(std::ostream& os, bool comp) const {
		os << left << setw(FW) << customer_name << "[" << product_assambled << "]" << endl;
		if (!comp) {
			for (size_t i = 0; i < num_Items; i++) {
				os << setw(FW) << " " << left << items[i].name << endl;
			}
		}
		else {
			for (size_t i = 0; i < num_Items; i++) {
				string str = items[i].filled == 0 ? "MISSING" : "FILLED";
				os << setw(FW) << " " << left << "[" << items[i].order_no << "] " << items[i].name << " - " << str << endl;
			}
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
		*this = std::move(src);

	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
		if (this != &src) {
			delete[] items;
			customer_name = src.customer_name;
			product_assambled = src.product_assambled;
			items = src.items;
			num_Items = src.num_Items;

			src.items = nullptr;
			src.customer_name = "";
			src.product_assambled = "";
			src.num_Items = num_Items;
		}
		return *this;
	}
}