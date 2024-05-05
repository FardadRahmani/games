// Map.h
#ifndef MAP_H
#define MAP_H
#include "Item.h"
#include "Monster.h"
#include <string>
#include <fstream>
#include <memory>
class Map
{
public:
	// Constructor.
	Map();
	// Methods
	int getPlayerXPos();
	int getPlayerYPos();
	void movePlayer();
	Monster* checkRandomEncounter();
	void battle(Player& player, Monster& monster, Map& map);
	
	friend ofstream& operator<<(ofstream& outFile, const Map& map);

	friend ifstream& operator>>(ifstream& inFile, Map& map);

	void printPlayerPos();
private:
	// Data members.
	int mPlayerXPos;
	int mPlayerYPos;
};
#endif //MAP_H