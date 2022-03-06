
#ifndef __banklogic_h
#define __banklogic_h

#include "simulation.h"
static unsigned totaltime = 0;//�˿��ܵĶ���ʱ��
static unsigned customnum = 0;//�˿�������

extern std::default_random_engine e;
extern std::uniform_int_distribution<unsigned> intertime;//���пͻ��������ʱ��
extern std::uniform_int_distribution<unsigned> durtime;//���пͻ�����ʱ��


extern std::vector<std::deque<qelemtype>> q;
extern std::forward_list<event> eventlist;


unsigned gettotaltime();
unsigned getcustomnum();

void openforday();
void customerarrived(event &,unsigned closetime);
void departure(event &);

#endif // !__banklogic_h

