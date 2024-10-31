	#ifndef GAMEMANAGER_H
	#define GAMEMANAGER_H
	#include <iostream>
	#include <vector>
	
	#include "Station.h"
	#include "Player.h"

using namespace std;

class GameManager {
	public:
		//constructor
		GameManager();
		
		//methods
		int getRound();
		vector<Station> initializeBoard();
		void gameLoop(Player& mrX, vector<Player>& detectives, vector<Station>& board);
		vector<int> getDetectiveLocations(vector<Player> detectives);
		
	
	private: 
		int round;
	
};

#endif

