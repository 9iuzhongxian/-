
#ifndef __simulation_h
#define __simulation_h




#include <list>
#include <iostream>
#include <random>
#include <forward_list>
#include <queue>
#include <random>
#include <ctime>




/*事件发生时间和类型，类型有：
	1.顾客到达事件类型
	2.顾客从队列1离开类型
	3.顾客从队列2离开类型
	4.顾客从队列3离开类型
	5.顾客从队列4离开类型
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


