#include <stdio.h>
#include <iostream>
#include "Player.h"

using namespace std;

void displayActivePlayers() {
    cout << "Active players: " << Player::getNumPlayers() << endl;
}


int main(int argc, char **argv)
{
	displayActivePlayers();
    Player hero("Hero");
    
    {
        Player frank("Franck");
        displayActivePlayers();
        
    }
    
    
    displayActivePlayers();
    
    cout << endl;
    
    Player *enemy = new Player("Enemy", 100, 100);
    displayActivePlayers();
    delete enemy;
    displayActivePlayers();
    
    
    return 0;
}
