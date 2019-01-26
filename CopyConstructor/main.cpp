#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Player {
    
private:
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
    ~Player() { cout << "Destructor called for: " << name << endl; }
    
};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} { std::cout << "Three-args constructor\n"; }

Player::Player(const Player &source)
    :Player(source.name, source.health, source.xp) {
//    name(source.name), health(source.health), xp(source.xp) {
        cout << "Copy constructor - made a copy of: " << source.name << endl;
}

void displayPlayer(const Player &p) {
    cout << "Name: " << p.getName() << endl;
    cout << "Health: " << p.getHealth() << endl;
    cout << "xp: " << p.getXp() << endl;
}


int main(int argc, char **argv)
{
//    Player empty {"XXXX", 100, 150};
//    Player my_new_object {empty};
//    displayPlayer(empty);
//    
//    
//    Player frank {"Frank"};
//    Player Hero {"Hero", 100, 10};
    const Player villain {"Villain", 100, 55};
    displayPlayer(villain);
    
    return 0;
}
