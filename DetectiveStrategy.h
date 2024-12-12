#ifndef DETECTIVESTRATEGY_H
#define DETECTIVESTRATEGY_H

#include "TreeNode.h"
#include "Player.h"
#include "Station.h"

class DetectiveStrategy {
private:
    vector<Player> detectives;
	void dfsHelper(int currentStationNum, int movesLeft, vector<bool>& visited, vector<Station>& reachableStations, vector<Station>& board, int& taxiTix, int& busTix, int& subwayTix);
	void performDFS(int startStation, int moves, vector<Station>& board, int taxiTix, int busTix, int subwayTix, vector<Station>& reachableStations);

public:
    // Constructor
    DetectiveStrategy(vector<Player> detectives);

    // Getters
	vector<Player> getDetectives(); //return vector of all 5 detectives (so that main can start the game loop)
    

    // Methods
	vector<int> shortestPath(Player detective, int start, int end, vector<Station> board);
	int chooseOptimalDetectiveMove(Player detective, int round, vector<int> detectiveLocations, TreeNode potentialMrXLocations, vector<int> subwayStations, vector<Station> board, vector<int> optimalPath);
	Station breakTie(vector<Station> destinations);
	void detectiveGreedyMove(vector<TreeNode> potentialMrXLocations, vector<Station> board);
	vector<int> pathToClosestSubway(Player detective, int moves, vector<int> subwayStations, vector<Station> board);
	vector<vector<Station>> getReachableStations(vector<Player>& detectives, int movesUntilReveal, vector<Station>& board);
	int distanceToPotentialMrX();
	int chooseBestTicket(Player detective, vector<int> availableTransports);
	int optimalBlindMove(Player detective, int round, vector<int> detectiveLocations, vector<int> adjacents, vector<int> subwayStations, vector<Station> board);
	void updateDetectives(vector<Player> inDetectives);
	bool contains(vector<int> stations, int station);
	
};


#endif
