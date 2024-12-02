
	#include "DetectiveStrategy.h"
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
	