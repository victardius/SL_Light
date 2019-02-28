#ifndef TRANSPORTGRAPH_H
#define TRANSPORTGRAPH_H

#include "Station.h"

class TransportGraph
{
public:
	TransportGraph();
	void aStar(Station* start, Station* end);
	~TransportGraph();
private:
	Station* stations[11];
};

#endif