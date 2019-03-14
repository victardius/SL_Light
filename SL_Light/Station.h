#ifndef STATION_H
#define STATION_H

#include "Coordinate.h"
#include "Transport.h"
#include "Path.h"
#include "TimeTable.h"
#include <unordered_map>
#include <vector>
#include <string>

#define INFINITY 999999999

class Station
{
public:
	static Station* getInstance(std::string name, int x, int y);
	Coordinate* getPosition();
	void addPath(int distance, Station*);
	std::unordered_map<std::string, Path<Station*>*> getPaths();
	Path<Station*>* getPath(std::string name);
	std::string getName();
	bool operator<(const Station& other);
	bool operator>(const Station& other);
	bool getKnown();
	Station* getPrevious();
	int getTimeAway();
	int getHTimeAway();
	void setKnown(bool k);
	void setPrevious(Station* s);
	void setTimeAway(int ta);
	void setHTimeAway(int hta);
	Station() {};
	~Station();
protected:
	Station(std::string name, int x, int y);
private:
	Coordinate position{ 0,0 };
	std::string name;
	int timeAway = INFINITY;
	int hTimeAway = INFINITY;
	Station* previous;
	bool known = false;
	std::unordered_map<std::string, Path<Station*>*> paths;
};

#endif

