#ifndef TRANSPORTGRAPH_H
#define TRANSPORTGRAPH_H

#include "Station.h"
#include <unordered_map>

class TransportGraph
{
public:
	TransportGraph();
	void aStar(Station* start, Station* end, int star);
	void addStation(std::string name, int x, int y);
	Station* getStation(std::string name);
	bool printPath();
	~TransportGraph();
private:
	std::unordered_map<std::string, Station*> stations;
	Station* destination = nullptr, *startStation = nullptr;
};

extern TransportGraph tg;

#endif