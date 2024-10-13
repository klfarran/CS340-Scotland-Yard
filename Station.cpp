
	#include <iostream>
	
	#include "Edge.h"
	
	using namespace std;


	//contructor
	Station::Station(int inStationNumber, vector<Edge> inEdges){
		stationNumber = inStationNumber;
		edges = inEdges;
	}

	//function to return the number of the current station
	int Station::getStationNum() {
		return stationNumber;
	}