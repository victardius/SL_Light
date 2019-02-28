#include "Station.h"



Station::Station(std::string name, int x, int y): name(name)
{
	position.x = x;
	position.y = y;
}


Station * Station::getInstance(std::string name, int x, int y)
{
	return new Station(name, x, y);
}

Coordinate * Station::getPosition()
{
	return &position;
}

void Station::addPath(int distance, Station* s)
{
	paths.push_back(new Path(s, distance));
}

std::vector<Path*> Station::getPath()
{
	return paths;
}

//std::unordered_map<Station*, std::vector<Transport*>>* Station::getAdjecent()
//{
//	return nullptr;
//}

bool Station::operator<(Station * other) const
{
	return timeAway < other->timeAway;
}

bool Station::operator>(Station * other) const
{
	return timeAway > other->timeAway;
}

Station::~Station()
{
	
}
