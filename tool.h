
#ifndef __tool_h
#define __tool_h

#include "simulation.h"
#include <algorithm>

void initlist(std::forward_list<event> & );
//bool compareA(const event&, const event&);
//using Func = bool (*)(const event&, const event&);
void orderinsert(std::forward_list<event>&, event&);
int minqlist(std::vector<std::deque<qelemtype>>& q);



#endif // !__tool_h

