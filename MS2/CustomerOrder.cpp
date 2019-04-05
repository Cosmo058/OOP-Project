// Milestone 2
// CustomerOrder.cpp
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 22/Mar/2019

#include "CustomerOrder.h"

namespace sict {
	size_t CustomerOrder::FW = 12;

	CustomerOrder::CustomerOrder() : items{ nullptr }, customer_name{ "" }, product_assambled{ "" }, num_Items{ 0 } {}

	CustomerOrder::CustomerOrder(const std::string& record) : CustomerOrder() {
		Utilities utils;

		size_t delim_pos = record.find(utils.getDelimiter()) + 1;
		customer_name = record.substr(0, delim_pos-1);

		if (FW < utils.getFieldWidth()) {
			FW = utils.getFieldWidth();
		}

		product_assambled = utils.extractToken(record, delim_pos);

		num_Items = std::count(record.begin(), record.end(), utils.getDelimiter()) - 1;
		items = new ItemInfo[num_Items];

		if (num_Items >= 1) {
			for (size_t i = 0; i < num_Items; i++) {
				items[i].name = utils.extractToken(record, delim_pos);
			}
		}
		else {
			throw "***No items are found***";
		}
	}

	CustomerOrder::~CustomerOrder() {
		delete[] items;
		items = { nullptr };
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (size_t i = 0; i < num_Items; ++i) {
			if (item.getName() == items[i].name) {
				if (item.getQuantity() == 0) {
					os << " Unable to fill " << customer_name << " [" << product_assambled << "][" << items[i].name << "][" << items[i].order_no << "] out of stock" << std::endl;
				}
				else {
					if (items[i].filled) {
						os << " Unable to fill " << customer_name << " [" << product_assambled << "][" << items[i].name << "][" << items[i].order_no << "] already filled" << std::endl;
					}
					else {
						items[i].order_no = item.getSerialNumber();
						items[i].filled = true;
						item.operator--();
						os << " Filled " << customer_name << " [" << product_assambled << "][" << items[i].name << "][" << items[i].order_no << "]" << std::endl;
					}
				}
			}
		}
	}

	bool CustomerOrder::isFilled() const {
		for (size_t i = 0; i < num_Items; ++i) {
			if (!items[i].filled) {
				return false;
			}
		}
		return true;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (size_t i = 0; i < num_Items; ++i) {
			if (items[i].name == itemName) {
				if (!items->filled) {
					return false;
				}
			}
		}
		return true;
	}

	std::string CustomerOrder::getNameProduct() const {
		return std::string(customer_name) + "[" + std::string(product_assambled) + "]";
	}

	void CustomerOrder::display(std::ostream & os, bool showDetail) const {
		os << std::left << std::setw(FW) << customer_name << " [" << product_assambled << "]" << std::endl;
		if (!showDetail) {
			for (size_t i = 0; i < num_Items; ++i) {
				os << std::setfill(' ') << std::setw(FW + 1) << "    " << std::right << items[i].name << std::endl;
			}
		}
	}

	///////////////////////////////////////////////////
	CustomerOrder::CustomerOrder(CustomerOrder&& src) {
		*this = std::move(src);
	}

	CustomerOrder & CustomerOrder::operator=(CustomerOrder&& src) {
		if (this != &src) {
			customer_name = src.customer_name;
			product_assambled = src.product_assambled;
			num_Items = src.num_Items;
			items = src.items;
			src.items = { nullptr };
		}
		return *this;
	}

}