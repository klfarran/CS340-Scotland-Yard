//class GameManager 

//public:
//distance needs the start, the end, and the vector of 
int distance(int startStationNum, int endStationNum, vector<Station>& board);

int GameManager::distance(int startStationNum, int endStationNum, vector<Station>& board){
	if (startStationNum == endStationNum) { //when start and end are the same, the distance is 0
		return 0;
	}
	
	
	int TotalStations = board.size();
	vector <int> distance(numstations,-1);// the amount of stations is the 
	//size of this vector, each element is -1 at first to set as unvisited
	
	queue<int> q;
	q.push(startStationNum);
	distance[startStationNum -1] =0; //the start distance is 0 not the "unvisted" number -1
	
	while (!q.empty()) {
        int currentStationNum = q.front();
        q.pop();
		
		vector<int> adjacents = board[currentStationNum - 1].getAllAdjacentStations(getDetectiveLocations(detectives), mrX.getTaxiTickets(), mrX.getBusTickets(), mrX.getSubwayTickets());
		for (int i = 0; i < adjacents.size(); i++) {
    int adjacentStationNum = adjacents[i];
	
	
	if (distance.find(adjacentStationNum) == distance.end()) {
    //chnage the distance to this station
    distance[adjacentStationNum] = distance[currentStationNum] + 1;
    //if the end station is found, return the distance
        if (adjacentStationNum == endStationNum) {
            return distance[adjacentStationNum];
        }

    q.push(adjacentStationNum);  //push the adjacent station on the queue
    }
	
		}
	}
}
