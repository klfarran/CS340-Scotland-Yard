	#ifndef STATION_H
	#define STATION_H
	#include <iostream>
	#include <vector>
	
	#include "Edge.h"

using namespace std;


class Station {
	
	public:
		//contructor
		Station(int inStationNumber, vector<Edge> inEdges);
		
		//methods
		int getStationNum();
		void displayStationInfo();
		void setEdges(vector<Edge> inEdges);
		vector<int> getAllAdjacentStations(vector<int> locations);
		vector<int> getNextStations(TransportType T);
	
	private: 
		int stationNumber;
		vector<Edge> edges;
	
};

#endif
