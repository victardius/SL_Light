#include "TimeTable.h"
#include <iostream>


TimeTable::TimeTable()
{
}


TimeTable * TimeTable::getInstance()
{
	return new TimeTable();
}

void TimeTable::addDeparture(int time, Transport * trans, int length)
{
	std::cout << ((length / 100) * 60) << std::endl;
	int arriv = ((length / 100) * 60) % 60;
	dep.emplace(time, std::make_pair(arriv, trans));
}

std::pair<int, std::pair<int, Transport*>> TimeTable::getDeparture(int time)
{
	int depart, arrive = (int)INFINITY;
	Transport* trans;
	for (auto& a : dep) {
		if (a.first >= time && a.second.first < arrive) {
			depart = a.first;
			arrive = a.second.first;
		}
	}

	return std::make_pair(depart, std::make_pair(arrive, trans));
}

TimeTable::~TimeTable()
{
}
