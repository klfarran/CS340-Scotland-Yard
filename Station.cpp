#include "Station.h"
#include <iostream>
using namespace std;


//contructor
Station::Station(int inStationNumber, vector<Edge> inEdges){
	stationNumber = inStationNumber;
	edges = inEdges;
}


