//Main program for Scotland Yard AI Group Project
//Kelly Farran, Kennedy Watkins, Emmet Ritchie 
//CS340 Fall 2024

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "Edge.h"
#include "Station.h"
#include "GameManager.h"

using namespace std;


	//helper function which returns true if the Station 'chosen' is present in the list of Stations 'drawn', false if not
	bool contains(vector<Station> drawn, Station chosen) {
		for(int i = 0; i < drawn.size(); i++) {
			if(drawn[i].equals(chosen))
				return true;
		}
		
		
		return false;
	}
	
	//helper function to pick a random station from possibleStarts, the vector of possible start stations, making sure that that 
	//station has not already been drawn/ chosen for another player to start at
	Station draw(vector<Station> possibleStarts, vector<Station>& drawn) {
			int random = rand() %18; //random number between 0 and 17
			Station chosen = possibleStarts[random];
		while(contains(drawn, chosen)) {
			srand(time(0)); //seed random number generator using current time(required to not get the same sequence of random numbers)
			random = rand() %18; //new random number between 0 and 17
			chosen = possibleStarts[random]; //new random station
		   }
			//once we get here, we've chosen a station that is not present in the list of station which have already been 'drawn', so remember it and return it
				drawn.push_back(chosen);
				return chosen;
		}


int main() {


    //Create an edge that can be traversed by all transport types
    //Edge edge2(8, 19, TAXI);
 
	//edge1.display();
    //edge2.display();
	
	//initialize the game board
	GameManager gameManager;
	vector<Station> board = gameManager.initializeBoard();
	
	//print out the game board if necessary for debugging: 
	/*
	for(int i = 0; i < board.size(); i++) {
		board[i].displayStationInfo();
	}
	*/
	
	//initialize all possible start stations
	//these numbers are from the 18 starting position cards from the game 
	//each one is the station number MINUS ONE, because the stations start with station number 1, so 
	//board[0] is the station with station number 1, board[1] station with station number 2,...
	vector<Station> possibleStarts;
	possibleStarts.push_back(board[13-1]);
	possibleStarts.push_back(board[26-1]);
	possibleStarts.push_back(board[29-1]);
	possibleStarts.push_back(board[34-1]);
	possibleStarts.push_back(board[50-1]);
	possibleStarts.push_back(board[53-1]);
	possibleStarts.push_back(board[91-1]);
	possibleStarts.push_back(board[94-1]);
	possibleStarts.push_back(board[103-1]);
	possibleStarts.push_back(board[112-1]);
	possibleStarts.push_back(board[117-1]);
	possibleStarts.push_back(board[132-1]);
	possibleStarts.push_back(board[138-1]);
	possibleStarts.push_back(board[141-1]);
	possibleStarts.push_back(board[155-1]);
	possibleStarts.push_back(board[174-1]);
	possibleStarts.push_back(board[197-1]);
	possibleStarts.push_back(board[198-1]);


	vector<Station> drawn; //keeps track of the start stations which already have players placed on them/ have already been 'drawn'/ chosen
							//so that we don't start another player at the same station as someone else 
	

	//initialize mrX
	Station xStartStation = draw(possibleStarts, drawn); //get startStation from "drawing a card"
	Player mrX(true, &xStartStation);
	
	//set all of mrX's tickets 
	//because mrX 'gets' the used tickets of the detectives, we can either initialize these to be 'infinite' (super large numbers) or
	//in the game loop, when a player uses a ticket, we can set mrX's tickets again (adding the used ticket from the player)
	mrX.setTaxiTickets(4);
	mrX.setBusTickets(3);
	mrX.setSubwayTickets(3);
	mrX.setDoubleMoves(2);
	mrX.setBlackTickets(5); //number of black tickets for mrX = number of detectives there are
	//no such thing as boat tickets- need to change player class to reflect 
	
	//initialize detectives (there are 5)
	vector<Player> detectives;

	Station d1StartStation = draw(possibleStarts, drawn);
	Player detective1(false, &d1StartStation);
	detectives.push_back(detective1);
	
	Station d2StartStation = draw(possibleStarts, drawn);
	Player detective2(false, &d2StartStation);
	detectives.push_back(detective2);
	
	Station d3StartStation = draw(possibleStarts, drawn);
	Player detective3(false, &d3StartStation);
	detectives.push_back(detective3);
	
	Station d4StartStation = draw(possibleStarts, drawn);
	Player detective4(false, &d4StartStation);
	detectives.push_back(detective4);
	
	Station d5StartStation = draw(possibleStarts, drawn);
	Player detective5(false, &d5StartStation);
	detectives.push_back(detective5);
	
	//set all of the tickets for the detectives with the appropriate starting amounts 
	for(int i = 0; i < detectives.size(); i++) {
		detectives[i].setTaxiTickets(10);
		detectives[i].setBusTickets(8);
		detectives[i].setSubwayTickets(4);
	}
	
	
	//start the game 
	gameManager.gameLoop(mrX, detectives, board);
	
}
	


