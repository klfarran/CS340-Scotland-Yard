#include "Ticket.h"
#include <string>
#include <isostream>
#include <vector>

// Make ticket type to an number now
int getIndex(string& ticket) {
    if (ticket == "TAXI") return TAXI;
    if (ticket == "BUS") return BUS;
    if (ticket == "UNDERGROUND") return UNDERGROUND;
	if (ticket == "RIVER") return RIVER;
	if (ticket == "BLACK") return BLACK;
	if (ticket == "DOUBLE") return DOUBLE;
    return 0;  // no ticket type 
}

// and the Constructor makes tickets for all players
Ticket::Ticket(int numPlayers) {
	
//set size of private playerTickets around now
// plays have 3 tickets, taxi, bus, under, plus black ticket now
//number of players x 4 types of tickets
 playerTickets.resize(numPlayers, vector<int>(4, 0)); //i need ticket counts for player starting at 0

    // set tickets for detective players (except Mr. X)
for (int i = 0; i < numPlayers - 1; ++i) {
		//player i is given 3 tickets 
        playerTickets[i][0] = 10;  // 10 t tickets
		
        playerTickets[i][1] = 8;       // 8 b tickets
		
        playerTickets[i][2] = 4;   // 4 u tickets
		
		playerTickets[i][3] = 0;     // 0 s moves
    }

// tickets for Mr. X (the last player)
	//player has 4 tickets
    playerTickets[numPlayers - 1][0] = 4;  // 4 t tickets
    playerTickets[numPlayers - 1][1] = 3;    // 3 b tickets
	
	
    playerTickets[numPlayers - 1][2] = 3;         // 3 u tickets
	playerTickets[numPlayers - 1][3] = 4;  // 4 s moves
}

// checticket for a specific player
    //(paras: what player, reference ticket) player with id num?
bool Ticket::useTicket(int playerId, string& ticketType) {
	//call index function to store the right ticket 
    int ticketIndex = getIndex(ticket);  // Find the right ticket\
	
	//if the ticket is valid and checks if ticket is avail for player with id
    if (ticketIndex != 0 && playerTickets[playerId][ticketIndex] > 0) {
       
	   playerTickets[playerId][ticketIndex]--;  // 
        return true;  // Ticket used successfully
    } 
	else {
    cout << "Player " << playerId << " is out of " << ticketType << " tickets. Oh No!"<<endl;
        return false;  // No tickets left
    }
	
}
////
// for now cout what ticket srae left ithink for just t
void Ticket::TicketAvail() {
	
	//loop through amount of tickets 
    for (int i = 0; i < playerTickets.size(); i++) {
        cout << "PLAYER: " << i <<endl;
        cout << "TAXI: " << playerTickets[i][0] <<endl;
        cout << "BUS: " << playerTickets[i][1] <<endl;
        cout << "UNDERGROUND: " << playerTickets[i][2] <<endl;
		cout << "BLACK: " <<playerTickets[i][3] <<endl;
    }//for loop
}
