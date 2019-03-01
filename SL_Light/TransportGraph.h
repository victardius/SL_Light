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
	~TransportGraph();
private:
	std::unordered_map<std::string, Station*> stations;
};

extern TransportGraph tg;

#endif