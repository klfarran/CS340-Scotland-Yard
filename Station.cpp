
	#include <iostream>
	#include <cstdarg>
	
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
	
	void Station::setEdges(int numArgs, ...) {
		va_list args; //list to hold all the arguments
		va_start(args, numArgs); //Initialize va_list with numArgs size
		
		for(int i = 0; i < numArgs; i++) { //for all args (variable number of args)
			Edge cur = va_arg(args, Edge); //retrieve an edge from the list of args
			edges.push_back(cur); //add this edge to the data member list of edges 
		}
		
		va_end(args);		
	}