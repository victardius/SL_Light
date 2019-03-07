#ifndef SCOMPARE_H
#define SCOMPARE_H

#include "Station.h"

struct SCompare
{
/**
 * Compare object/function used in the TransportGraph to compare Station* objects.
 *
 * @param Station* st and s2 two stations to be compared if s1 is larger than s2.
 *
 * @return bool true if s1 is larger than s2, false if s2 is equal or larger than s1.
 */
	bool operator()(Station* s1, Station* s2) {
		return *s1 > *s2;
	}
};

#endif