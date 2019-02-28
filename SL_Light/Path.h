#ifndef PATH_H
#define PATH_H

#include "Station.h"

struct Path
{
	Path(Station* s, int l) : station(s), length(l) {};
	Station* station;
	int length;
};

#endif