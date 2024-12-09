	#ifndef GAMEMANAGER_H
	#define GAMEMANAGER_H
	#include <iostream>
	#include <vector>
	
	#include "Station.h"
	#include "Player.h"
	#include "TreeNode.h"

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
		TreeNode Build_Tree(Station station, vector<Station>& board, Player& mrX, vector<Player> detectives);
		void AddNextPossibleMrXLocations(TreeNode possibleMrXLocations, vector<Station>& board, Player& mrX, vector<Player>& detectives);
		void printAvailalbeTransportTypes(vector<int> availTransportTypes);
		
	
	private: 
		int round;
	
};

#endif

