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

/**
 * Finds the shortest path in minutes to get from start to end. The function does not return anything, but it changes the previous variable in the
 * Station objects based on the how to get there the fastest including heuristics which is distance to end divided by top speed and finally multiplied 
 * by 60 to convert it into minutes.
 * When the fastest path to end has been found the path there can be printed through the end stations previous variable and then using the previous on
 * every previous station until the start station has been reached. This can also be done by using the printPath() function in TransportGraph after
 * this function has been run.
 *
 * @param Station* start and end representing where to travel from and to in the graph. 
 * @param int time representing the time to start travelling in minutes. Also used to find the best path in regards to departure times and lengths.
 */
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

/**
 * Adds a new station to the graph without any edges (edges need to be added by using the addPath() function on stations). 
 *
 * @param String representing the name of the station that will be used to find the station.
 * @param int x and y represents the coordinates where this station will be. 
 */
void TransportGraph::addStation(std::string name, int x, int y)
{
	stations.emplace(name, Station::getInstance(name, x, y));
}

/**
 * Gets the station object reference related to the string sent as a parameter from the graph.
 * 
 * @param String that is the name of a station previously added.
 *
 * @return Station object reference (Station*) to the station with the parameter name sent in the function. If no station has that name it prints to cout "No such station exists!".
 */
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

/**
 * Prints to cout the path found by the aStar function to the found station.
 * <p>
 * If there was no path to the station it will print to cout "Could not find a path to STATIONNAME"
 * 
 * @return true if a path was searched for with aStar before running printpath, false if no station has been searched for.
 */
bool TransportGraph::printPath()
{
	if (destination != nullptr) {
		if (destination->known) {
			std::string temp = "Station: " + destination->getName() + ", Minuter: " + std::to_string(destination->timeAway);

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

		return true;
	}
	return false;
}


TransportGraph::~TransportGraph()
{
}

TransportGraph tg;
