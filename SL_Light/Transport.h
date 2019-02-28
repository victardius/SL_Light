#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "TimeTable.h"

class Transport
{
public:
	const static int getTopSpeed();
	virtual int getSpeed() = 0;
	void setTimeTable();
protected:
	Transport(int s);
	virtual ~Transport();
private:
	TimeTable* timeTable;
	static int topSpeed;
	int speed;
};

#endif

