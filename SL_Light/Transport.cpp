#include "Transport.h"



const int Transport::getTopSpeed()
{
	return topSpeed;
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
