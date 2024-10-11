//Main program for Scotland Yard AI Group Project
//Kelly Farran, Kennedy Watkins, Emmet Ritchie 
//CS340 Fall 2024

#include <iostream>
#include <vector>
#include "Edge.h"
#include "GameManager.h"


using namespace std;


	int main() {
		
	Edge edge1(1, 8, TAXI | BUS);  // Combining TAXI and BUS using bitwise OR

    // Create an edge that can be traversed by all transport types
    Edge edge2(8, 19, TAXI);
 
	edge1.display();
    edge2.display();
	}