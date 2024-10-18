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
		void setEdges(vector<Edge> inEdges);
		vector<int> getAllAdjacentStations();
		vector<int> getNextStations(TransportType T);
	
	private: 
		int stationNumber;
		vector<Edge> edges;
	
};

#endif
