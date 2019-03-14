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
 * Finds the shortest path in minutes to get from start to end based on the A* algorithm. The function does not return anything, but it changes the 
 * previous variable in the Station objects based on the how to get there the fastest including heuristics which is distance to end divided by top 
 * speed and finally multiplied  by 60 to convert it into minutes.
 * When the fastest path to end has been found, the path there can be printed through the end stations previous variable and then using the previous on
 * every previous station until the start station has been reached. This can also be done by using the printPath() function in TransportGraph after
 * this function has been run.
 * 
 * If there is no paths/edges leading to the end station the function will not set a path and using the printPath() function will print that no path to 
 * the end station exists. The function will however always try to find a path and go through all objects it can get to through connected paths/edges 
 * and it will print the stations when it finds its fastest way there to cout with name and time. It will only stop when it has found the shortest path
 * to all stations/objects it can possibly get to if end station is not reachable, the same is also true if the station does not exists within the 
 * graphs context. 
 * 
 * print all stations it goes to and how long it takes.
 * If either Station* start or end is a nullptr the function will not run and nothing happens, start and end stations are required to be able to find a 
 * path. The same is true if Int time is a value below zero.
 *
 * @param Station* start and end representing where to travel from and to in the graph. 
 * @param int time representing the time to start travelling in minutes. Also used to find the best path in regards to departure times and lengths.
 * @return This function returns void.
 */
void TransportGraph::aStar(Station* start, Station* end, int time)
{
	if (end != nullptr && start != nullptr && time >= 0) {
		destination = end;
		startStation = start;
		std::priority_queue<Station*, std::vector<Station*>, SCompare> pq;

		for (auto& s : stations) {
			s.second->setTimeAway(INFINITY);
			s.second->setKnown(false);
		}

		start->setTimeAway(0 + time);
		
		pq.push(start);

		while (!end->getKnown() && !(pq.size() == 0)) {
			Station* s = pq.top();
			pq.pop();
			std::cout << "Station: " << s->getName() << " Minuter: " << s->getTimeAway() << std::endl;

			if (!s->getKnown()) {

				s->setKnown(true);

				for (auto& p : s->getPaths()) {

					if (!p.second->station->getKnown()) {

						std::pair<int, std::pair<int, Transport*>> temp = p.second->tt->getDeparture(s->getTimeAway());
						int timeAway = temp.second.first;

						if (p.second->station->getTimeAway() == INFINITY || s->getTimeAway() + timeAway < p.second->station->getTimeAway()) {

							p.second->station->setTimeAway(timeAway);
							int x = std::abs(end->getPosition()->x - p.second->station->getPosition()->x);
							int y = std::abs(end->getPosition()->y - p.second->station->getPosition()->y);
							double distance = std::sqrt(x * x + y * y);
							p.second->station->setHTimeAway((distance / Transport::getTopSpeed()) * 60);
							p.second->station->setPrevious(s);
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
 * @return Station object reference (Station*) to the station with the parameter name sent in the function. If no station has that name it prints to cout "No such station exists!" and returns a nullptr.
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
		if (destination->getKnown()) {
			std::string temp = "Station: " + destination->getName() + ", Minuter: " + std::to_string(destination->getTimeAway());

			for (Station* s = destination->getPrevious(); s->getName() != startStation->getName(); s = s->getPrevious()) {
				std::string t = "Station: " + s->getName() + ", Minuter: " + std::to_string(s->getTimeAway()) + ", ";
				temp.insert(0, t);
			}

			std::string t = "Station: " + startStation->getName() + ", Minuter: " + std::to_string(startStation->getTimeAway()) + ", ";
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
