#include "TimeTable.h"



TimeTable::TimeTable()
{
}


TimeTable * TimeTable::getInstance()
{
	return new TimeTable();
}

TimeTable::~TimeTable()
{
}
