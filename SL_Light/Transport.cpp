#include "Transport.h"



const int Transport::getTopSpeed()
{
	return topSpeed;
}

int Transport::getSpeed()
{
	return speed * 1000;
}

void Transport::setTimeTable()
{
}

Transport::Transport(int s): speed(s)
{
	if (s > topSpeed)
		topSpeed = s;
}


Transport::~Transport()
{
}
