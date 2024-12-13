#ifndef PLAYER_H
#define PLAYER_H


class Player {
private:
    bool isMrX;
    int taxiTickets;
    int busTickets;
    int subwayTickets;
    int blackTickets;  // Only Mr. X
    int doubleMoves;   // Only Mr. X
    int currentStation;  // Current station number of the location of the player

public:
    // Constructor
    Player(bool isMrX, int startStation);

    // Getters
    bool getIsMrX() const;
    int getTaxiTickets() const;
    int getBusTickets() const;
    int getSubwayTickets() const;
    int getBlackTickets() const;
    int getDoubleMoves() const;
    int getCurrentStation() const;

    // Setters
    void setTaxiTickets(int tickets);
    void setBusTickets(int tickets);
    void setSubwayTickets(int tickets);
    void setBlackTickets(int tickets);
    void setDoubleMoves(int moves);
    void setCurrentStation(int station);

    // Methods
    bool canMove(int transportType) const;
    void move(int destination, int transportType, Player& mrX);
    void moveWithDouble(int destination1, int destination2);
};

#endif
