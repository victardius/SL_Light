#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <unordered_map>

class TimeTable
{
public:
	static TimeTable* getInstance();
	~TimeTable();
protected:
	TimeTable();
private:
	//std::unordered_map<std::pair<Station*, Station*>, int> paths;
};

#endif

