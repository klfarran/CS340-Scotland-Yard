
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
	
	vector<Edge> Station::getEdges() {
		return edges;
	}
	
	void Station::setEdges(vector<Edge> inEdges) {
		edges = inEdges;	
	}


	//returns a vector of ints which are the station numbers of the stations which are adjacent to the station object the 
		//function is called on, regardless of transportation method 
	vector<int>Station::getAllAdjacentStations(vector<int> locations) {
		vector<int> adjacents;
		bool isOpen;
		for(int i = 0; i < edges.size(); i++) {
			isOpen = true; //for each destination station, we start by assuming that its "open" (there are no detectives already there)
			for(int j = 0; j < locations.size(); j++) {
				if(locations[j] == (edges[i].getPointB())) //our (current) destination station is the same as some station that a detective is at
					isOpen = false; //so this station is not "open"
			}
			
			if(isOpen) //this next station is not currently occupied by any player 
		   adjacents.push_back(edges[i].getPointB()); //destination station from our station cur
		}
		
	   return adjacents;
	}

	//returns all the stations adjacent to the current station only of transportation type t 
	vector<int> Station::getNextStations(TransportType t){
		vector<int> adjacents;
		for(int i = 0; i < edges.size(); i++) {
		    if(edges[i].hasTransportType(t))
		     adjacents.push_back(edges[i].getPointB());
		}

	    return adjacents;
	}
	
	bool Station::equals(Station other) {
		
		if(edges.size() != other.getEdges().size() || stationNumber != other.getStationNum())
			return false; 
		else  {//check every edge coming out of both stations to be equal (or not)
		
			for(int i = 0; i < edges.size(); i++) { //edges and other.getEdges are the same size because we passed our check above
				if(edges[i].getPointA() == other.getEdges()[i].getPointA() && edges[i].getPointB() == other.getEdges()[i].getPointB() && edges[i].getTransport() == other.getEdges()[i].getTransport())
					return false;
			}
			return true; //passes all checks 
		}
	
	}
	