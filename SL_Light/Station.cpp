#include "Station.h"



Station::Station(std::string name, int x, int y): name(name), previous(nullptr)
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
	paths.emplace(s->name ,new Path<Station*>(s, distance));
}

std::unordered_map<std::string, Path<Station*>*> Station::getPaths()
{
	return paths;
}

Path<Station*>* Station::getPath(std::string name)
{
	return paths.at(name);
}

std::string Station::getName()
{
	return name;
}

bool Station::operator<(const Station& other)
{
	return timeAway + hTimeAway < other.timeAway + other.hTimeAway;
}

bool Station::operator>(const Station& other)
{
	return timeAway + hTimeAway > other.timeAway + other.hTimeAway;
}

bool Station::getKnown()
{
	return known;
}

Station * Station::getPrevious()
{
	return previous;
}

int Station::getTimeAway()
{
	return timeAway;
}

int Station::getHTimeAway()
{
	return hTimeAway;
}

void Station::setKnown(bool k)
{
	known = k;
}

void Station::setPrevious(Station * s)
{
	previous = s;
}

void Station::setTimeAway(int ta)
{
	timeAway = ta;
}

void Station::setHTimeAway(int hta)
{
	hTimeAway = hta;
}

Station::~Station()
{
	
}
