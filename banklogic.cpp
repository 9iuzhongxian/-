#include "tool.h"
#include "banklogic.h"

std::vector<std::deque<qelemtype>> q(5);
std::forward_list<event> eventlist;

std::default_random_engine e((unsigned)time(0));
std::uniform_int_distribution<unsigned> intertime(0, 5);//银行客户到达相隔时间
std::uniform_int_distribution<unsigned> durtime(0, 30);//银行客户逗留时间

void openforday()
{
	event en;
	en.setcurrenttime(0);
	en.settype(0);
	orderinsert(eventlist, en);

}

unsigned gettotaltime()
{
	return totaltime;
}

void customerarrived(event & eventpass,unsigned closetime)
{
	++customnum;
	unsigned duration, interation,t;
	

	duration = durtime(e);
	interation = intertime(e);
	t = eventpass.getcurrenttime() + interation;
	if (t < closetime) {
		event arv(t, 0);//下一个客户的到来事件
		orderinsert(eventlist, arv);
	}
	int i = minqlist(q);
	qelemtype elem(eventpass.getcurrenttime(),duration);//该客户进入人数最少队列，并记录到达时间和逗留时间
	q[i].push_back(elem);
	if (q[i].size() == 1) {

		event leave(eventpass.getcurrenttime() + duration, i);
		orderinsert(eventlist, leave);
	}
	



}

unsigned getcustomnum()
{
	return customnum;
}

void departure(event &eventpass)
{
	unsigned i = eventpass.gettype();
	qelemtype &customer = q[i].front();
	totaltime =totaltime+(eventpass.getcurrenttime() - customer.getarrivetime());
	q[i].pop_front();
	if (!q[i].empty()) {//该队列剩下的客户插入事件表
		qelemtype &customeranother = q[i].front();
		event another(eventpass.getcurrenttime() + customeranother.getduration(), i);
		orderinsert(eventlist, another);
	}


}


