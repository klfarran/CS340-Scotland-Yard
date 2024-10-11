#include "GameManager.h"
#include <iostream>
using namespace std;


//contructor
GameManager::GameManager(){
	//game has to start on round 0, can't start game in middle of rounds
	round = 0; 
}


int GameManager::getRound(){
	return round;
}
