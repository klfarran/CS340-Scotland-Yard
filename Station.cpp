
	#include <iostream>
	#include <vector>
	
	#include "Edge.h"
	#include "Station.h"
	
	using namespace std;


	//contructors
	Station::Station(int inStationNumber, vector<Edge> inEdges){
		stationNumber = inStationNumber;
		edges = inEdges;
	}
	
	//copy constructor
	Station::Station(const Station& other) {
		stationNumber = other.stationNumber;
		edges = other.edges;
	}
	
	//default constructor
	Station::Station() {
		stationNumber = -1;
		edges = {};
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
	
	vector<Edge> Station::getEdges() const {
		return edges;
	}
	
	int Station::getNumEdges() const {
		return edges.size();
	}
	
	void Station::setEdges(vector<Edge> inEdges) {
		edges = inEdges;	
	}


	//returns a vector of ints which are the station numbers of the stations which are adjacent to the station object the 
		//function is called on
	vector<int>Station::getAllAdjacentStations(vector<int> locations, int taxiTickets, int busTickets, int undTickets) {
		vector<int> adjacents;
		bool isOpen;
	
		//for each edge of this station (that connects to a neighbor station)
		for(int i = 0; i < edges.size(); i++) {
			isOpen = true; //for each destination station, we start by assuming that its "open" (there are no detectives already there)
			//for each station that a detective currently occupies 
			for(int j = 0; j < locations.size(); j++) {
				
				if(locations[j] == edges[i].getPointB()) //if there is a detective at this possible destination station, its not "open" to be moved to 
					isOpen = false; //so this station is not "open"
			}
			if(isOpen) { //this next station is not currently occupied by any player 
				//check to see if we have a ticket to get there 
				int transport = edges[i].getTransport();
				
				if(transport == 1 && taxiTickets > 0 || transport == 2 && busTickets > 0 || transport == 3 && (taxiTickets > 0 || busTickets > 0)
				|| transport == 4 && undTickets > 0 || transport == 6 && (busTickets > 0 || undTickets > 0)) 
					adjacents.push_back(edges[i].getPointB()); //destination station from our station cur
			}
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
	
	//returns true if the station other is 'equal' to the current station, meaning that it has the 
	//same station number as the current station; otherwise, return false 
	bool Station::equals(Station other) {
		//because all stations have a unique station number, we can distinguish station using only their station number
		return stationNumber == other.getStationNum();
	}
	
	// Returns vector of all transport types between two stations
	vector<int> Station::getAllTransportTypesTo(Station adjacent) const {
		vector<int> transportTypes;
		vector<Edge> edges = getEdges();
		for (Edge edge : edges) {
			if (edge.getPointB() == adjacent.getStationNum()) {
				transportTypes.push_back(edge.getTransport());
			}
		}
		return transportTypes;
	}