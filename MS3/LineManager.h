// Milestone 3
// LineManager.h
// Student Name : Angel Sanchez
// Student #: 153582176
// Student Id: asanchez-valencia
// 22/Mar/2019

#ifndef SICT_PROGRAM_MANAGER_H
#define SICT_PROGRAM_MANAGER_H

#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include "AssemblyLine.h"
#include "Station.h"
#include "CustomerOrder.h"

namespace sict {
	
	class LineManager {

		std::deque<CustomerOrder> to_fill;		
		std::deque<CustomerOrder> completed;
		std::deque<CustomerOrder> incompleted;
		std::vector<Station*> stations;
		std::vector<size_t> indexes;
		const size_t num_orders;
		const size_t start_point;
		size_t end_num;
	public:
		LineManager(std::vector<Station*>& , std::vector<size_t>& , std::vector<CustomerOrder>& , size_t , std::ostream& os);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}

#endif //SICT_PROGRAM_MANAGER_H
