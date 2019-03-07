#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>

struct Coordinate
{
/**
 * Internal class for managing coordinates used by stations in some functions.
 *
 * @param int representing x and y coordinates/location.
 */
	Coordinate(int xx, int yy) : x(xx), y(yy) {};
	int x, y;
};

#endif