#include "TimeTable.h"
#include <iostream>

#define INFINITY 999999999

TimeTable::TimeTable()
{
}


TimeTable * TimeTable::getInstance()
{
	return new TimeTable();
}

void TimeTable::addDeparture(double time, Transport * trans, double length)
{
	//std::cout << ((length / 100000) * 60) + time << std::endl;
	double arriv = ((length / trans->getSpeed()) * 60) + time;
	dep.emplace(time, std::make_pair(arriv, trans));
}

std::pair<int, std::pair<int, Transport*>> TimeTable::getDeparture(int time)
{
	int depart = INFINITY, arrive = INFINITY;
	Transport* trans;
	for (auto& a : dep) {
		if (a.first >= (time % 60) && a.second.first < arrive) {
			depart = a.first;
			arrive = a.second.first;
		}
	}

	return std::make_pair(depart, std::make_pair(arrive, trans));
}

TimeTable::~TimeTable()
{
}
