#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate
{
	Coordinate(int xx, int yy) : x(xx), y(yy) {};
	int operator-(const Coordinate other) {
		return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
	}
	int x, y;
};

#endif