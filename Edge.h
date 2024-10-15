#ifndef EDGE_H
#define EDGE_H
#include <iostream>

enum TransportType {
    TAXI = 1,          
    BUS = 2,           
    UNDERGROUND = 4,   
	RIVER = 8; 
    
};


class Edge {
private: 
	int PointA;
	int PointB;
	int Transport;
	
public:

	Edge(int start, int end, int trans);
	
	int getPointA();
	int getPointB();
	
	bool hasTransportType(TransportType t);
	//what transport is legal
	
	//show what transport is for each edge
	void display();
};


//how will the input be typed in to move a piece? 

//how to check for legal transport type input

#endif