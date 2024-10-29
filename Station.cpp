
	#include <iostream>
	#include <vector>
	
	#include "Edge.h"
	#include "Station.h"
	
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
		cout << "\nStation number: " << stationNumber << " with edges:";
		for(int i = 0; i < edges.size(); i ++) {
			edges[i].display();
		}
		cout << endl;
	}
	
	void Station::setEdges(vector<Edge> inEdges) {
		edges = inEdges;	
	}


	//returns a vector of ints which are the station numbers of the stations which are adjacent to the station object the 
		//function is called on
	vector<int>Station::getAllAdjacentStations() {
		vector<int> adjacents;
		for(int i = 0; i < edges.size(); i++) {
		   adjacents.push_back(edges[i].getPointB()); //destination station from our station cur
		}
		
	   return adjacents;
	}

	//returns all the stations adjacent to the current station, regardless of transportation type 
	vector<int> Station::getNextStations(TransportType t){
		vector<int> adjacents;
		for(int i = 0; i < edges.size(); i++) {
		    if(edges[i].hasTransportType(t))
		     adjacents.push_back(edges[i].getPointB());
		}

	    return adjacents;
	}
	