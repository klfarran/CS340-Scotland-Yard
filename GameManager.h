	#ifndef GAMEMANAGER_H
	#define GAMEMANAGER_H
	#include <iostream>
	#include <vector>
	
	#include "Station.h"

using namespace std;

class GameManager {
	public:
		int getRound();
		vector<Station> initializeBoard();
		void gameLoop(Player& mrX, vector<Player>& detectives, vector<Station>& board);
		
	
	private: 
		int round;
	
};

#endif

