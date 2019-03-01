#ifndef SUBWAY_H
#define SUBWAY_H

#include "Transport.h"
class Subway :
	public Transport
{
public:
	static Subway* getInstance();
	~Subway();
protected:
	Subway();
};

#endif
