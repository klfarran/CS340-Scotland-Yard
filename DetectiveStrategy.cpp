
	#include "DetectiveStrategy.h"
	#include <limits.h> //for INT_MAX
	
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
	
	//Uses shortestPath and loops through mr. x’s potential locations and 
	//selects the location with the minimal distance for the detective 'detective'
	Station DetectiveStrategy::chooseOptimalDetectiveMove(Player detective, TreeNode potentialMrXLocations) {
		//leaves of the tree of potential mrX locations are the current potential mrx locations- get them 
		vector<TreeNode> locations; 
		potentialMrXLocations.getLeaves(potentialMrXLocations, locations); //locations is updated by reference to contain the leaves 
		
		int shortestPath = INT_MAX; //current shortest path found
		int curPath;  //current path we're working with 
		Station* closestStation; 
		Station* detectiveStation = detective.getCurrentStation();
	
		for(TreeNode curPotentialLoc : locations) {
			Station* curPotStation = curPotentialLoc.getStation();
			curPath = this->shortestPath(detective, *detectiveStation, *curPotStation);
			if(curPath < shortestPath) {
				shortestPath = curPath;
				closestStation = curPotStation;
			}
		}		
	}
	
	//If multiple detectives have the same choices for where to go, choose a destination 
	//station that benefits the whole team by spreading detectives to cover more of mr. x’s potential moves
	Station DetectiveStrategy::breakTie(vector<Station> destinations) {		
		vector<Edge> edges;
		return Station(0, edges);
	}
	
	void DetectiveStrategy::detectiveGreedyMove() {
		//Execute moves based off of optimal move and tie breaking
	}
	
	//Returns a vector<Edge> which is the path to the nearest subway station that the detective can reach in 'moves' number of moves
	//'moves' is the number of moves before mr. x shows up
	//'start' is the current station of the detective 
	//TO-DO: in GameManager, need to create function getSubwayStations(vector<Station> board) to be able to pass the subway stations to this function 
	//subway stations: 1, 46, 74, 93, 79, 111, 163, 153, 140, 185, 159, 13, 67, 89
	vector<Edge> DetectiveStrategy::pathToClosestSubway(Player detective, int moves, vector<Station> subwayStations) {
				
			int shortestPath = INT_MAX;	
			int curPath;
			Station* closestSubStation;
			Station* detectiveStation = detective.getCurrentStation();
			
			//call shortestPath between start and each subway station to see if any subway station is reachable in under 'moves' # of moves 
			for(Station curSubStation : subwayStations) {
				curPath = this->shortestPath(detective, *detectiveStation, curSubStation);
				if(curPath < shortestPath && curPath < moves) {//path is shorter than current shortest path AND less than 'moves' # of moves
					shortestPath = curPath;
					closestSubStation = &curSubStation;
				}
			}			
		
		//TO-DO: we have closestSubwayStation, now we need to get the path to it and return it
		vector<Edge> edges;
			return edges;

		if(shortestPath == INT_MAX) { //no path to any subway station is < moves, return empty vector	
			vector<Edge> edges;
			return edges;
		}
	}
	
	vector<Station> DetectiveStrategy::getReachableStations(Station start, int movesRemaining) {
		//Return all stations a detective can reach in a certain number of moves, like pathToClosestSubway but more general
		vector<Station> stations;
		return stations;
	}
	
	int DetectiveStrategy::distanceToPotentialMrX() {
		//For each detective, find distances to potential mr. x locations based off the tree of possible mr. x moves for greedy strategy
		return 0;
	}
	
	int DetectiveStrategy::chooseBestTicket(Player detective, vector<int> availableTransports) {
		//Returns highest priority transport types to a given station, like maybe we want to use buses first and save taxis and save subways
		return 0;
	}
	