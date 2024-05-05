// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <iostream>
#include <vector>
#include <fstream>
// Inventory system
// shop system
// items are string only
// Inventory can be extended
// User can buy stuff from the shop and place it into the inventory
// Use pointers to grow inventory and pass value between shop and inventory
// Avoid memory leaks

class Inventory {
public:
	// Constructor.
	Inventory();
	// Methods
	void addWeapon(Weapon& weapon);
	void addPotion(Potion& potion);
	void addArmor(Armor& armor);
	void printInventory();
	//get methods
	std::vector<Weapon> getWeapon();
	std::vector<Potion> getPotion();
	std::vector<Armor> getArmor();

	friend class Player;

	friend ofstream& operator<<(ofstream& outFile, const Inventory& inv);
	friend ifstream& operator>>(ifstream& inFile,  Inventory& inv);

private:
	// Data members.
	std::vector<Weapon> mWeapon;
	std::vector<Armor> mArmor;
	std::vector<Potion> mPotion;




};


#endif // INVENTORY_H
