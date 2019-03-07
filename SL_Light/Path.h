#ifndef PATH_H
#define PATH_H

#include "TimeTable.h"

template <typename T>
struct Path
{
/**
 * Path represents one way edges between vertices in the graph. This is a template class that is used by vertices to find other vertices on the other side of said edge. This class 
 * uses one parameter station which is the vertice on the other side of the edge. Length is used to define the weight of the edge.
 * This class is used by Station objects to define all edges/paths to other stations. 
 *
 * @param T s is the vertice on the other end of the edge, or the other station in the case of Stations.
 * @param int l is the weight of the edge or length of the path in the case of stations.
 */
	Path(T s, int l) : station(s), length(l) {}
	T station;
	int length;
	TimeTable* tt = TimeTable::getInstance();
};

#endif