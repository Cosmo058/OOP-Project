// Milestone 3
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
		}*items = nullptr;

		std::string customer_name;
		std::string product_assambled;
		size_t num_Items;
		static size_t FW;

	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		~CustomerOrder();
		void fillItem(ItemSet&, std::ostream&);
		bool isFilled() const;
		bool isItemFilled(const std::string&) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;

		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
	};
}
#endif //SICT_CUSTOMER_ORDER_H