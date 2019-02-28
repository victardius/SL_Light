#ifndef STATION_H
#define STATION_H

#include "Coordinate.h"
#include "Transport.h"
#include "Path.h"
#include <unordered_map>
#include <vector>
#include <string>

class Station
{
public:
	static Station* getInstance(std::string name, int x, int y);
	Coordinate* getPosition();
	void addPath(int distance, Station*);
	std::vector<Path*> getPath();
	int timeAway = -1;
	Station* previous;
	bool known = false;
	//std::unordered_map<Station*, std::pair<int, std::vector<Transport*>>>* getAdjecent();
	bool operator<(Station* other) const;
	bool operator>(Station* other) const;
	Station() {};
	~Station();
protected:
	Station(std::string name, int x, int y);
private:
	Coordinate position{ 0,0 };
	//std::unordered_map<Station*, std::pair<int,std::vector<Transport*>>> adjacentStations;
	std::string name;
	std::vector<Path*> paths;
};

#endif

