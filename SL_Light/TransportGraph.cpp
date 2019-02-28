#include "TransportGraph.h"
#include "Path.h"
#include <queue>
#define INFINITY -1


TransportGraph::TransportGraph()
{
	
}

void TransportGraph::aStar(Station* start, Station* end)
{

	std::priority_queue<Station*, std::greater<Station*>> pq;

	for (Station* s : stations) {
		s->timeAway = INFINITY;
		s->known = false;
	}

	start->timeAway = 0;

	pq.push(start);

	while (end->timeAway == INFINITY) {
		Station* s = pq.pop;
		s->known = true;

		for (Path* p : s->getPath()) {
			if (!p->station->known) {
				int distance = p->length + std::abs(*p->station->getPosition() - *end->getPosition()); //måste räkna in tid, (längd / hastighet) * 60
				if (p->station->timeAway == INFINITY || s->timeAway + distance < p->station->timeAway) {
					if (p->station->timeAway == INFINITY)
						pq.push(p->station);
					p->station->timeAway = s->timeAway + distance;
					p->station->previous = s;
				}
			}
		}
	}
}


TransportGraph::~TransportGraph()
{
}
