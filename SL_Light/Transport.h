#ifndef TRANSPORT_H
#define TRANSPORT_H

class Transport
{
public:
	const static int getTopSpeed();
	virtual int getSpeed();
	void setTimeTable();
protected:
	Transport(int s);
	virtual ~Transport();
private:
	int speed;
};

static int topSpeed = 0;

#endif

