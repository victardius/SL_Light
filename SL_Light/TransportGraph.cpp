#include "TransportGraph.h"
#include "Path.h"
#include "SCompare.h"
#include <queue>
#include <vector>
#include <iostream>

#define INFINITY 999999999

TransportGraph::TransportGraph()
{
	
}

void TransportGraph::aStar(Station* start, Station* end, int time)
{
	if (end != nullptr) {
		destination = end;
		startStation = start;
		std::priority_queue<Station*, std::vector<Station*>, SCompare> pq;

		for (auto& s : stations) {
			s.second->timeAway = INFINITY;
			s.second->known = false;
		}

		start->timeAway = 0 + time;
		
		pq.push(start);

		while (!end->known && !(pq.size() == 0)) {
			Station* s = pq.top();
			pq.pop();
			std::cout << "Station: " << s->getName() << " Minuter: " << s->timeAway << std::endl;

			if (!s->known) {

				s->known = true;

				for (auto& p : s->getPaths()) {

					if (!p.second->station->known) {

						std::pair<int, std::pair<int, Transport*>> temp = p.second->tt->getDeparture(s->timeAway);
						int timeAway = temp.second.first;

						if (p.second->station->timeAway == INFINITY || s->timeAway + timeAway < p.second->station->timeAway) {

							p.second->station->timeAway = timeAway;
							int x = std::abs(end->getPosition()->x - p.second->station->getPosition()->x);
							int y = std::abs(end->getPosition()->y - p.second->station->getPosition()->y);
							double distance = std::sqrt(x * x + y * y);
							p.second->station->hTimeAway = (distance / Transport::getTopSpeed()) * 60;
							p.second->station->previous = s;
							pq.push(p.second->station);//kan vara ett alternativ att göra en egen prioritetskö pga dubletter men den bör nästan aldrig gå igenom samma flera gånger
						}
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
	try {
		return stations.at(name);
	}
	catch (std::out_of_range) {
		std::cout << "No such station exists!" << std::endl;
		destination = nullptr;
		return nullptr;
	}
}

void TransportGraph::printPath()
{
	if (destination != nullptr) {
		if (destination->known) {
			std::string temp = "Station: " + destination->getName() + ", Minuter: " + std::to_string(destination->timeAway) + ", ";

			for (Station* s = destination->previous; s->getName() != startStation->getName(); s = s->previous) {
				std::string t = "Station: " + s->getName() + ", Minuter: " + std::to_string(s->timeAway) + ", ";
				temp.insert(0, t);
			}

			std::string t = "Station: " + startStation->getName() + ", Minuter: " + std::to_string(startStation->timeAway) + ", ";
			temp.insert(0, t);

			std::cout << temp << std::endl;
		}
		else
			std::cout << "Could not find a path to " << destination->getName() << std::endl;
	}
}


TransportGraph::~TransportGraph()
{
}

TransportGraph tg;
