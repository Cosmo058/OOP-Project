// Milestone 3
// LineManager.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 22/Mar/2019

#include "LineManager.h"

namespace sict {

	LineManager::LineManager(std::vector<Station*>& station, std::vector<size_t>& next_index, std::vector<CustomerOrder>& customerOrders, size_t starting_index, std::ostream& os) : stations(station), indexes(next_index), num_orders(customerOrders.size()), start_point(starting_index){
		for (size_t i = 0u; i < customerOrders.size(); i++) {
			to_fill.push_front(std::move(customerOrders[i]));
		}
		end_num = starting_index;
		for (size_t i = 0u; i < indexes.size(); i++) {
			if (indexes[end_num] < stations.size()) {
				end_num = indexes[end_num];
			}
		}
	}

	void LineManager::display(std::ostream& os) const {
		os << "COMPLETED ORDERS" << std::endl;
		for (size_t i = 0u; i < completed.size(); i++) {
			completed[i].display(os, true);
		}
		os << std::endl;
		os << "INCOMPLETE ORDERS" << std::endl;
		for (size_t i = 0u; i < incompleted.size(); i++) {
			incompleted[i].display(os, true);
		}
		
	}

	bool LineManager::run(std::ostream& os) {
		bool finish = false;
		if (!to_fill.empty()) {
			*stations[start_point] += std::move(to_fill.back());
			to_fill.pop_back();
		}
		
		for (size_t i = 0u; i < stations.size(); i++) {
			stations[i]->fill(os);
		}

		for (size_t i = 0u; i < stations.size(); ++i) {
			
			if (stations[i]->hasAnOrderToRelease()) {
				CustomerOrder custOrder;
				bool done = stations[i]->pop(custOrder);
				os << " --> " << custOrder.getNameProduct() << " moved from " << stations[i]->getName() << " to ";
				if (i != end_num) {
					os << stations[indexes[i]]->getName() << std::endl;
					*stations[indexes[i]] += std::move(custOrder);
				}
				else if (done) {
					os << "Completed Set" << std::endl;
					completed.push_back(std::move(custOrder));
				}
				else {
					os << "Incomplete Set" << std::endl;
					incompleted.push_back(std::move(custOrder));
				}
			}
		}

		if ((completed.size() + incompleted.size()) == num_orders) {
			finish = true;
		}
		return finish;
	}
}
