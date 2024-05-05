#ifndef OVERLOADING_H
#define OVERLOADING_H
#include <fstream>
#include "Player.h"
#include "Inventory.h"
#include "Map.h"
#include "Item.h"


ofstream& operator<<(ofstream& outFile, const Player& player);
ifstream& operator>>(ifstream& inFile, Player& player);
ofstream& operator<<(ofstream& outFile, const Armor& armor);

ofstream& operator<<(ofstream& outFile, const Weapon& weapon);

ifstream& operator>>(ifstream& inFile, Armor& armor);
ifstream& operator>>(ifstream& inFile, Weapon& weapon);

ofstream& operator<<(ofstream& outFile, const Inventory& inv);
ifstream& operator>>(ifstream& inFile, Inventory& inv);

ofstream& operator<<(ofstream& outFile, const Map& map);
ifstream& operator>>(ifstream& inFile, Map& map);


#endif 