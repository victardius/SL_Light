#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <map>
#include "Transport.h"

class TimeTable
{
public:
	static TimeTable* getInstance();
	void addDeparture(int time, Transport* trans, int length);
	std::pair<int, std::pair<int, Transport*>> getDeparture(int time);
	~TimeTable();
protected:
	TimeTable();
private:
	std::map<int, std::pair<int, Transport*>> dep;
};

#endif

