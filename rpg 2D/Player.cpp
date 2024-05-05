// Player.cpp

#include "Player.h"




using namespace std;

//ofstream& operator<<(ofstream& outFile, const Player& player)
//{
//    outFile << player.mWeapon
//        << player.mArmor << player.mName << endl << player.mClassName << endl << player.mHitPoints << endl << player.mMaxHitPoints << endl << player.mMagicPoints << endl << player.mMaxMagicPoints << endl
//        << player.mGold << endl << player.mAccuracy << endl << player.mExpPoints << endl << player.mNextLevelExp << endl << player.mLevel << endl;
//    return outFile;
//}
//ifstream& operator>>(ifstream& inFile, Player& player)
//{
//
//    inFile >> player.mWeapon
//        >> player.mArmor
//        >> player.mName >> player.mClassName >> player.mHitPoints >> player.mMaxHitPoints >> player.mMagicPoints >> player.mMaxMagicPoints
//        >> player.mGold >> player.mAccuracy >> player.mExpPoints >> player.mNextLevelExp >> player.mLevel;
//        
//    return inFile;
//
//
//
//}


// Constructor
Player::Player()
{
    mName = "Default";
    mClassName = "Default";
    mAccuracy = 0;
    mHitPoints = 0;
    mMaxHitPoints = 0;
    mMagicPoints = 0;
    mMaxMagicPoints = 0;
    mExpPoints = 0;
    mNextLevelExp = 0;
    mLevel = 0;
    mArmor.mName = "Default Armor";
    mArmor.mCost = 50;
    mArmor.armorRate = 0;
    mGold = 0;
    mWeapon.mName = "Default Weapon Name";
    mWeapon.mCost = 50;
    mWeapon.mDamageRange.mLow = 0;
    mWeapon.mDamageRange.mHigh = 0;
}
void Player::saveGame(Player& mainPlayer, Map& map, Inventory& inv)
{
    ofstream saveFile{ "gameSave.txt" };
    ofstream savePosition{ "posSave.txt" };
    ofstream saveInv{ "invSave.txt" };
    ofstream saveInvIndex{ "invIndexSave.txt" };

    if (!saveFile.is_open()) cout<<"Error saving Game";
    if (!savePosition.is_open()) cout << "Error saving position";
    if (!saveInv.is_open()) cout << "Error saving Inventory";
    if (!saveInvIndex.is_open()) cout << "Error saving InvIndex";
    saveFile << mainPlayer;
    savePosition << map;
    saveInv << inv;
    saveInvIndex << inv.mWeapon.size() << endl << inv.mArmor.size();


    saveFile.close();
    savePosition.close();
    saveInv.close();
    saveInvIndex.close();


}

void Player::loadGame(Player& mainPlayer, Map& map, Inventory& inv)
{
    ifstream saveFile{ "gameSave.txt" };
    ifstream savePosition{ "posSave.txt" };
    
    ifstream saveInv{ "invSave.txt" };

    if (!saveFile.is_open()) cout << "Error loading game";
    if (!savePosition.is_open()) cout << "Error loading Pos";
    if (!saveInv.is_open()) cout << "Error loading Inv";
    
     
    saveFile >> mainPlayer;
    savePosition >> map;
    saveInv >> inv;

}

// Check if the player is dead
bool Player::isDead()
{
    return mHitPoints <= 0;
}

// Get the player's name
std::string Player::getName()
{
    return mName;
}

//Get Gold
int Player::getGold()
{
    return mGold;
}
//Set Gold
void Player::setGold(int gold)
{
    mGold = gold;

}

// Get the player's armor value
int Player::getArmor()
{
    return mArmor.armorRate;
}

// Take damage
void Player::takeDamage(int damage)
{
    mHitPoints -= damage;
}

//Character generation Process
void Player::createClass()
{
    cout << "CHARACTER CLASS GENERATION" << endl;
    cout << "==========================" << endl;
    // Input character's name.
    cout << "Enter your character's name: ";
    getline(cin, mName);
    // Character selection.
    cout << "Please select a character class number..." << endl;
    cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";
    int characterNum = 1;
    cin >> characterNum;
    switch (characterNum)
    {
    case 1: // Fighter
        mClassName = "Fighter";
        mAccuracy = 10;
        mHitPoints = 20;
        mMaxHitPoints = 30;
        mMagicPoints = 30;
        mMaxMagicPoints = 20;
        mExpPoints = 0;
        mNextLevelExp = 1000;
        mLevel = 1;
        mArmor.mName = "Dirty mail";
        mArmor.armorRate = 4;
        mGold = 1000;
        mWeapon.mName = "Long Sword";
        mWeapon.mDamageRange.mLow = 1;
        mWeapon.mDamageRange.mHigh = 8;
        break;
    case 2: // Wizard
        mClassName = "Wizard";
        mAccuracy = 5;
        mHitPoints = 10;
        mMaxHitPoints = 10;
        mMagicPoints = 25;
        mMaxMagicPoints = 25;
        mExpPoints = 0;
        mNextLevelExp = 1000;
        mLevel = 1;
        mArmor.mName = "Dirty Cloak";
        mArmor.armorRate = 1;
        mGold = 1000;
        mWeapon.mName = "Staff";
        mWeapon.mDamageRange.mLow = 1;
        mWeapon.mDamageRange.mHigh = 4;
        break;
    case 3: // Cleric
        mClassName = "Cleric";
        mAccuracy = 8;
        mHitPoints = 15;
        mMaxHitPoints = 15;
        mMagicPoints = 15;
        mMaxMagicPoints = 15;
        mExpPoints = 0;
        mNextLevelExp = 1000;
        mLevel = 1;
        mArmor.mName = "Dirty Cloak";
        mArmor.armorRate = 3;
        mGold = 1000;
        mWeapon.mName = "Flail";
        mWeapon.mDamageRange.mLow = 1;
        mWeapon.mDamageRange.mHigh = 6;
        break;
    default: // Thief
        mClassName = "Thief";
        mAccuracy = 7;
        mHitPoints = 12;
        mMaxHitPoints = 12;
        mMagicPoints = 8;
        mMaxMagicPoints = 8;
        mExpPoints = 0;
        mNextLevelExp = 1000;
        mLevel = 1;
        mArmor.mName = "Dirty rug";
        mArmor.armorRate = 2;
        mGold = 1000;
        mWeapon.mName = "Short Sword";
        mWeapon.mDamageRange.mLow = 1;
        mWeapon.mDamageRange.mHigh = 6;
        break;
    }
}

// Attack a monster
struct Spell
{
    std::string mName;
    Range mDamageRange;
    int mMagicPointsRequired;
};
bool Player::attack(Monster& monster) {
    // Calculate damage based on weapon damage and accuracy
    int selection = 1;
    cout << "1) Attack, 2) Cast Spell, 3) Run Away: ";
    cin >> selection;
    switch (selection)
    {

    case 1:
    {
        cout << "You attack an " << monster.getName() << " with a " << mWeapon.mName
            << endl;
        if (Random(0, 12) < mAccuracy) {
            int damage = Random(mWeapon.mDamageRange);
            int totalDamage = damage - monster.getArmor();
            if (totalDamage <= 0) {
                cout << "Your attack failed to penetrate "
                    << "the armor." << endl;
            }
            else {
                cout << "You attack for " << totalDamage << " damage!" << endl;
                // Subtract from monster's hitpoints.
                monster.takeDamage(totalDamage);
            }
        }
        else {
            cout << "You miss!" << endl;
        }
        cout << endl;
        return false;

        break;
    }
    case 2:
    {
        //Use the struct spell from Player.h:
        //such as “magic missile,” “fireball,” and “shield.”
        //The player can select a spell from the list of spells in his/her spell book.
        //Be sure to verify that the player has enough magic points to cast the spell.
        //And also be sure to deduct the magic points required to cast the spell from the 
        cout << "Magicpoints = " << mMagicPoints << endl;
        cout << "MaxMagicpoints = " << mMaxMagicPoints << endl;
        cout << "Select the Spell you want to cast" << endl;
        cout << "1) Magic Missile" << endl;
        cout << "2) Fireball" << endl;
        cout << "3) Shield" << endl;
        int spellNum = 0;
        cin >> spellNum;
        //Create the spell struct:
        //Magic Missile 9-14 Damage
        //Fireball 7-12 Damage
        //Shield: 5-9 Damage
        //User nested if instead of switch
        if (spellNum == 1)
        {
            //Create Spell
            Spell magicMissile;
            magicMissile.mName = "Magic Missile";
            magicMissile.mDamageRange.mLow = 20;
            magicMissile.mDamageRange.mHigh = 30;
            magicMissile.mMagicPointsRequired = 5;
            //Check if player has enough magic points
            if (mMagicPoints >= magicMissile.mMagicPointsRequired)
            {
                //Subtract magic points
                mMagicPoints -= magicMissile.mMagicPointsRequired;
                //Calculate damage
                int damage = Random(magicMissile.mDamageRange);
                int totalDamage = damage - monster.getArmor();
                if (totalDamage <= 0)
                {
                    cout << "Your attack failed to penetrate "
                        << "the armor." << endl;

                }
                else {
                    cout << "You attack for " << totalDamage << " damage!" << endl;
                    // Subtract from monster's hitpoints.
                    monster.takeDamage(totalDamage);

                }

            }
            else {
                cout << "You don't have enough magic points to cast this spell" << endl;

            }


        }
        else if (spellNum == 2)
        {
            //Create Spell
            Spell fireball;
            fireball.mName = "Fireball";
            fireball.mDamageRange.mLow = 7;
            fireball.mDamageRange.mHigh = 12;
            fireball.mMagicPointsRequired = 5;
            //Check if player has enough magic points
            if (mMagicPoints >= fireball.mMagicPointsRequired)
            {
                //Subtract magic points
                mMagicPoints -= fireball.mMagicPointsRequired;
                //Calculate damage
                int damage = Random(fireball.mDamageRange);
                int totalDamage = damage - monster.getArmor();
                if (totalDamage <= 0)
                {
                    cout << "Your attack failed to penetrate "
                        << "the armor." << endl;

                }
                else {
                    cout << "You attack for " << totalDamage << " damage!" << endl;
                    // Subtract from monster's hitpoints.
                    monster.takeDamage(totalDamage);

                }

            }
            else {
                cout << "You don't have enough magic points to cast this spell" << endl;

            }

        }
        else if (spellNum == 3)
        {
            //Create Spell
            Spell shield;
            shield.mName = "Shield";
            shield.mDamageRange.mLow = 5;
            shield.mDamageRange.mHigh = 9;
            shield.mMagicPointsRequired = 5;
            //Check if player has enough magic points
            if (mMagicPoints >= shield.mMagicPointsRequired)
            {
                //Subtract magic points
                mMagicPoints -= shield.mMagicPointsRequired;
                //Calculate damage
                int damage = Random(shield.mDamageRange);
                int totalDamage = damage - monster.getArmor();
                if (totalDamage <= 0)
                {
                    cout << "Your attack failed to penetrate "
                        << "the armor." << endl;

                }
                else {
                    cout << "You attack for " << totalDamage << " damage!" << endl;
                    // Subtract from monster's hitpoints.
                    monster.takeDamage(totalDamage);

                }

            }
            else {
                cout << "You don't have enough magic points to cast this spell" << endl;

            }

        }
        else {
            cout << "Invalid spell selection" << endl;
        }




        return false;
        break;


    }



    case 3:
    {
        // 25 % chance of being able to run.
        if (Random(0, 4) < 1)
        {
            cout << "You successfully ran away!" << endl;
            return true;

        }
        else {
            cout << "You failed to run away!" << endl;
            return false;


        }
        break;
    }
    default:
        cout << "You do nothing!" << endl;
        return false;
        break;
    }

}
// Level up the player
void Player::levelUp()
{
    if (mExpPoints >= mNextLevelExp)
    {
        cout << "You gained a level!" << endl;
        // Increment level.
        mLevel++;
        //increase the amount of magic points when the character levels up:
        mMaxHitPoints += 5;
        mHitPoints = mMaxHitPoints;

        // Set experience points required for next level.
        mNextLevelExp = mLevel * mLevel * 1000;

        //Magic Points
        mMaxMagicPoints += 5;
        mMagicPoints = mMaxMagicPoints;
    }
}

//Simulate random battle
int Player::getHitPoints()
{
    return mHitPoints;

}
// Rest to recover hit points
void Player::rest(Map& gameMap)
{
    cout << "Resting..." << endl;
    mHitPoints = mMaxHitPoints;
    mMagicPoints = mMaxMagicPoints;
    //25% chance of random Encounter:
    if (Random(0, 4) < 1)
    {
        Monster* monster = gameMap.checkRandomEncounter();
        if (monster != nullptr)
        {
            cout << "You are attacked by a " << monster->getName() << "!" << endl;
            //Battle using Map::battle
            gameMap.battle(*this, *monster, gameMap);




        }
        //Delete Monster:




    }

}

// View player stats
void Player::viewStats()
{
    cout << "PLAYER STATS" << endl;
    cout << "============" << endl;
    cout << endl;

    cout << "Name = " << mName << endl;
    cout << "Class = " << mClassName << endl;
    cout << "Accuracy = " << mAccuracy << endl;
    cout << "Hitpoints = " << mHitPoints << endl;
    cout << "MaxHitpoints = " << mMaxHitPoints << endl;
    cout << "Magicpoints = " << mMagicPoints << endl;
    cout << "MaxMagicpoints = " << mMaxMagicPoints << endl;
    cout << "XP = " << mExpPoints << endl;
    cout << "XP for Next Lvl = " << mNextLevelExp << endl;
    cout << "Level = " << mLevel << endl;
    cout << "Armor = " << mArmor.armorRate << endl;
    cout << "Gold = " << mGold << endl;
    cout << "Weapon Name = " << mWeapon.mName << endl;
    cout << "Weapon Damage = " << mWeapon.mDamageRange.mLow
        << "-" << mWeapon.mDamageRange.mHigh << endl;
    cout << endl;
    cout << "END PLAYER STATS" << endl;
    cout << "================" << endl;
    cout << endl;
}

// Handle victory (after defeating a monster)
void Player::victory(int xp)
{
    cout << "You won the battle!" << endl;
    cout << "You win " << xp
        << " experience points!" << endl << endl;
    mExpPoints += xp;
    //Gold winnings:
    //Gold winning having fought a goblin:
    if (xp >= 100)
    {
        mGold += 100;
        cout << "You gained 100 gold!" << endl;

    }
    //Gold winning having fought an orc:
    else if (xp >= 200)
    {
        mGold += 200;
        cout << "You gained 200 gold!" << endl;

    }
    //Gold winning having fought an Ogre:
    else if (xp >= 500)
    {
        mGold += 500;
        cout << "You gained 500 gold!" << endl;

    }
    //Gold winning having fought a Orc Lord:
    else if (xp >= 1000)
    {
        mGold += 1000;
        cout << "You gained 1000 gold!" << endl;

    }
}

// Handle game over
void Player::gameover()
{
    cout << "You died in battle..." << endl;
    cout << endl;
    cout << "================================" << endl;
    cout << "GAME OVER!" << endl;
    cout << "================================" << endl;
    cout << "Press 'q' to quit: ";
    char q = 'q';
    cin >> q;
    if (q == 'q')
    {
        exit(0);
    }
    cout << endl;
}

// Display the player's hit points
void Player::displayHitPoints()
{
    cout << mName << "'s hitpoints = " << mHitPoints << endl;
}


void Player::equipWeapon(Inventory& inv, Weapon& weapon)
{
    inv.addWeapon(mWeapon);
    mWeapon = weapon;

}
void Player::equipArmor(Inventory& inv, Armor& armor)
{
    inv.addArmor(mArmor);
    mArmor = armor;

}
void Player::takePotion() {
    mHitPoints = mMaxHitPoints;
}