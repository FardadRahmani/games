// Shop.h
#ifndef SHOP_H
#define SHOP_H
#include "Item.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
// Inventory system
// shop system
// items are string only
// Inventory can be extended
// User can buy stuff from the shop and place it into the inventory
// Use pointers to grow inventory and pass value between shop and inventory
// Avoid memory leaks

class Shop {
public:
	// Constructor.
	Shop();
	// Methods
	void addWeapon(Weapon& weapon);
	void addPotion(Potion& potion);
	void addArmor(Armor& armor);
	void printShop();
	void sellWeaponToPlayer(Inventory& inv, Weapon& weapon);
	void sellPotionToPlayer(Inventory& inv, Potion& potion);
	void sellArmorToPlayer(Inventory& inv, Armor& armor);

private:
	// Data members.
	std::vector<Weapon> mWeapon;
	std::vector<Armor> mArmor;
	std::vector<Potion> mPotion;
	




};


#endif // SHOP_H
