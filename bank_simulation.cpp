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

	std::cout << "ÿλ���˵�ƽ������ʱ��" << (float)gettotaltime() / getcustomnum() << std::endl;




}

