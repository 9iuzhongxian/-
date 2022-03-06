#include "tool.h"
#include "banklogic.h"

std::vector<std::deque<qelemtype>> q(5);
std::forward_list<event> eventlist;

std::default_random_engine e((unsigned)time(0));
std::uniform_int_distribution<unsigned> intertime(0, 5);//���пͻ��������ʱ��
std::uniform_int_distribution<unsigned> durtime(0, 30);//���пͻ�����ʱ��

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
		event arv(t, 0);//��һ���ͻ��ĵ����¼�
		orderinsert(eventlist, arv);
	}
	int i = minqlist(q);
	qelemtype elem(eventpass.getcurrenttime(),duration);//�ÿͻ������������ٶ��У�����¼����ʱ��Ͷ���ʱ��
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
	if (!q[i].empty()) {//�ö���ʣ�µĿͻ������¼���
		qelemtype &customeranother = q[i].front();
		event another(eventpass.getcurrenttime() + customeranother.getduration(), i);
		orderinsert(eventlist, another);
	}


}


