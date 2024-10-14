
	#include <iostream>

	#include "GameManager.h"
	#include "Station.h"
	
	using namespace std;


	//contructor	
	GameManager::GameManager(){
		//game has to start on round 0, can't start game in middle of rounds
		round = 0; 
	}

	//function to return the number of the current round of the game 
	int GameManager::getRound(){
		return round;
	}
	
	//function to initialize the game board 
	//to be implemented
	vector<Station> GameManager::initializeBoard() {
		vector<Station> board; 
		return board;
	}
