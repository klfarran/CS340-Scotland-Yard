#include "Edge.h"
#include <iostream>
using namespace std;


//contructor
Edge::Edge(int start, int end, int trans){
	PointA = start;
	PointB = end; 
	Transport = trans;
}
// edge class, initialize data members, construct members values


int Edge::getPointA(){
	return PointA;
}

int Edge::getPointB(){
	return PointB;
}

int Edge::getTransport() {
	return Transport;
}

bool Edge:: hasTransportType(TransportType t){ //use for ifs
	return (Transport & t) !=0; //checking if transport type exists
}

//display transport
void Edge::display(){
	cout<<endl;
	cout<< "E:"<<PointA<< " - " <<PointB<< " :type- ";
	if (hasTransportType(TAXI)){
		cout << " Taxi ";
	} 
	if (hasTransportType(BUS)){
		cout << " Bus ";
	} 
	if (hasTransportType(UNDERGROUND)){
		cout << " Undergroud ";
	} 
	if (hasTransportType(RIVER)){
		cout << " River ";
	}
}