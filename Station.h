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
		vector<Edge> getEdges();
		void setEdges(vector<Edge> inEdges);
		vector<int> getAllAdjacentStations(vector<int> locations, int taxiTickets, int busTickets, int undTickets);
		vector<int> getNextStations(TransportType T);
		bool equals(Station other);
		vector<int> getAllTransportTypesTo(Station adjacent) const;
	
	private: 
		int stationNumber;
		vector<Edge> edges;
	
};

#endif
