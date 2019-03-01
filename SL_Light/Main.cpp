#include "TransportGraph.h"
#include "Subway.h"

int main(int argc, char** argv)
{
	tg.addStation("T-Centralen", 15621, 2153);
	tg.addStation("Slussen", 23632, 1251);
	tg.addStation("Mariatorget", 12612, 235);
	tg.addStation("Uppsala", 136, 3631);
	tg.addStation("Kista", 1111, 2222);

	tg.getStation("T-Centralen")->addPath(42224, tg.getStation("Uppsala"));
	tg.getStation("T-Centralen")->addPath(58645, tg.getStation("Kista"));
	tg.getStation("Kista")->addPath(15125, tg.getStation("Slussen"));
	tg.getStation("Kista")->addPath(63365, tg.getStation("Mariatorget"));
	tg.getStation("Slussen")->addPath(52225, tg.getStation("Mariatorget"));
	tg.getStation("Uppsala")->addPath(64674, tg.getStation("Mariatorget"));
	tg.getStation("Uppsala")->addPath(42224, tg.getStation("T-Centralen"));
	tg.getStation("Kista")->addPath(58645, tg.getStation("T-Centralen"));
	tg.getStation("Slussen")->addPath(15125, tg.getStation("Kista"));
	tg.getStation("Mariatorget")->addPath(63365, tg.getStation("Kista"));
	tg.getStation("Mariatorget")->addPath(52225, tg.getStation("Slussen"));
	tg.getStation("Mariatorget")->addPath(64674, tg.getStation("Uppsala"));

	Subway* sub = Subway::getInstance();

	tg.getStation("T-Centralen")->getPath("Uppsala")->tt->addDeparture(10, sub, tg.getStation("T-Centralen")->getPath("Uppsala")->length);
	tg.getStation("T-Centralen")->getPath("Uppsala")->tt->addDeparture(20, sub, tg.getStation("T-Centralen")->getPath("Uppsala")->length);
	tg.getStation("T-Centralen")->getPath("Uppsala")->tt->addDeparture(30, sub, tg.getStation("T-Centralen")->getPath("Uppsala")->length);
	tg.getStation("T-Centralen")->getPath("Uppsala")->tt->addDeparture(40, sub, tg.getStation("T-Centralen")->getPath("Uppsala")->length);
	tg.getStation("T-Centralen")->getPath("Uppsala")->tt->addDeparture(50, sub, tg.getStation("T-Centralen")->getPath("Uppsala")->length);
	tg.getStation("T-Centralen")->getPath("Uppsala")->tt->addDeparture(60, sub, tg.getStation("T-Centralen")->getPath("Uppsala")->length);
	tg.getStation("Uppsala")->getPath("T-Centralen")->tt->addDeparture(10, sub, tg.getStation("Uppsala")->getPath("T-Centralen")->length);
	tg.getStation("Uppsala")->getPath("T-Centralen")->tt->addDeparture(20, sub, tg.getStation("Uppsala")->getPath("T-Centralen")->length);
	tg.getStation("Uppsala")->getPath("T-Centralen")->tt->addDeparture(30, sub, tg.getStation("Uppsala")->getPath("T-Centralen")->length);
	tg.getStation("Uppsala")->getPath("T-Centralen")->tt->addDeparture(40, sub, tg.getStation("Uppsala")->getPath("T-Centralen")->length);
	tg.getStation("Uppsala")->getPath("T-Centralen")->tt->addDeparture(50, sub, tg.getStation("Uppsala")->getPath("T-Centralen")->length);
	tg.getStation("Uppsala")->getPath("T-Centralen")->tt->addDeparture(60, sub, tg.getStation("Uppsala")->getPath("T-Centralen")->length);
	tg.getStation("T-Centralen")->getPath("Kista")->tt->addDeparture(5, sub, tg.getStation("T-Centralen")->getPath("Kista")->length);
	tg.getStation("T-Centralen")->getPath("Kista")->tt->addDeparture(15, sub, tg.getStation("T-Centralen")->getPath("Kista")->length);
	tg.getStation("T-Centralen")->getPath("Kista")->tt->addDeparture(25, sub, tg.getStation("T-Centralen")->getPath("Kista")->length);
	tg.getStation("T-Centralen")->getPath("Kista")->tt->addDeparture(35, sub, tg.getStation("T-Centralen")->getPath("Kista")->length);
	tg.getStation("T-Centralen")->getPath("Kista")->tt->addDeparture(45, sub, tg.getStation("T-Centralen")->getPath("Kista")->length);
	tg.getStation("T-Centralen")->getPath("Kista")->tt->addDeparture(55, sub, tg.getStation("T-Centralen")->getPath("Kista")->length);
	tg.getStation("Kista")->getPath("T-Centralen")->tt->addDeparture(5, sub, tg.getStation("Kista")->getPath("T-Centralen")->length);
	tg.getStation("Kista")->getPath("T-Centralen")->tt->addDeparture(15, sub, tg.getStation("Kista")->getPath("T-Centralen")->length);
	tg.getStation("Kista")->getPath("T-Centralen")->tt->addDeparture(25, sub, tg.getStation("Kista")->getPath("T-Centralen")->length);
	tg.getStation("Kista")->getPath("T-Centralen")->tt->addDeparture(35, sub, tg.getStation("Kista")->getPath("T-Centralen")->length);
	tg.getStation("Kista")->getPath("T-Centralen")->tt->addDeparture(45, sub, tg.getStation("Kista")->getPath("T-Centralen")->length);
	tg.getStation("Kista")->getPath("T-Centralen")->tt->addDeparture(55, sub, tg.getStation("Kista")->getPath("T-Centralen")->length);
	tg.getStation("Kista")->getPath("Slussen")->tt->addDeparture(1, sub, tg.getStation("Kista")->getPath("Slussen")->length);
	tg.getStation("Kista")->getPath("Slussen")->tt->addDeparture(11, sub, tg.getStation("Kista")->getPath("Slussen")->length);
	tg.getStation("Kista")->getPath("Slussen")->tt->addDeparture(21, sub, tg.getStation("Kista")->getPath("Slussen")->length);
	tg.getStation("Kista")->getPath("Slussen")->tt->addDeparture(31, sub, tg.getStation("Kista")->getPath("Slussen")->length);
	tg.getStation("Kista")->getPath("Slussen")->tt->addDeparture(41, sub, tg.getStation("Kista")->getPath("Slussen")->length);
	tg.getStation("Kista")->getPath("Slussen")->tt->addDeparture(51, sub, tg.getStation("Kista")->getPath("Slussen")->length);
	tg.getStation("Kista")->getPath("Slussen")->tt->addDeparture(61, sub, tg.getStation("Kista")->getPath("Slussen")->length);
	tg.getStation("Slussen")->getPath("Kista")->tt->addDeparture(1, sub, tg.getStation("Slussen")->getPath("Kista")->length);
	tg.getStation("Slussen")->getPath("Kista")->tt->addDeparture(11, sub, tg.getStation("Slussen")->getPath("Kista")->length);
	tg.getStation("Slussen")->getPath("Kista")->tt->addDeparture(21, sub, tg.getStation("Slussen")->getPath("Kista")->length);
	tg.getStation("Slussen")->getPath("Kista")->tt->addDeparture(31, sub, tg.getStation("Slussen")->getPath("Kista")->length);
	tg.getStation("Slussen")->getPath("Kista")->tt->addDeparture(41, sub, tg.getStation("Slussen")->getPath("Kista")->length);
	tg.getStation("Slussen")->getPath("Kista")->tt->addDeparture(51, sub, tg.getStation("Slussen")->getPath("Kista")->length);
	tg.getStation("Mariatorget")->getPath("Kista")->tt->addDeparture(7, sub, tg.getStation("Mariatorget")->getPath("Kista")->length);
	tg.getStation("Mariatorget")->getPath("Kista")->tt->addDeparture(17, sub, tg.getStation("Mariatorget")->getPath("Kista")->length);
	tg.getStation("Mariatorget")->getPath("Kista")->tt->addDeparture(27, sub, tg.getStation("Mariatorget")->getPath("Kista")->length);
	tg.getStation("Mariatorget")->getPath("Kista")->tt->addDeparture(37, sub, tg.getStation("Mariatorget")->getPath("Kista")->length);
	tg.getStation("Mariatorget")->getPath("Kista")->tt->addDeparture(47, sub, tg.getStation("Mariatorget")->getPath("Kista")->length);
	tg.getStation("Mariatorget")->getPath("Kista")->tt->addDeparture(57, sub, tg.getStation("Mariatorget")->getPath("Kista")->length);
	tg.getStation("Kista")->getPath("Mariatorget")->tt->addDeparture(7, sub, tg.getStation("Kista")->getPath("Mariatorget")->length);
	tg.getStation("Kista")->getPath("Mariatorget")->tt->addDeparture(17, sub, tg.getStation("Kista")->getPath("Mariatorget")->length);
	tg.getStation("Kista")->getPath("Mariatorget")->tt->addDeparture(27, sub, tg.getStation("Kista")->getPath("Mariatorget")->length);
	tg.getStation("Kista")->getPath("Mariatorget")->tt->addDeparture(37, sub, tg.getStation("Kista")->getPath("Mariatorget")->length);
	tg.getStation("Kista")->getPath("Mariatorget")->tt->addDeparture(47, sub, tg.getStation("Kista")->getPath("Mariatorget")->length);
	tg.getStation("Kista")->getPath("Mariatorget")->tt->addDeparture(57, sub, tg.getStation("Kista")->getPath("Mariatorget")->length);
	tg.getStation("Mariatorget")->getPath("Slussen")->tt->addDeparture(8, sub, tg.getStation("Mariatorget")->getPath("Slussen")->length);
	tg.getStation("Mariatorget")->getPath("Slussen")->tt->addDeparture(18, sub, tg.getStation("Mariatorget")->getPath("Slussen")->length);
	tg.getStation("Mariatorget")->getPath("Slussen")->tt->addDeparture(28, sub, tg.getStation("Mariatorget")->getPath("Slussen")->length);
	tg.getStation("Mariatorget")->getPath("Slussen")->tt->addDeparture(38, sub, tg.getStation("Mariatorget")->getPath("Slussen")->length);
	tg.getStation("Mariatorget")->getPath("Slussen")->tt->addDeparture(48, sub, tg.getStation("Mariatorget")->getPath("Slussen")->length);
	tg.getStation("Mariatorget")->getPath("Slussen")->tt->addDeparture(58, sub, tg.getStation("Mariatorget")->getPath("Slussen")->length);
	tg.getStation("Slussen")->getPath("Mariatorget")->tt->addDeparture(8, sub, tg.getStation("Slussen")->getPath("Mariatorget")->length);
	tg.getStation("Slussen")->getPath("Mariatorget")->tt->addDeparture(18, sub, tg.getStation("Slussen")->getPath("Mariatorget")->length);
	tg.getStation("Slussen")->getPath("Mariatorget")->tt->addDeparture(28, sub, tg.getStation("Slussen")->getPath("Mariatorget")->length);
	tg.getStation("Slussen")->getPath("Mariatorget")->tt->addDeparture(38, sub, tg.getStation("Slussen")->getPath("Mariatorget")->length);
	tg.getStation("Slussen")->getPath("Mariatorget")->tt->addDeparture(48, sub, tg.getStation("Slussen")->getPath("Mariatorget")->length);
	tg.getStation("Slussen")->getPath("Mariatorget")->tt->addDeparture(58, sub, tg.getStation("Slussen")->getPath("Mariatorget")->length);
	tg.getStation("Mariatorget")->getPath("Uppsala")->tt->addDeparture(6, sub, tg.getStation("Mariatorget")->getPath("Uppsala")->length);
	tg.getStation("Mariatorget")->getPath("Uppsala")->tt->addDeparture(16, sub, tg.getStation("Mariatorget")->getPath("Uppsala")->length);
	tg.getStation("Mariatorget")->getPath("Uppsala")->tt->addDeparture(26, sub, tg.getStation("Mariatorget")->getPath("Uppsala")->length);
	tg.getStation("Mariatorget")->getPath("Uppsala")->tt->addDeparture(36, sub, tg.getStation("Mariatorget")->getPath("Uppsala")->length);
	tg.getStation("Mariatorget")->getPath("Uppsala")->tt->addDeparture(46, sub, tg.getStation("Mariatorget")->getPath("Uppsala")->length);
	tg.getStation("Mariatorget")->getPath("Uppsala")->tt->addDeparture(56, sub, tg.getStation("Mariatorget")->getPath("Uppsala")->length);
	tg.getStation("Uppsala")->getPath("Mariatorget")->tt->addDeparture(6, sub, tg.getStation("Uppsala")->getPath("Mariatorget")->length);
	tg.getStation("Uppsala")->getPath("Mariatorget")->tt->addDeparture(16, sub, tg.getStation("Uppsala")->getPath("Mariatorget")->length);
	tg.getStation("Uppsala")->getPath("Mariatorget")->tt->addDeparture(26, sub, tg.getStation("Uppsala")->getPath("Mariatorget")->length);
	tg.getStation("Uppsala")->getPath("Mariatorget")->tt->addDeparture(36, sub, tg.getStation("Uppsala")->getPath("Mariatorget")->length);
	tg.getStation("Uppsala")->getPath("Mariatorget")->tt->addDeparture(46, sub, tg.getStation("Uppsala")->getPath("Mariatorget")->length);
	tg.getStation("Uppsala")->getPath("Mariatorget")->tt->addDeparture(56, sub, tg.getStation("Uppsala")->getPath("Mariatorget")->length);

	tg.aStar(tg.getStation("Slussen"), tg.getStation("Uppsala"), 1);

	return 0;
}