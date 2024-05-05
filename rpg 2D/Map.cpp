// Map.cpp

#include "Map.h"
#include "Random.h"
#include "Player.h"
#include <iostream>
#include <cstdlib> // For rand()
using namespace std;
// Constructor
Map::Map()
{
    // Player starts at origin (0, 0)
    mPlayerXPos = 0;
    mPlayerYPos = 0;
}
void saveGame(Map& map);

//ofstream& operator<<(ofstream& outFile, const Map& map)
//{
//    outFile << map.mPlayerXPos << endl << map.mPlayerYPos << endl;
//    return outFile;
//}
//ifstream& operator>>(ifstream& inFile, Map& map)
//{
//
//    inFile >> map.mPlayerXPos >> map.mPlayerYPos;
//    return inFile;
//}

// Get the player's X position
int Map::getPlayerXPos()
{
    return mPlayerXPos;
}

// Get the player's Y position
int Map::getPlayerYPos()
{
    return mPlayerYPos;
}

// Move the player
void Map::movePlayer()
{
    int selection = 1;
    cout << "1) North, 2) East, 3) South, 4) West: ";
    cin >> selection;
    // Update coordinates based on selection.
    switch (selection)
    {
    case 1: // North
        mPlayerYPos++;
        break;
    case 2: // East
        mPlayerXPos++;
        break;
    case 3: // South
        mPlayerYPos--;
        break;
    default: // West
        mPlayerXPos--;
        break;
    }
    cout << endl;
}
//Battle Simulation
void Map::battle(Player& player, Monster& monster, Map& map)
{
    // Print player's position
    map.printPlayerPos();
    // simulate battle
    while (!player.isDead() && !monster.isDead())
    {
        // Display hitpoints.
        player.displayHitPoints();
        monster.displayHitPoints();
        cout << endl;
        while (true)
        {
            // Display hitpoints.
            player.displayHitPoints();
            monster.displayHitPoints();
            cout << endl;
            // Player's turn to attack first:
            bool runAway = player.attack(monster);
            if (runAway)
            {
                break;
            }




            //if (runAway)
            //	break;
            if (monster.isDead())
            {
                player.victory(monster.getXPReward());
                player.levelUp();
                break;
            }
            monster.attack(player);
            if (player.isDead())
            {
                player.gameover();

                break;
            }
        }
        // The pointer to a monster returned from
        // checkRandomEncounter was allocated with
        // 'new', so we must delete it to avoid
        // memory leaks.

    }



}
// Check for random encounters
Monster* Map::checkRandomEncounter()
{
    int roll = Random(0, 20);
    std::unique_ptr<Monster> monster;

    if (roll <= 8)
    {
        // No encounter, return a null pointer.
        return nullptr;
    }
    else if (roll >= 9 && roll <= 12)
    {
        monster = std::make_unique<Monster>("Orc", 10, 8, 200, 1,
            "Short Sword", 2, 7);
        cout << "You encountered an Orc!" << endl;
        cout << "Prepare for battle!" << endl;
        cout << endl;
    }
    else if (roll >= 13 && roll <= 16)
    {
        monster = std::make_unique<Monster>("Goblin", 6, 6, 100, 0,
            "Dagger", 1, 5);
        cout << "You encountered a Goblin!" << endl;
        cout << "Prepare for battle!" << endl;
        cout << endl;
    }
    else if (roll >= 17 && roll <= 18)
    {
        monster = std::make_unique<Monster>("Ogre", 20, 12, 500, 2,
            "Club", 3, 8);
        cout << "You encountered an Ogre!" << endl;
        cout << "Prepare for battle!" << endl;
        cout << endl;
    }
    else if (roll >= 19 && roll <= 20)
    {
        monster = std::make_unique<Monster>("Orc Lord", 25, 15, 2000, 5,
            "Two Handed Sword", 5, 20);
        cout << "You encountered an Orc Lord!!!" << endl;
        cout << "Prepare for battle!" << endl;
        cout << endl;
    }
    return monster.release(); // Release ownership to the raw pointer
}

// Print player's position
void Map::printPlayerPos()
{
    cout << "Player Position = (" << mPlayerXPos << ", "
        << mPlayerYPos << ")" << endl << endl;
}