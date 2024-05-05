#include "OperatorOverloading.h"



ofstream& operator<<(ofstream& outFile, const Player& player)
{
    outFile << player.mWeapon
        << player.mArmor << player.mName << endl << player.mClassName << endl << player.mHitPoints << endl << player.mMaxHitPoints << endl << player.mMagicPoints << endl << player.mMaxMagicPoints << endl
        << player.mGold << endl << player.mAccuracy << endl << player.mExpPoints << endl << player.mNextLevelExp << endl << player.mLevel << endl;
    return outFile;
}
ifstream& operator>>(ifstream& inFile, Player& player)
{

    inFile >> player.mWeapon
        >> player.mArmor
        >> player.mName >> player.mClassName >> player.mHitPoints >> player.mMaxHitPoints >> player.mMagicPoints >> player.mMaxMagicPoints
        >> player.mGold >> player.mAccuracy >> player.mExpPoints >> player.mNextLevelExp >> player.mLevel;

    return inFile;



}
ofstream& operator<<(ofstream& outFile, const Armor& armor)
{
    outFile << armor.mName << endl << armor.armorRate << endl << armor.mCost << endl;
    return outFile;
}

ofstream& operator<<(ofstream& outFile, const Weapon& weapon)
{
    outFile << weapon.mName << endl << weapon.mDamageRange.mLow << endl << weapon.mDamageRange.mHigh << endl << weapon.mCost << endl;
    return outFile;
}

ifstream& operator>>(ifstream& inFile, Armor& armor)
{
    getline(inFile, armor.mName);
    inFile  >> armor.armorRate >> armor.mCost;
    return inFile;

}
ifstream& operator>>(ifstream& inFile, Weapon& weapon)
{
    getline(inFile, weapon.mName);

    inFile >> weapon.mDamageRange.mLow >> weapon.mDamageRange.mHigh >> weapon.mCost;
    return inFile;
}

ofstream& operator<<(ofstream& outFile, const Inventory& inv)
{
    for (int cnt = 0; cnt < inv.mWeapon.size(); ++cnt)
    {
        outFile << inv.mWeapon[cnt] << endl;

    }
    for (int cnt = 0; cnt < inv.mArmor.size(); ++cnt)
    {
        outFile << inv.mArmor[cnt] << endl;
    }
    return outFile;

}
ifstream& operator>>(ifstream& inFile, Inventory& inv)
{

    ifstream saveInvIndex{ "invIndexSave.txt" };
    ifstream saveInv{ "invSave.txt" };

    if (!saveInvIndex.is_open() || !saveInv.is_open())
    {
        cout << "Error loading Data";
        return inFile; // Return early if file open fails
    }

    int cnt1, cnt2;
    saveInvIndex >> cnt1 >> cnt2;

    // Read weapon data
    for (int i = 0; i < cnt1; ++i)
    {
        Weapon weapon; // Create a temporary weapon object
        saveInv >> weapon; // Read weapon data from "invSave.txt"
        inv.mWeapon.push_back(weapon); // Add the weapon to the inventory
    }

    // Read armor data
    for (int i = 0; i < cnt2; ++i)
    {
        Armor armor; // Create a temporary armor object
        saveInv >> armor; // Read armor data from "invSave.txt"
        inv.mArmor.push_back(armor); // Add the armor to the inventory
    }

    saveInvIndex.close(); // Close the file streams
    saveInv.close();
    return inFile;
    

}
ofstream& operator<<(ofstream& outFile, const Map& map)
{
    outFile << map.mPlayerXPos << endl << map.mPlayerYPos << endl;
    return outFile;
}
ifstream& operator>>(ifstream& inFile, Map& map)
{

    inFile >> map.mPlayerXPos >> map.mPlayerYPos;
    return inFile;
}
