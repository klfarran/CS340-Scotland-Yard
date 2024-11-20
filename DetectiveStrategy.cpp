
	#include "DetectiveStrategy.h"
	
	using namespace std;

	//constructor	
	DetectiveStrategy::DetectiveStrategy(vector<Player> inDetectives){
		detectives = inDetectives;
	}
	
	//return a list of all the detectives 
	vector<Player> DetectiveStrategy::getDetectives() {
		return detectives;
	}
	
	int DetectiveStrategy::shortestPath(Player detective, Station start, Station end) { 
		//Using algorithm like BFS or Dijkstra’s shortest path to calculate minimum moves 
		//between detective and mr. x’s potential locations
		return 0;
	}
	
	Station DetectiveStrategy::chooseOptimalDetectiveMove(Player detective, TreeNode potentialMrXLocations) {
		//Uses shortestPath and loops through mr. x’s potential locations and 
		//selects the location with the minimal distance for each detective
		vector<Edge> edges;
		return Station(0, edges);
	}
	
	Station DetectiveStrategy::breakTie(vector<Station> destinations) {
		//If multiple detectives have the same choices for where to go, choose a destination 
		//station that benefits the whole team by spreading detectives to cover more of mr. x’s potential moves
		vector<Edge> edges;
		return Station(0, edges);
	}
	
	void DetectiveStrategy::detectiveGreedyMove() {
		//Execute moves based off of optimal move and tie breaking
	}
	
	vector<Edge> DetectiveStrategy::pathToClosestSubway(Station start, int moves) {
		//Returns a path to the nearest subway station that the detective can reach in x 
		//number of moves, x being the number of moves before mr. x shows up

	}
	
	vector<Station> DetectiveStrategy::getReachableStations(Station start, int movesRemaining) {
		//Return all stations a detective can reach in a certain number of moves, like pathToClosestSubway but more general

	}
	
	int DetectiveStrategy::distanceToPotentialMrX() {
		//For each detective, find distances to potential mr. x locations based off the tree of possible mr. x moves for greedy strategy
	}
	
	int DetectiveStrategy::chooseBestTicket(Player detective, vector<int> availableTransports) {
		//Returns highest priority transport types to a given station, like maybe we want to use buses first and save taxis and save subways
	}
	