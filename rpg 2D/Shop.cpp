// Shop.cpp

#include "Shop.h"
using namespace std;
// Constructor
Shop::Shop() {
    // Initialize vectors
    mWeapon = std::vector<Weapon>();
    mArmor = std::vector<Armor>();
    mPotion = std::vector<Potion>();
}

// Add a weapon to the shop
void Shop::addWeapon(Weapon& weapon) {
    mWeapon.push_back(weapon);



}

// Add a potion to the shop
void Shop::addPotion(Potion& potion) {

    mPotion.push_back(potion);

}

// Add an armor to the Shop from Player
void Shop::addArmor(Armor& armor) {
    mArmor.push_back(armor);

}
void sellWeaponToPlayer(Inventory& inv, Weapon& weapon)
{
    inv.addWeapon(weapon);

}
void sellPotionToPlayer(Inventory& inv, Potion& potion) {
    inv.addPotion(potion);
}
void sellArmorToPlayer(Inventory& inv, Armor& armor) {
    inv.addArmor(armor);
}




// Display the Shop
void Shop::printShop() {
    cout << "SHOP" << endl;
    cout << "====" << endl;
    cout << endl;
    cout << "1. Weapons:" << endl;
    for (int i = 0; i < mWeapon.size(); i++)
    {
        cout << i + 1 << ". " << mWeapon[i].mName << " (" << mWeapon[i].mDamageRange.mLow << "-" << mWeapon[i].mDamageRange.mHigh << ")" << endl;

    }
    cout << endl;
    cout << "2. Armor:" << endl;
    for (int i = 0; i < mArmor.size(); i++)
    {
        cout << i + 1 << ". " << mArmor[i].mName << " (" << mArmor[i].armorRate << ")" << endl;

    }
    cout << endl;
    cout << "3. Potions:" << endl;
    for (int i = 0; i < mPotion.size(); i++)
    {
        cout << i + 1 << ". " << mPotion[i].mName << " (" << mPotion[i].potionRate << ")" << endl;

    }
    cout << endl;
    cout << "4. Sell" << endl;
    cout << "5. Leave Shop" << endl;

}