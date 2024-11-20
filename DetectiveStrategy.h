#ifndef DETECTIVESTRATEGY_H
#define DETECTIVESTRATEGY_H

#include "TreeNode.h"
#include "Player.h"
#include "Station.h"

class DetectiveStrategy {
private:
    vector<Player> detectives;

public:
    // Constructor
    DetectiveStrategy(vector<Player> detectives);

    // Getters
	vector<Player> getDetectives(); //return vector of all 5 detectives (so that main can start the game loop)
    

    // Methods
	int shortestPath(Player detective, Station start, Station end);
	Station chooseOptimalDetectiveMove(Player detective, TreeNode potentialMrXLocations);
	Station breakTie(vector<Station> destinations);
	void detectiveGreedyMove();
	vector<Edge> pathToClosestSubway(Station start, int moves);
	vector<Station> getReachableStations(Station start, int movesRemaining);
	int distanceToPotentialMrX();
	int chooseBestTicket(Player detective, vector<int> availableTransports);
	
};


#endif
