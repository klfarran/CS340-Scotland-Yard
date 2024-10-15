	#ifndef STATION_H
	#define STATION_H
	#include <iostream>
	#include <vector>
	
	#include "Edge.h"

using namespace std;


class Station {
	
	public:
		int getStationNum();
		void displayStationInfo();
	
	private: 
		int stationNumber;
		vector<Edge> edges;
	
};

#endif
