// Player.h
#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include "Monster.h"
#include "Inventory.h"
#include <string>
#include <fstream>
#include "Random.h"
#include <iostream>
#include "Map.h"
#include "OperatorOverloading.h"
using namespace std;

class Player
{
public:
    // Constructor.
    Player();
    // Methods
    bool isDead();
    std::string getName();
    int getArmor();
    int getHitPoints();
    int getGold();
    void setGold(int gold);
    void takeDamage(int damage);
    void createClass();
    bool attack(Monster& monster);
    void levelUp();
    void rest(Map& gameMap);
    void viewStats();
    void victory(int xp);
    void gameover();
    void equipWeapon(Inventory& inv, Weapon& weapon);
    void equipArmor(Inventory& inv, Armor& armor);
    void takePotion();
    void saveGame(Player& mainPlayer, Map& map, Inventory& inv);
    void loadGame(Player& mainPlayer, Map& map, Inventory& inv);

    friend ofstream& operator<<(ofstream& outFile, const Player& player);
    friend ifstream& operator>>(ifstream& inFile, Player& player);
    



    void displayHitPoints();

private:
    // Data members.
    std::string mName;
    std::string mClassName;
    int mAccuracy;
    int mHitPoints;
    int mMaxHitPoints;
    int mMagicPoints;
    int mMaxMagicPoints;
    int mExpPoints;
    int mNextLevelExp;
    int mLevel;
    

    int mGold;
    Armor mArmor;
    Weapon mWeapon;
};





struct SavePlayer {
    int mGold;
    Armor mArmor;
    Weapon mWeapon;

};

#endif //PLAYER_H