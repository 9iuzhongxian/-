
#ifndef __banklogic_h
#define __banklogic_h

#include "simulation.h"
static unsigned totaltime = 0;//顾客总的逗留时间
static unsigned customnum = 0;//顾客总人数

extern std::default_random_engine e;
extern std::uniform_int_distribution<unsigned> intertime;//银行客户到达相隔时间
extern std::uniform_int_distribution<unsigned> durtime;//银行客户逗留时间


extern std::vector<std::deque<qelemtype>> q;
extern std::forward_list<event> eventlist;


unsigned gettotaltime();
unsigned getcustomnum();

void openforday();
void customerarrived(event &,unsigned closetime);
void departure(event &);

#endif // !__banklogic_h

