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
#include "DetectiveStrategy.h"

using namespace std;


	//helper function which returns true if the Station number'chosen' is present in the list of Station numbers 'drawn', false if not
	bool contains(vector<int> drawn, int chosen) {
		for(int i = 0; i < drawn.size(); i++) {
			if(drawn[i] == chosen)
				return true;
		}
		
		
		return false;
	}
	
	//helper function to pick a random station number from possibleStarts, the vector of possible start station numbers, making sure that that 
	//station number has not already been drawn/ chosen for another player to start at
	int draw(vector<int> possibleStarts, vector<int>& drawn) {
			int random = rand() %18; //random number between 0 and 17
			int chosen = possibleStarts[random];
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
	
	//initialize the game board
	GameManager gameManager;
	vector<Station> board = gameManager.initializeBoard();
	
	//initialize all possible start stations
	//these numbers are from the 18 starting position cards from the game 

	vector<int> possibleStarts = {13, 26, 29, 34, 50, 53, 91, 94, 103, 112, 117, 132, 138, 141, 155, 174, 197, 198};
	

	vector<int> drawn; //keeps track of the start stations which already have players placed on them/ have already been 'drawn'/ chosen
							//so that we don't start another player at the same station as someone else 
	
	//initialize mrX
    //get start Station number from "drawing a card"
	Player mrX(true, draw(possibleStarts, drawn));
	
	
	//initialize detectives (there are 5)
	vector<Player> detectives;

	Player detective1(false, draw(possibleStarts, drawn));
	detectives.push_back(detective1);
	
	Player detective2(false, draw(possibleStarts, drawn));
	detectives.push_back(detective2);
	
	Player detective3(false, draw(possibleStarts, drawn));
	detectives.push_back(detective3);
	
	Player detective4(false, draw(possibleStarts, drawn));
	detectives.push_back(detective4);
	
	Player detective5(false, draw(possibleStarts, drawn));
	detectives.push_back(detective5);
	
	
	//start the game 
	gameManager.gameLoop(mrX, detectives, board);
	
}
	


