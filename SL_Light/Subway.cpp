#include "Subway.h"



Subway::Subway() : Transport(100)
{
}


Subway * Subway::getInstance()
{
	return new Subway();
}

Subway::~Subway()
{
}
