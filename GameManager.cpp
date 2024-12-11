
	#include <iostream>
	#include <fstream>
	#include <sstream>
	
	#include "Station.h"
	#include "Edge.h"
	#include "Player.h"
	#include "TreeNode.h"
	#include "GameManager.h"
	#include "DetectiveStrategy.h"
	
	using namespace std;


	//constructor	
	GameManager::GameManager(){
		//game has to start on round 1, can't start game in middle of rounds
		round = 1; 
	}

	//function to return the number of the current round of the game 
	int GameManager::getRound(){
		return round;
	}
	
	//function to initialize the game board 
	//to be implemented
	vector<Station> GameManager::initializeBoard() {
		
	   vector<Station> board; 
		
		//READ EACH EDGE DEFINITION FROM AN EXTERNAL FILE 
		
		vector<Edge> edges; //vector of all edges, must be read from "edges.txt"
		
		// open the file
		string filename = "edges.txt";

		ifstream fin;
		fin.open(filename.data());
			while(!fin){ //for debugging only:
				cout << "Edge file not found. Please have edges.txt in the same directory as this project" << endl;
		}
	
			//read the file of edges
			string line; 
			
			string PointA;
			string PointB;
			string inTransport;
			int transport; //the actual transport type as determined by the bitwise or
			
			while(getline(fin, line)) {
				stringstream ss(line);

				ss >> PointA; // Read in station number Point A

				ss >> PointB; // Read in station number Point B

				ss >> inTransport; // Read transport type as it appears in file (BUS, TAXI|BUS, ...)
				
				if(inTransport == "TAXI")
					transport = 1;
				else if(inTransport == "BUS")
					transport = 2;
				else if(inTransport == "UNDERGROUND")
					transport = 4;
				else if(inTransport == "RIVER")
					transport = 8;
				else if(inTransport == "TAXI|BUS")
					transport = 1 | 2;
				else if(inTransport == "BUS|UNDERGROUND")
					transport = 2 | 4;
			
				//make the edge with the info read from the file 
				Edge curEdge(stoi(PointA), stoi(PointB), transport); //stoi(string str) takes a string and returns its integer equivalent 
				
				//add the edge to the list of all edges 'edges'
				edges.push_back(curEdge);
			}
		
		//create each station and add its relevant edges to its list of edges
		//add the newly created station to the board
		
		vector<Edge>stationEdges;
		
		for(int i = 1; i <= 200; i++) { //199 stations on the board, ranging from 1 to 200
			stationEdges.clear(); //we're reusing this vector to temporarily hold the edges for each station
			
			//for each station, loop through the vector of ALL edges and find the edges which 'come from' that specific station
			//push these edges back to the list of edges for the station 
			for(int x = 0; x < edges.size(); x++) {
				if(edges[x].getPointA() == i)
					stationEdges.push_back(edges[x]);
			}
			
			//make the station
			Station curStation(i, stationEdges); //station number is i
			
			//push the station back to the board 
			board.push_back(curStation);
		}
		
		return board;
	}

	void GameManager::gameLoop(Player& mrX, vector<Player>& detectives, vector<Station>& board) {
    	bool gameOver = false;
		TreeNode possibleMrXLocations = TreeNode();

		//pass detectives to detective strategy class to initialize the detective strategy object 
		DetectiveStrategy detectiveStrategy(detectives);

    	// Start the game loop
    	while (!gameOver) {
        
			// Display current round
			cout << "\nRound " << round << " begins!" << endl;

			// Mr. X's turn
			cout << "Mr. X's turn!" << endl;
        
			// Show available moves for Mr. X, only reveal location on rounds 3, 8, 13, 18, 24
			vector<int> possibleMoves = board[mrX.getCurrentStation()-1].getAllAdjacentStations(getDetectiveLocations(detectives), mrX.getTaxiTickets(),mrX.getBusTickets(), mrX.getSubwayTickets());
			if(round == 3 || round == 8 || round == 13 || round == 18 || round == 24){
				cout << "Mr. X is at station " << mrX.getCurrentStation() << ". Available stations to move to:  ";
			}
			else{
				cout << "Mr. X's location is hidden. Available stations to move to:  ";
			}
			for (int stationNum : possibleMoves) {
				cout << stationNum << " ";
			}
			cout << endl;

			// Mr. X Double move
			char useDoubleMove;
			cout << "Do you want to use a double move? (y/n): ";
			cin >> useDoubleMove;

			if(useDoubleMove == 'y' && mrX.getDoubleMoves() > 0){
				// Ask for the transport type and destination for Mr. X's first move
				int firstStation, firstTransport;
				cout << "Enter the first destination station number: ";
				cin >> firstStation;
				
				//print available transportation methods for user 
				vector<int> availTransportTypes = board[mrX.getCurrentStation()-1].getAllTransportTypesTo(board[firstStation-1]);
				cout << "\nAvailable modes of transportation: ";
				printAvailalbeTransportTypes(availTransportTypes);
				
				cout << "Enter the first transport type (1: Taxi, 2: Bus, 3: Subway, 4: Black Ticket): ";
				cin >> firstTransport;

				//show possible destinations for second half of double move: 
				vector<int> possibleSecondMoves = board[firstStation-1].getAllAdjacentStations(getDetectiveLocations(detectives), mrX.getTaxiTickets(),mrX.getBusTickets(), mrX.getSubwayTickets());
				cout << "Mr. X's location is hidden. Available stations to move to:  ";
					for (int stationNum : possibleSecondMoves) {
						cout << stationNum << " ";
					}
				cout << endl;		
				
				// Ask for the transport type and destination for Mr. X's double move
				int doubleStation, doubleTransport;
				cout << "Enter the second destination station number: ";
				cin >> doubleStation;
				
				//print available transportation methods for user 
				vector<int> secondAvailTransportTypes = board[firstStation-1].getAllTransportTypesTo(board[doubleStation-1]);
				cout << "\nAvailable modes of transportation: ";
				printAvailalbeTransportTypes(secondAvailTransportTypes);
				
				cout << "Enter the second transport type (1: Taxi, 2: Bus, 3: Subway, 4: Black Ticket): ";
				cin >> doubleTransport;	

				// Move Mr. X if possible
				if (mrX.canMove(firstTransport) && mrX.canMove(doubleTransport)) {
					mrX.moveWithDouble(firstStation, doubleStation);
					cout << "Mr. X used a double move and moved to station " << mrX.getCurrentStation() << endl;
				} else {
					cout << "Invalid move." << endl;
				}							
			}
			else if (useDoubleMove == 'n'){
				// Ask for the transport type and destination for Mr. X
				int chosenStation, chosenTransport;
				cout << "Enter the destination station number: ";
				cin >> chosenStation;
				//print available transportation methods for user 
				vector<int> availTransportTypes = board[mrX.getCurrentStation()-1].getAllTransportTypesTo(board[chosenStation-1]);
				cout << "\nAvailable modes of transportation: ";
				printAvailalbeTransportTypes(availTransportTypes);
				
				cout << "Enter the desired transport type (1: Taxi, 2: Bus, 3: Subway, 4: Black Ticket): ";
				cin >> chosenTransport;
				
				// Move Mr. X if possible
				if (mrX.canMove(chosenTransport)) {
					mrX.move(chosenStation, chosenTransport, mrX);
					cout << "Mr. X moved to station " << mrX.getCurrentStation() << endl;
					
					if(round == 3 || round == 8 || round == 13 || round == 18) //or first half of a double move,...
						possibleMrXLocations = Build_Tree(mrX.getCurrentStation(), board, mrX, detectives);	
					else 
						AddNextPossibleMrXLocations(possibleMrXLocations, board, mrX, detectives);
					
				} else {
					cout << "Invalid move. Mr. X cannot move with this transport type." << endl;
				}
			}

			// Detectives' turn
			cout << "\nDetectives' turn!" << endl;

			int detectiveNum = 1;
			for (int i = 0; i < detectives.size(); i++) {
				cout << "Detective #" << detectiveNum << " at station " << detectives[i].getCurrentStation() << " is moving..." << endl;
				int stationNum = detectives[i].getCurrentStation();
				// Detective chooses optimal solution based on shortest path to potential Mr X location
				int nextStation = detectiveStrategy.chooseOptimalDetectiveMove(detectives[i], getDetectiveLocations(detectives), possibleMrXLocations, board);
				//cout << "destination station: " <<nextStation << " " << endl; 

				detectives[i].setCurrentStation(stationNum);
				
				vector<int> transportTypes = board[detectives[i].getCurrentStation()-1].getAllTransportTypesTo(board[nextStation-1]);
				
				//for debugging, delete later 
				//cout << "current station: " << detectives[i].getCurrentStation()->getStationNum() << endl;
				/*
				cout << "transport types: ";
				for (int k = 0; k < transportTypes.size(); k++) {
					cout << transportTypes[k] << " ";
				}
				cout << endl;
				*/
				// Just choose the first transport type for now
				detectives[i].move(nextStation, transportTypes[0], mrX);

				detectiveNum++;
			}

			// Check if the round count has reached the endgame, 24 rounds
			if (round == 24) {
				cout << "Maximum rounds reached. Mr. X wins!" << endl;
				gameOver = true;
			}

			// Increment round
			round++;

			// Continue to the next round unless gameOver is true
    	}
	}
	
	//function which takes a list of detectives (players minus mrX) and returns a vector of integers which are the 
	//corresponding station numbers of the station that each detective is at 
	vector<int> GameManager::getDetectiveLocations(vector<Player> detectives) {
		vector<int> locations;
		
		for(int i = 0; i < detectives.size(); i++) {
			locations.push_back(detectives[i].getCurrentStation());
		}
		
		return locations;
	}
	
	TreeNode GameManager::Build_Tree(int station, vector<Station>& board, Player& mrX, vector<Player> detectives) {
		vector<TreeNode> children;
		vector<TreeNode> childrensChildren = {};
	
		vector<int> adjacentStationNumbers = board[station-1].getAllAdjacentStations(getDetectiveLocations(detectives), mrX.getTaxiTickets(), mrX.getBusTickets(), mrX.getSubwayTickets());
			for(int i = 0; i < adjacentStationNumbers.size(); i++) {
				TreeNode child(adjacentStationNumbers[i], childrensChildren); //
				children.push_back(child);
			}
		TreeNode root(station, children);
		return root;
	}


	void GameManager::AddNextPossibleMrXLocations(TreeNode possibleMrXLocations, vector<Station>& board, Player& mrX, vector<Player>& detectives) {
	//improve after finishing to add pruning
		//go to every leaf of the tree and add all possible next stations as children of each 
		vector<TreeNode> leaves; 
		vector<TreeNode> childrensChildren = {};

		possibleMrXLocations.getLeaves(possibleMrXLocations, leaves); //updates leaves vector to contain all leaves from tree rooted at possibleMrXLocations
		
		if(leaves[0].getStation() != -1) { //its not round 1 or 2, so build next level of tree given mrX's possible location(s)
			for(int j = 0; j < leaves.size(); j++) {
				vector<TreeNode> children;
				vector<int> adjacentStationNumbers = board[leaves[j].getStation()-1].getAllAdjacentStations(getDetectiveLocations(detectives), mrX.getTaxiTickets(), mrX.getBusTickets(), mrX.getSubwayTickets());
				for(int i = 0; i < adjacentStationNumbers.size(); i++) {
					TreeNode child(adjacentStationNumbers[i], childrensChildren); 
					children.push_back(child);
				}	
				leaves[j].setChildren(children);
			 }
	    }
	}

	//prints out in one line the available transport types according to the transport types found in 
	//incoming vector availTransportTypes
	void GameManager::printAvailalbeTransportTypes(vector<int> availTransportTypes) {
		
		string answer = "";
		bool hasTaxi = false; 
		bool hasBus = false;
		bool hasUnd = false;
		bool hasBlack = false; 
		
		for(int k = 0; k < availTransportTypes.size(); k++) {
				if(availTransportTypes[k] == 1)
					hasTaxi = true;
				else if(availTransportTypes[k] == 2)
					hasBus = true;
				else if(availTransportTypes[k] == 4)
					hasUnd = true; 
				else if(availTransportTypes[k] == 8)
					hasBlack = true;
			}
			
		if(hasTaxi)
			answer += "Taxi ";
		if(hasBus)
			answer += "Bus ";
		if(hasUnd)
			answer += "Underground ";
		if(hasBlack)
			answer += "Black ";
		
		//add commas in the answer 
		for (int k = 0; k < answer.length() -1; k++) { //dont want to replace the last space with a comma 
			if (answer.at(k) == ' ') 
				answer.insert(k, ", ");
		}
		cout << answer << endl;
	}

