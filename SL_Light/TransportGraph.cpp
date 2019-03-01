#include "TransportGraph.h"
#include "Path.h"
#include "SCompare.h"
#include <queue>
#include <vector>
#include <iostream>


TransportGraph::TransportGraph()
{
	
}

void TransportGraph::aStar(Station* start, Station* end, int time)
{

	std::priority_queue<Station*, std::vector<Station*>, SCompare> pq;

	for (auto& s : stations) {
		s.second->timeAway = (int)INFINITY;
		s.second->known = false;
	}

	start->timeAway = 0;

	pq.push(start);

	while ((end->timeAway == (int)INFINITY && !end->known) || pq.empty()) {
		Station* s = pq.top();
		pq.pop();
		std::cout << "Station: " << s->getName() << " Minuter: " << s->timeAway << std::endl;

		if (!s->known) {

			s->known = true;

			for (auto& p : s->getPaths()) {
				
				if (!p.second->station->known) {

					std::pair<int, std::pair<int, Transport*>> temp = p.second->tt->getDeparture(time);
					int timeAway = temp.second.first; 

					if (p.second->station->timeAway == (int)INFINITY || s->timeAway + timeAway < p.second->station->timeAway) {

						p.second->station->timeAway = s->timeAway + timeAway;
						p.second->station->hTimeAway = (std::abs(*p.second->station->getPosition() - *end->getPosition()) / Transport::getTopSpeed()) * 60;
						p.second->station->previous = s;
						pq.push(p.second->station);//kan vara ett alternativ att göra en egen prioritetskö
					}
				}
			}
		}
	}
}

void TransportGraph::addStation(std::string name, int x, int y)
{
	stations.emplace(name, Station::getInstance(name, x, y));
}

Station * TransportGraph::getStation(std::string name)
{
	return stations.at(name);
}


TransportGraph::~TransportGraph()
{
}

TransportGraph tg;
