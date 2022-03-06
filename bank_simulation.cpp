#include "bank_simulation.h"


void banksimulation(unsigned closetime)
{
	openforday();
	while (!eventlist.empty()) {

		auto& en = eventlist.front();
		event temp = en;
		eventlist.pop_front();
		if (temp.gettype() == 0)
			customerarrived(temp, closetime);
		else
			departure(temp);
		

	}

	std::cout << "每位客人的平均逗留时间" << (float)gettotaltime() / getcustomnum() << std::endl;




}

