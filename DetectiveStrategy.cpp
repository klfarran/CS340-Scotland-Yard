
	#include "DetectiveStrategy.h"
	#include <limits> //for INT_MAX
	#include <limits.h>
	#include "Station.h"
	#include "Edge.h"
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
		potentialMrXLocations.getLeaves(potentialMrXLocations, locations); //locations is updated by reference to contain the leaves 
		
		int shortestPathLen = INT_MAX; //current shortest path found
		int curPathLen;  //current path we're working with 
		vector<int> curPath;
		Station* detectiveStation = detective.getCurrentStation();
	
		for(TreeNode curPotentialLoc : locations) {
			Station* curPotStation = curPotentialLoc.getStation();
			curPath = this->shortestPath(detective, *detectiveStation, *curPotStation, board);
			curPathLen = curPath.size();
			if(curPathLen < shortestPathLen) {
				shortestPathLen = curPathLen;
			}
		}
			return board[curPath[0]-1]; 
	}
	
	//If multiple detectives have the same choices for where to go, choose a destination 
	//station that benefits the whole team by spreading detectives to cover more of mr. x’s potential moves
	Station DetectiveStrategy::breakTie(vector<Station> destinations) {		
		vector<Edge> edges;
		return Station(0, edges);
	}
	
	//pulls optimal moves and uses tie to decide which detective gets ahead.  
//this needs the tree node vetor to show the potential X locations. 
//the stations that rep the board. 
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
	
	vector<Station> DetectiveStrategy::getReachableStations(Station start, int movesRemaining) {
		//Return all stations a detective can reach in a certain number of moves, like pathToClosestSubway but more general
		vector<Station> stations;
		return stations;
	}
	
	int DetectiveStrategy::chooseBestTicket(Player detective, vector<int> availableTransports) {
		//Returns highest priority transport types to a given station, like maybe we want to use buses first and save taxis and save subways
		return 0;
	}
	
