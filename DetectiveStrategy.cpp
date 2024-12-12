
	#include "DetectiveStrategy.h"
	#include <limits.h> //for INT_MAX
	#include "Station.h"
	#include "Edge.h"
	#include "GameManager.h"
	#include <algorithm>
	
	using namespace std;

	//constructor	
	DetectiveStrategy::DetectiveStrategy(vector<Player> inDetectives){
		detectives = inDetectives;
	}
	
	//return a list of all the detectives 
	vector<Player> DetectiveStrategy::getDetectives() {
		return detectives;
	}
	
	// Return vector of station numbers for the shortest path from start to end
	vector<int> DetectiveStrategy::shortestPath(Player detective, Station start, Station end, vector<Station> board) { 
		// Infinity, for use in dijkstra
		const int INF = numeric_limits<int>::max();
		int totalStations = 199;

		// Get detective locations
		vector<int> detectiveLocations;
		for(const Player detective : detectives){
			detectiveLocations.push_back(detective.getCurrentStation()->getStationNum());
		}

		// Distance vector and visited array
		vector<int> distances(totalStations, INF);
		vector<bool> visited(totalStations, false);

		// Track predecessors to rebuild path later
		vector<int> predecessors(totalStations, -1);

		// Start station is distance 0
		distances[start.getStationNum() - 1] = 0;

		// Get tickets
		int taxiTix = detective.getTaxiTickets();
		int busTix = detective.getBusTickets();
		int subwayTix = detective.getSubwayTickets();

		// Find shortest path!
		for(int i = 0; i < totalStations; i++){
			// Find unvisited station with the shortest distance
			int currStation = -1;
			int minDistance = INF;
			for(int j = 0; j < totalStations; j++){
				if(!visited[j] && distances[j] < minDistance){
					minDistance = distances[j];
					currStation = j;
				}
			}

			// All reachable stations have been visited
			if(currStation == -1)
				break;
			visited[currStation] = true;

			// Get current station object?
			Station curr = board[currStation];
			// Get adjacent stations
			vector<int> adjacents = curr.getAllAdjacentStations(detectiveLocations, taxiTix, busTix, subwayTix);

			// Update distances for adjacent stations
			for(int adj : adjacents){
				Station adjStation = board[adj - 1];
				// Get all transport types from curr to adjStation
				vector<int> transportTypes = curr.getAllTransportTypesTo(adjStation);
				
				for (int transportType : transportTypes) {
					// Each transport uses one ticket
					int ticketCost = 1; 

					// Check ticket availability
					bool hasTickets = (transportType == 1 && taxiTix > 0) || (transportType == 2 && busTix > 0) || (transportType == 4 && subwayTix > 0);

					if (!hasTickets){
						// Update distances if a shorter path is found
						if (!visited[adj - 1] && distances[currStation] + ticketCost < distances[adj - 1]) {
							distances[adj - 1] = distances[currStation] + ticketCost;
							predecessors[adj - 1] = currStation;

							// Deduct tickets from the detective?
							if (transportType == 1) taxiTix--;
							if (transportType == 2) busTix--;
							if (transportType == 4) subwayTix--;
						}
					}
				}
			}
		}
		// Return shortest distance to end station
		//return distances[end.getStationNum() - 1];

		// Reconstruct shortest path
		vector<int> shortestPath;
		int curr = end.getStationNum() - 1;

		while(curr != -1){
			shortestPath.push_back(board[curr].getStationNum());
		}

		reverse(shortestPath.begin(), shortestPath.end());

		return shortestPath;
	}
	
	//Uses shortestPath and loops through mr. x’s potential locations and 
	//selects the location with the minimal distance for the detective 'detective'
	Station DetectiveStrategy::chooseOptimalDetectiveMove(Player detective, TreeNode potentialMrXLocations, vector<Station> board) {
		//leaves of the tree of potential mrX locations are the current potential mrx locations- get them 
		vector<TreeNode> locations; 
		potentialMrXLocations.getLeaves(potential relocations, locations); //locations is updated by reference to contain the leaves 
		
		int shortestPathLen = INT_MAX; //current shortest path found
		int curPathLen;  //current path we're working with 
		vector<int> curPath;
		Station* closestStation; 
		Station* detectiveStation = detective.getCurrentStation();
	
		for(TreeNode curPotentialLoc : locations) {
			Station* curPotStation = curPotentialLoc.getStation();
			curPath = this->shortestPath(detective, *detectiveStation, *curPotStation, board);
			curPathLen = curPath.size();
			if(curPathLen < shortestPathLen) {
				shortestPathLen = curPathLen;
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
	
	void DetectiveStrategy::detectiveGreedyMove(vector<TreeNode> potentialMrXLocations, vector<Station> board) {
		
	//need to hold all of the stations that a detective goes to
	vector<int> detectiveDestinations(detectives.size());
		
		//go thorugh each detective and pulls the optimal move for that detective
	for (int i =0; i<detectives.size(); i++){
		Player& detective = detectives[i];
		int optimal = chooseOptimalDetectiveMove(detective, potentialMrXLocations, board).getStationNum();

	//make sure that the location has not conflict. 
	bool conflict = false;
	for (int j = 0; j < i; j++) {
		//goes through destinations vector to make sure none are equal
	if (detectiveDestinations[j] == optimal) {
		//is a detective already at that station, then make the conflict bool true
	conflict = true;
	}
	}

	if (conflict) {
	//making a vectore to hold the stations with conflicts 
	vector<Station> conflictingDestinations;
	conflictingDestinations.push_back(board[optimal -1]);
	//when a station has a conflict dont move rhat detective. -1 keeps detective in same place 
	//get a different station from break tie 
	int resolvedmove = breakTie((conflictingDestinations).getStationNum());
	//make the breaktie move the current move
	detectiveDestinations[i] = resolvedmove;
	} 
	else {
	detectiveDestinations[i] = optimal;
	}
	}
	for (int k = 0; k < detectives.size(); k++) {
		Player& detective = detectives[k];
		int destinationNum = detectiveDestinations[k];
		
		//make sure the station is a valid destination 
		if (destinationNum >= 1 && destinationNum <= board.size()){
		Station destination = board[destinationNum - 1]; 
		detective.setCurrentStation(destination);
		}
		}
	
	}
	
	//Returns a vector<int> which is the path (station #s in order) to the nearest subway station that the detective can reach in 'moves' number of moves
	//'moves' is the number of moves before mr. x shows up
	//'start' is the current station of the detective 
	//TO-DO: in GameManager, need to create function getSubwayStations(vector<Station> board) to be able to pass the subway stations to this function 
	//subway stations: 1, 46, 74, 93, 79, 111, 163, 153, 140, 185, 159, 13, 67, 89
	vector<int> DetectiveStrategy::pathToClosestSubway(Player detective, int moves, vector<Station> subwayStations, vector<Station> board) {
				
			int shortestPathLen = INT_MAX;	
			int curPathLen;
			vector<int> shortestPath;
			Station* detectiveStation = detective.getCurrentStation();
			
			//call shortestPath between start and each subway station to see if any subway station is reachable in under 'moves' # of moves 
			for(Station curSubStation : subwayStations) {
				shortestPath = this->shortestPath(detective, *detectiveStation, curSubStation, board);
				curPathLen = shortestPath.size();
				if(curPathLen < shortestPathLen && curPathLen < moves) //path is shorter than current shortest path AND less than 'moves' # of moves
					shortestPathLen = curPathLen;
			}			
		
		if(shortestPathLen == INT_MAX) { //no path to any subway station is < moves, return empty vector	
			vector<int> emptyPath;
			return emptyPath;
		} else //we have a real shortestPath, return it
			return shortestPath;
	}
	
	// For each detective, returns a vector of reachable stations they could get to in a certain amount of moves
	vector<vector<Station>> DetectiveStrategy::getReachableStations(vector<Player>& detectives, int movesUntilReveal, vector<Station>& board) {
    	vector<vector<Station>> allDetectiveStations;

		//going through each detective from players
		for (Player& detective : detectives) {
			vector<Station> reachableStations;

			int taxiTix = detective.getTaxiTickets();
			int busTix = detective.getBusTickets();
			int subwayTix = detective.getSubwayTickets();

			// Perform DFS for the current detective
			performDFS(detective.getCurrentStation(), movesUntilReveal, board, taxiTix, busTix, subwayTix, reachableStations);

			allDetectiveStations.push_back(reachableStations);
		}

		return allDetectiveStations;
	}

	

	void DetectiveStrategy::dfsHelper(int currentStationNum, int movesLeft, vector<bool>& visited, vector<Station>& reachableStations,
               vector<Station>& board, int& taxiTix, int& busTix, int& subwayTix) {
		//mark current staion as visted and add it to reach vector
		visited[currentStationNum - 1] = true;
		reachableStations.push_back(board[currentStationNum - 1]);

		//end recursion if no moves are left
		if (movesLeft <= 0) {
			return;
		}

		vector<int> adjacents;
		//get the current station local 
		Station& currentStation = board[currentStationNum - 1];
		//what stations are reachable based on tickets
		adjacents = currentStation.getAllAdjacentStations(
			{},        // No other detectives to consider
			taxiTix,   //  taxi tickets
			busTix,    //  bus tickets
			subwayTix  // subway tickets
		);
		
		for (int adj : adjacents) {
			//if the adjacent station has not beeen visited yet then 
			if (!visited[adj - 1]) {
				//get the current ways to travel depednng o n the current station
				vector<int> transportTypes = currentStation.getAllTransportTypesTo(board[adj - 1]);
				bool canProceed = false;

				for (int transport : transportTypes) {
					//check if a ticket can be used and then take thatused ticket away
					if (transport == 1 && taxiTix > 0) {
						taxiTix--;
						canProceed = true;
					} else if (transport == 2 && busTix > 0) {
						busTix--;
						canProceed = true;
					} else if (transport == 4 && subwayTix > 0) {
						subwayTix--;
						canProceed = true;
					}

					if (canProceed) {
						//moves left goes down by one in this call of helper
						dfsHelper(adj, movesLeft - 1, visited, reachableStations, board, taxiTix, busTix, subwayTix);

						//putting the tickets back for estimating the next reahcbale move 
						if (transport == 1) taxiTix++;
						if (transport == 2) busTix++;
						if (transport == 4) subwayTix++;
						//when a valid tranportion type is chosen leve theis loop with break
						break;
					}
				}
        	}
    	}
	}
	
	void DetectiveStrategy::performDFS(int startStation, int moves, vector<Station>& board, int taxiTix, int busTix, int subwayTix,
		vector<Station>& reachableStations) {
		
		// create the vector of visited stations (false for all stations so they are makred unvisited befoe the helper is called)
		vector<bool> visited(board.size(), false);

		//  helper function starting at the start station
		dfsHelper(startStation, moves, visited, reachableStations, board, taxiTix, busTix, subwayTix);
	}
	
	int DetectiveStrategy::chooseBestTicket(Player detective, vector<int> availableTransports) {
		//Returns highest priority transport types to a given station, like maybe we want to use buses first and save taxis and save subways
		return 0;
	}
	
	int DetectiveStrategy::distanceToPotentialMrX() {
		//For each detective, find distances to potential mr. x locations based off the tree of possible mr. x moves for greedy strategy
		return 0;
	}
	
	int DetectiveStrategy::chooseBestTicket(Player detective, vector<int> availableTransports) {
		//Returns highest priority transport types to a given station, like maybe we want to use buses first and save taxis and save subways
		return 0;
	}
	
