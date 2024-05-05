// Monster.cpp

#include "Monster.h"
#include "Player.h"
#include "Random.h"
#include <iostream>
using namespace std;
// Constructor
Monster::Monster(const std::string& name, int hp, int acc,
    int xpReward, int armor, const std::string& weaponName,
    int lowDamage, int highDamage)
{
    mName = name;
    mHitPoints = hp;
    mAccuracy = acc;
    mExpReward = xpReward;
    mArmor = armor;
    mWeapon.mName = weaponName;
    mWeapon.mDamageRange.mLow = lowDamage;
    mWeapon.mDamageRange.mHigh = highDamage;
}

// Check if the monster is dead
bool Monster::isDead()
{
    return mHitPoints <= 0;
}

// Get the experience reward for defeating the monster
int Monster::getXPReward()
{
    return mExpReward;
}

// Get the monster's name
std::string Monster::getName()
{
    return mName;
}

// Get the monster's armor value
int Monster::getArmor()
{
    return mArmor;
}

// Attack the player
void Monster::attack(Player& player)
{
    cout << "A " << mName << " attacks you "
        << "with a " << mWeapon.mName << endl;
    if (Random(0, 20) < mAccuracy)
    {
        int damage = Random(mWeapon.mDamageRange);
        int totalDamage = damage - player.getArmor();
        if (totalDamage <= 0)
        {
            cout << "The monster's attack failed to "
                << "penetrate your armor." << endl;
        }
        else
        {
            cout << "You are hit for " << totalDamage
                << " damage!" << endl;
            player.takeDamage(totalDamage);
        }
    }
    else
    {
        cout << "The " << mName << " missed!" << endl;
    }
    cout << endl;
}

// Take damage from the player
void Monster::takeDamage(int damage)
{
    mHitPoints -= damage;
}

// Display the monster's hit points
void Monster::displayHitPoints()
{
    cout << mName << "'s hitpoints = " << mHitPoints << endl;
}