
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
	
	void Station::displayStationInfo(){
		cout << "Station number: " << stationNumber << " with edges: \n";
		for(int i = 0; i < edges.size(); i ++) {
			cout << edges[i].display() << endl;
		}
	}