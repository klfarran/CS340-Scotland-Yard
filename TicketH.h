#include "Station.h"
#include "player.h"
#include <iostream>
#include <vector>
	
	
//Ticket types
int TAXI =0;
int BUS =1;
int UNDERGROUND =2;
int BLACK =3; 
int RIVER =4;
int DOUBLE = 5;
	

class Ticket{
	
private:
	vector<vector<int>> playerTickets; //storing howmany tickets a player has 
	
public:

	int getIndex(string& ticket);  
  //  int getTicketCount(int transportType);//?
    bool useTicket(int player, int transportType);
	void TicketsAvail();
   
};
	