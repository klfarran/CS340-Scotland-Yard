#include "Player.h"

// Constructor
Player::Player(bool isMrX, int startStation) {
    this->isMrX = isMrX;
    
    // Assign taxi tickets
    if (isMrX) {
        taxiTickets = 4;
    } else {
        taxiTickets = 10;
    }

    // Assign bus tickets
    if (isMrX) {
        busTickets = 3;
    } else {
        busTickets = 8;
    }

    // Assign subway tickets
    if (isMrX) {
        subwayTickets = 3;
    } else {
        subwayTickets = 4;
    }

    // Assign black tickets (only Mr. X)
    if (isMrX) {
        blackTickets = 5;
    } else {
        blackTickets = 0;
    }

    // Assign double moves (only Mr. X)
    if (isMrX) {
        doubleMoves = 2;
    } else {
        doubleMoves = 0;
    }

    // Set player's current station
    currentStation = startStation;
}


// Getters
bool Player::getIsMrX() const { 
    return isMrX; 
}

int Player::getTaxiTickets() const { 
    return taxiTickets; 
}

int Player::getBusTickets() const { 
    return busTickets; 
}

int Player::getSubwayTickets() const { 
    return subwayTickets; 
}

int Player::getBlackTickets() const { 
    return blackTickets; 
}

int Player::getDoubleMoves() const { 
    return doubleMoves; 
}

int Player::getCurrentStation() const { 
    return currentStation; 
}

// Setters
void Player::setTaxiTickets(int tickets) { 
    taxiTickets = tickets; 
}

void Player::setBusTickets(int tickets) { 
    busTickets = tickets; 
}

void Player::setSubwayTickets(int tickets) { 
    subwayTickets = tickets; 
}

void Player::setBlackTickets(int tickets) { 
    blackTickets = tickets; 
}

void Player::setDoubleMoves(int moves) { 
    doubleMoves = moves; 
}

void Player::setCurrentStation(int station) { 
    currentStation = station; 
}

// Check if the player can move using a specific transport type
bool Player::canMove(int transportType) const {
    switch (transportType) {
        case 1: return taxiTickets > 0;
        case 2: return busTickets > 0;
        case 3: return subwayTickets > 0;
        case 4: return blackTickets > 0 && isMrX;
        default: return false;
    }
}

// Move the player and deduct tickets, add used ticket to Mr. X's inventory if player is a detective
void Player::move(int destination, int transportType, Player& mrX) {
    if (canMove(transportType)) {
        currentStation = destination;

        // Deduct tickets based on transport type and add the used ticket to Mr. X's inventory
        switch (transportType) {
            case 1:
                taxiTickets--;
                mrX.taxiTickets++;
                break;
            case 2:
                busTickets--;
                mrX.busTickets++;
                break;
            case 3:
                subwayTickets--;
                mrX.subwayTickets++;
                break;
            case 4:
                blackTickets--;
                break;
        }
    }
}


// Mr. X double moves
void Player::moveWithDouble(int destination1, int destination2) {
    if (isMrX && doubleMoves > 0) {
        currentStation = destination1;  // First move
        currentStation = destination2;  // Second move
        doubleMoves--;  // Use up a double move ticket
    }
}
