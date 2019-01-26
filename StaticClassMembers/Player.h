#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>

using namespace std;

class Player {
    
private:
    static int num_players;
    std::string name;
    int health;
    int xp;

public:
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getXp() const { return xp; }
    
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    // copy constructor
    Player(const Player &source);
    // destructor
    ~Player();
    
    static int getNumPlayers();  // static method, only have access to static members
};

#endif // ifndef
