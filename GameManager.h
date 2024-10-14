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
		
	
	private: 
		int round;
	
};

#endif

