#ifndef PATH_H
#define PATH_H

#include "TimeTable.h"

template <typename T>
struct Path
{
	Path(T s, int l) : station(s), length(l) {}
	T station;
	int length;
	TimeTable* tt = TimeTable::getInstance();
};

#endif