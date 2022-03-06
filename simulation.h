
#ifndef __simulation_h
#define __simulation_h




#include <list>
#include <iostream>
#include <random>
#include <forward_list>
#include <queue>
#include <random>
#include <ctime>




/*�¼�����ʱ������ͣ������У�
	1.�˿͵����¼�����
	2.�˿ʹӶ���1�뿪����
	3.�˿ʹӶ���2�뿪����
	4.�˿ʹӶ���3�뿪����
	5.�˿ʹӶ���4�뿪����
	*/
class event {
public:
	event() = default;
	event(unsigned oc, unsigned tp):occurtime(oc),Type(tp){}
	
	unsigned getcurrenttime()const;
	void setcurrenttime(unsigned);
	unsigned gettype()const;
	void settype(unsigned);

	inline bool operator<(const event& E2) { return this->occurtime < (E2.getcurrenttime()); }
private:
	unsigned occurtime=0;
	unsigned Type=0;

};





class qelemtype {
public:

	qelemtype() = default;
	qelemtype(unsigned avt, unsigned dr) :arrivetime(avt), duration(dr) {}
	unsigned getarrivetime();
	unsigned getduration();
	
	
	
private:
	unsigned arrivetime = 0;
	unsigned duration = 0;
};




#endif // !__simulation_h


