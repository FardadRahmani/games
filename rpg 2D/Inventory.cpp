// Inventory.cpp

#include "Inventory.h"
using namespace std;
// Constructor
Inventory::Inventory() {
    // Initialize vectors
    mWeapon = std::vector<Weapon>();
    mArmor = std::vector<Armor>();
    mPotion = std::vector<Potion>();
}



//ofstream& operator<<(ofstream& outFile, const Inventory& inv)
//{
//    for (int cnt = 0; cnt < inv.mWeapon.size(); ++cnt)
//    {
//        outFile << inv.mWeapon[cnt] << endl;
//        
//    }
//    for (int cnt = 0; cnt < inv.mArmor.size(); ++cnt)
//    {
//        outFile << inv.mArmor[cnt] << endl;
//    }
//    return outFile;
//    
//}
//ifstream& operator>>(ifstream& inFile, Inventory& inv)
//{
//  
//    ifstream saveInvIndex{ "invIndexSave.txt" };
//
//    if (!saveInvIndex.is_open()) cout << "Error loading Data";
//    int cnt1, cnt2;
//    saveInvIndex >> cnt1 >> cnt2;
//
//    for (int i = 0; i <= cnt1; ++i)
//    {
//        inFile >> inv.mWeapon[i];
//    }
//    for (int i = 0; i <= cnt2; ++i)
//    {
//        inFile >> inv.mArmor[i];
//    }
//    return inFile;
//    saveInvIndex.close();
//
//}


// Add a weapon to the inventory
void Inventory::addWeapon(Weapon& weapon) {

    mWeapon.push_back(weapon);
}

// Add a potion to the inventory(Potion& potion)
void Inventory::addPotion(Potion& potion) {

    mPotion.push_back(potion);
}

// Add an armor to the inventory
void Inventory::addArmor(Armor& armor) {

    mArmor.push_back(armor);
}


// Display the inventory
void Inventory::printInventory() {
    cout << "INVENTORY" << endl;
    cout << "=========" << endl;
    cout << endl;
    cout << "1.Weapons:" << endl;
    for (int i = 0; i < mWeapon.size(); i++)
    {
        cout << i + 1 << ". " << mWeapon[i].mName << " (" << mWeapon[i].mDamageRange.mLow << "-" << mWeapon[i].mDamageRange.mHigh << ")" << endl;

    }
    cout << endl;
    cout << "2.Armor:" << endl;
    for (int i = 0; i < mArmor.size(); i++)
    {
        cout << i + 1 << ". " << mArmor[i].mName << " (" << mArmor[i].armorRate << ")" << endl;

    }
    cout << endl;
    cout << "3.Potions:" << endl;
    for (int i = 0; i < mPotion.size(); i++)
    {
        cout << i + 1 << ". " << mPotion[i].mName << " (" << mPotion[i].potionRate << ")" << endl;

    }
    cout << endl;
    cout << "4.Leave Inventory" << endl;

}

//get methods
std::vector<Weapon> Inventory::getWeapon()
{
    return mWeapon;
}

std::vector<Potion> Inventory::getPotion() {
    return mPotion;

}
std::vector<Armor> Inventory::getArmor() {
    return mArmor;

}