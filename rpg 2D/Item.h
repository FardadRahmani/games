#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <fstream>

#include "Range.h" // Assuming you have a Range class defined
using namespace std;
struct Weapon;
struct Armor;
struct Item
{
    friend ofstream &operator<<(ofstream& outFile, const Armor& armor);
    friend ofstream &operator<<(ofstream& outFile, const Weapon& weapon);

    friend ifstream &operator>>(ifstream& inFile, Armor& armor);
    friend ifstream &operator>>(ifstream& inFile, Weapon& weapon);

    std::string mName;
    int mCost;
};

struct Weapon : public Item
{
    Range mDamageRange;
};

struct Armor : public Item
{
    int armorRate;
};

struct Potion : public Item
{
    int potionRate;
};




//ofstream& operator<<(ofstream& outFile, const Armor& armor)
//{
//    outFile << armor.mName << endl << armor.armorRate << endl << armor.mCost << endl;
//    return outFile;
//}
//
//ofstream& operator<<(ofstream& outFile, const Weapon& weapon)
//{
//    outFile << weapon.mName << endl << weapon.mDamageRange.mLow << endl << weapon.mDamageRange.mHigh << endl << weapon.mCost <<endl;
//    return outFile;
//}
//
//ifstream& operator>>(ifstream& inFile, Armor& armor)
//{
//    inFile >> armor.mName >> armor.armorRate >> armor.mCost;
//    return inFile;
//
//}
//ifstream& operator>>(ifstream& inFile, Weapon& weapon)
//{
//    inFile >> weapon.mName >> weapon.mDamageRange.mLow >> weapon.mDamageRange.mHigh >> weapon.mCost;
//    return inFile;
//}



#endif // ITEM_H