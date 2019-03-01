#ifndef SCOMPARE_H
#define SCOMPARE_H

#include "Station.h"

struct SCompare
{
	bool operator()(Station* s1, Station* s2) {
		return *s1 > *s2;
	}
};

#endif