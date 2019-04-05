// Milestone 2
// CustomerOrder.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 22/Mar/2019

#ifndef SICT_CUSTOMER_ORDER_H
#define SICT_CUSTOMER_ORDER_H

#include <string>
#include <algorithm>

#include "ItemSet.h"

namespace sict {
	class CustomerOrder {
		struct ItemInfo {
			std::string name;
			int order_no;
			bool filled;
			ItemInfo() : name{ "" }, order_no{ 0 }, filled{ false } {}
		}*items;

		std::string customer_name;
		std::string product_assambled;
		size_t num_Items;
		static size_t FW;

	public:
		CustomerOrder();
		explicit CustomerOrder(const std::string&);
		~CustomerOrder();
		void fillItem(ItemSet&, std::ostream&);
		bool isFilled() const;
		bool isItemFilled(const std::string&) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;

		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&);
		CustomerOrder& operator=(CustomerOrder&&);
	};
}

#endif //SICT_CUSTOMER_ORDER_H