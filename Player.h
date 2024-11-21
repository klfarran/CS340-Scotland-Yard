#ifndef PLAYER_H
#define PLAYER_H

#include "Station.h"

class Player {
private:
    bool isMrX;
    int taxiTickets;
    int busTickets;
    int subwayTickets;
    int blackTickets;  // Only Mr. X
    int doubleMoves;   // Only Mr. X
    Station* currentStation;  // Current location of the player

public:
    // Constructor
    Player(bool isMrX, Station* startStation);

    // Getters
    bool getIsMrX() const;
    int getTaxiTickets() const;
    int getBusTickets() const;
    int getSubwayTickets() const;
    int getBlackTickets() const;
    int getDoubleMoves() const;
    Station* getCurrentStation() const;

    // Setters
    void setTaxiTickets(int tickets);
    void setBusTickets(int tickets);
    void setSubwayTickets(int tickets);
    void setBlackTickets(int tickets);
    void setDoubleMoves(int moves);
    void setCurrentStation(Station* station);

    // Methods
    bool canMove(int transportType) const;
    void move(Station* destination, int transportType, Player& mrX);
    void moveWithDouble(Station* destination1, Station* destination2);
};

#endif
