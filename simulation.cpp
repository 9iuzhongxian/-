#include "simulation.h"





unsigned event::getcurrenttime()const
{
	return occurtime;
}

void event::setcurrenttime(unsigned time)
{
	occurtime = time;

}

unsigned event::gettype()const
{
	return Type;
}

void event::settype(unsigned typ)
{
	Type = typ;

}

//bool event::operator<(const event&E2){ return this->occurtime < (E2.getcurrenttime()); 


unsigned qelemtype::getarrivetime()
{
	return arrivetime;
}

unsigned qelemtype::getduration()
{
	return duration;
}
