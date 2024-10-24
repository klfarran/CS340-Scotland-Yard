//Main program for Scotland Yard AI Group Project
//Kelly Farran, Kennedy Watkins, Emmet Ritchie 
//CS340 Fall 2024

#include <iostream>
#include <vector>

#include "Edge.h"
#include "Station.h"
#include "GameManager.h"

using namespace std;


int main() {


    //Create an edge that can be traversed by all transport types
    Edge edge2(8, 19, 5);
 
	//edge1.display();
    //edge2.display();
	

	GameManager gameManager;
	vector<Station> board = gameManager.initializeBoard();
	
	for(int i = 0; i < board.size(); i++) {
		board[i].displayStationInfo();
	}
	
}
	
	

