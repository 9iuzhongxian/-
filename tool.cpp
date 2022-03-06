#include "tool.h"



void initlist(std::forward_list<event>& eventlist)
{
	event a, b;
	a.setcurrenttime(3);
	b.setcurrenttime(1);
	eventlist = { a,b };

}


bool compareA(const event& E1, const event& E2)
{
	
	bool b = (E1.getcurrenttime()) < (E2.getcurrenttime());
	return b;
}


void orderinsert(std::forward_list<event>&Elist, event&En)
{
	//initlist(Elist);
	//auto prev = Elist.before_begin();
	Elist.push_front(En);
	//std::vector<int> vtor{ 1,2 ,4,7,5,10};
	Elist.sort();
	//for(auto & v:Elist) {
	//	std::cout << v.getcurrenttime()<<"\n";
	//}



}

int minqlist(std::vector<std::deque<qelemtype>>& q)
{

	unsigned min = q[1].size();
	unsigned minindex = 1;

		for (unsigned i=2; i < 5; i++) {
			if (q[i].size() < min) {
				min = q[i].size();
				minindex = i;
			}

	}
	return minindex;

}

