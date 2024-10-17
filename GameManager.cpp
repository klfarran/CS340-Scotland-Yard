
	#include <iostream>
	#include <fstream>
	#include <sstream>

	#include "GameManager.h"
	#include "Station.h"
	#include "Edge.h"
	
	using namespace std;


	//contructor	
	GameManager::GameManager(){
		//game has to start on round 0, can't start game in middle of rounds
		round = 0; 
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
				cout << "Edge file not found" << endl;
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
