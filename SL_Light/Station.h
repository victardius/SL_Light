#ifndef STATION_H
#define STATION_H

#include "Coordinate.h"
#include "Transport.h"
#include "Path.h"
#include "TimeTable.h"
#include <unordered_map>
#include <vector>
#include <string>

class Station
{
public:
	static Station* getInstance(std::string name, int x, int y);
	Coordinate* getPosition();
	void addPath(int distance, Station*);
	std::unordered_map<std::string, Path<Station*>*> getPaths();
	Path<Station*>* getPath(std::string name);
	std::string getName();
	int timeAway = (int)INFINITY;
	int hTimeAway = (int)INFINITY;
	Station* previous;
	bool known = false;
	bool operator<(const Station& other);
	bool operator>(const Station& other);
	Station() {};
	~Station();
protected:
	Station(std::string name, int x, int y);
private:
	Coordinate position{ 0,0 };
	std::string name;
	//std::vector<Path<Station*>*> paths;
	std::unordered_map<std::string, Path<Station*>*> paths;
};

#endif

