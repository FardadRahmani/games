// game.cpp
#include "Map.h"
#include "Player.h"
#include "Inventory.h"
#include "Shop.h"
#include "Item.h"
#include "OperatorOverloading.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

struct Spell
{
    std::string mName;
    Range mDamageRange;
    int mMagicPointsRequired;
};

//write a minigame inside the game using enum and state machine:
enum States {
    Jump = 1,
    Stand = 2,
    Duck = 3,
    Crouch = 4,
    JumpAttack = 5,
    DuckAttack = 6
};


int main()
{
    srand(time(0));

    Map gameMap;
    Player mainPlayer;
    mainPlayer.createClass();

    //create State:
    States playerState = Jump;

    //create Inventory usinh Inventory.h:
    Inventory playerInv;

    // Create Shop using shop.h:
    Shop shop;
    //Create some weapons and armor for the shop and set price:
    Weapon longSword;
    longSword.mName = "Long Sword";
    longSword.mDamageRange.mLow = 10;
    longSword.mDamageRange.mHigh = 20;
    longSword.mCost = 100;
    Armor scaleShield;
    scaleShield.mName = "Scale Shield";
    scaleShield.armorRate = 7;
    scaleShield.mCost = 100;
    Potion healthPotion;
    healthPotion.mName = "Health Potion";
    healthPotion.potionRate = 10;
    healthPotion.mCost = 100;
    //Add the weapons and armor to the shop:

    shop.addWeapon(longSword);
    shop.addArmor(scaleShield);
    shop.addPotion(healthPotion);


    // Begin adventure.
    bool done = false;
    while (!done)
    {
        // Each loop cycly we output the player position and
        // a selection menu.
        gameMap.printPlayerPos();
        int selection = 1;
        cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: 5) View Inventory 6)Play Minigame 7)Save Game 8)Load Game" << endl;
        cin >> selection;
        Monster* monster = 0;
        switch (selection)
        {
        case 1:
            // Move the player.
            gameMap.movePlayer();
            if (gameMap.getPlayerXPos() == 2 &&
                gameMap.getPlayerYPos() == 3)
            {

                //Display the shop:       

                shop.printShop();

                cout << "What would you like to buy?";

                int selection;
                cin >> selection;
                while (selection != 5)
                {


                    switch (selection)
                    {
                    case 1:
                        //Buy Weapon:
                        playerInv.addWeapon(longSword);
                        cout << "You bought a " << longSword.mName << " for " << longSword.mCost << " gold." << endl;
                        //Remove gold:
                        mainPlayer.setGold(mainPlayer.getGold() - longSword.mCost);

                        break;
                    case 2:
                        //Buy Armor:
                        playerInv.addArmor(scaleShield);
                        cout << "You bought a " << scaleShield.mName << " for " << scaleShield.mCost << " gold." << endl;
                        //Remove gold:
                        mainPlayer.setGold(mainPlayer.getGold() - scaleShield.mCost);
                        break;
                    case 3:
                        //Buy Potion:
                        playerInv.addPotion(healthPotion);
                        cout << "You bought a " << healthPotion.mName << " for " << healthPotion.mCost << " gold." << endl;
                        //Remove gold:
                        mainPlayer.setGold(mainPlayer.getGold() - healthPotion.mCost);
                        break;
                    case 4:
                        //Sell Weapon:
                        cout << "Selling is not possible yet" << endl;
                        break;








                    }
                    cout << "What would you like to buy?";
                    cin >> selection;

                }


            }


            //Ende Shop-whiel




       //Ende Shop Schleife------------------------------   

        // Check for a random encounter. This function
        // returns a null pointer if no monsters are
        // encountered.
            monster = gameMap.checkRandomEncounter();
            // 'monster' not null, run combat simulation.

            if (monster != 0)
            {
                //Battle loop using Map::battle method:
                gameMap.battle(mainPlayer, *monster, gameMap);




                /*
                // Loop until a 'break' statement.
                while (true)
                {
                  // Display hitpoints.
                  mainPlayer.displayHitPoints();
                  monster->displayHitPoints();
                  cout << endl;
                  // Player's turn to attack first.
                  bool runAway = mainPlayer.attack(*monster);
                  //if (runAway)
                  //	break;
                  if (monster->isDead())
                  {
                    mainPlayer.victory(monster->getXPReward());
                    mainPlayer.levelUp();
                    break;
                  }
                  monster->attack(mainPlayer);
                  if (mainPlayer.isDead())
                  {
                    mainPlayer.gameover();
                    done = true;
                    break;
                  }
                }
                */
                // The pointer to a monster returned from
                // checkRandomEncounter was allocated with
                // 'new', so we must delete it to avoid
                // memory leaks.
                delete monster;
                monster = 0;
            }
            break;
        case 2:
            mainPlayer.rest(gameMap);
            break;
        case 3:
            mainPlayer.viewStats();
            break;
        case 4:

            done = true;
            break;

        case 5:
        {
            //Display inventory:
            int invSelect = 5;
            while (invSelect != 4)
            {
                playerInv.printInventory();
                cout << "would you like to use/equip an Item?";
                cin >> selection;
                switch (selection)
                {
                case 1:
                    //Use Weapon:
                    cout << "Which weapon would you like to equip?";
                    cin >> selection;
                    mainPlayer.equipWeapon(playerInv, playerInv.getWeapon()[selection - 1]);
                    break;
                case 2:
                    //Use Armor:
                    cout << "Which armor would you like to equip?";
                    cin >> selection;
                    mainPlayer.equipArmor(playerInv, playerInv.getArmor()[selection - 1]);
                    break;
                case 3:
                    //Use Potion:
                    cout << "Which potion would you like to use?";
                    cin >> selection;
                    mainPlayer.takePotion();
                    break;
                case 4:
                    //Leave Inventory:
                    invSelect = 4;

                    break;


                }
            }



            break;
        }
        case 6:
        {
            //Play minigame: 
            cout << "You are in a minigame" << endl;
            int statechange = 0;
            int minigameSelect = 5;
            States RabbitState = Jump;
            while (minigameSelect != 7)
            {
                cout << "1) Jump, 2) Stand, 3) Duck, 4) Crouch, 5) Jump Attack, 6) Duck Attack";
                cout << "Do as the rabbit does" << endl;
                //Player lands on jump first, 
                //In each state the rabbit will change its state randomly
                //The player will have to change the state to match the rabbit
                //If the player does not imitate the rabbit's state correctly, game is finished
                //If the player imitates the rabbit's state correctly, the player will move to the next state
                //If the player imitates rabbit 5 times correctly, the player will win 200 Gold
                //If the player imitates rabbit 10 times correctly, the player will win 500 Gold
                //If the player imitates rabbit 20 times correctly, the player will win 700 Gold
                //If the player imitates rabbit 30 times correctly, the player will win 1000 Gold

                int counter = 0;
                switch (playerState)
                {
                case Jump:
                    //RabbitState = Jump;

                    cout << "You are Jumping" << endl;

                    cout << "The rabbit is now " << RabbitState << endl;
                    if (RabbitState == playerState)
                    {
                        cout << "You are in the same state as the rabbit" << endl;
                        counter++;
                        if (counter == 5)
                            mainPlayer.setGold(mainPlayer.getGold() + 200);
                        if (counter == 10)
                            mainPlayer.setGold(mainPlayer.getGold() + 500);
                        if (counter == 20)
                            mainPlayer.setGold(mainPlayer.getGold() + 700);
                        if (counter == 30)
                            mainPlayer.setGold(mainPlayer.getGold() + 1000);

                    }
                    else {
                        cout << "You are not in the same state as the rabbit" << endl;
                        minigameSelect = 7;
                        break;

                    }
                    //Change rabbits state randomly:
                    RabbitState = (States)(1 + rand() % 6);
                    //Display the rabbit's state:
                    cout << "The rabbit is now " << RabbitState << endl;

                    cin >> statechange;

                    if (statechange == 2)
                        playerState = Stand;
                    else if (statechange == 3)
                        playerState = Duck;
                    else if (statechange == 4)
                        playerState = Crouch;
                    else if (statechange == 5)
                        playerState = JumpAttack;
                    else if (statechange == 6)
                        playerState = DuckAttack;
                    else if (statechange == 1)
                        playerState = Jump;

                    break;

                case Stand:

                    cout << "You are Standing" << endl;
                    cout << "The rabbit is now " << RabbitState << endl;

                    if (RabbitState == playerState)
                    {
                        cout << "You are in the same state as the rabbit" << endl;
                        counter++;
                        if (counter == 5)
                            mainPlayer.setGold(mainPlayer.getGold() + 200);
                        if (counter == 10)
                            mainPlayer.setGold(mainPlayer.getGold() + 500);
                        if (counter == 20)
                            mainPlayer.setGold(mainPlayer.getGold() + 700);
                        if (counter == 30)
                            mainPlayer.setGold(mainPlayer.getGold() + 1000);

                    }
                    else {
                        cout << "You are not in the same state as the rabbit" << endl;
                        minigameSelect = 7;
                        break;

                    }
                    //Change rabbits state randomly:
                    RabbitState = (States)(rand() % 6);
                    //Display the rabbit's state:
                    cout << "The rabbit is now " << RabbitState << endl;


                    cin >> statechange;
                    if (statechange == 2)
                        playerState = Stand;
                    else if (statechange == 3)
                        playerState = Duck;
                    else if (statechange == 4)
                        playerState = Crouch;
                    else if (statechange == 5)
                        playerState = JumpAttack;
                    else if (statechange == 6)
                        playerState = DuckAttack;
                    else if (statechange == 1)
                        playerState = Jump;
                    break;
                case Duck:
                    cout << "You are Ducking" << endl;
                    cout << "The rabbit is now " << RabbitState << endl;

                    if (RabbitState == playerState)
                    {
                        cout << "You are in the same state as the rabbit" << endl;
                        counter++;
                        if (counter == 5)
                            mainPlayer.setGold(mainPlayer.getGold() + 200);
                        if (counter == 10)
                            mainPlayer.setGold(mainPlayer.getGold() + 500);
                        if (counter == 20)
                            mainPlayer.setGold(mainPlayer.getGold() + 700);
                        if (counter == 30)
                            mainPlayer.setGold(mainPlayer.getGold() + 1000);

                    }
                    else {
                        cout << "You are not in the same state as the rabbit" << endl;
                        minigameSelect = 7;
                        break;

                    }
                    //Change rabbits state randomly:
                    RabbitState = (States)(1 + rand() % 6);
                    //Display the rabbit's state:
                    cout << "The rabbit is now " << RabbitState << endl;


                    cin >> statechange;
                    if (statechange == 2)
                        playerState = Stand;
                    else if (statechange == 3)
                        playerState = Duck;
                    else if (statechange == 4)
                        playerState = Crouch;
                    else if (statechange == 5)
                        playerState = JumpAttack;
                    else if (statechange == 6)
                        playerState = DuckAttack;
                    else if (statechange == 1)
                        playerState = Jump;
                    break;
                case Crouch:
                    cout << "You are Crouching" << endl;
                    cout << "The rabbit is now " << RabbitState << endl;

                    if (RabbitState == playerState)
                    {
                        cout << "You are in the same state as the rabbit" << endl;
                        counter++;
                        if (counter == 5)
                            mainPlayer.setGold(mainPlayer.getGold() + 200);
                        if (counter == 10)
                            mainPlayer.setGold(mainPlayer.getGold() + 500);
                        if (counter == 20)
                            mainPlayer.setGold(mainPlayer.getGold() + 700);
                        if (counter == 30)
                            mainPlayer.setGold(mainPlayer.getGold() + 1000);

                    }
                    else {
                        cout << "You are not in the same state as the rabbit" << endl;
                        minigameSelect = 7;
                        break;

                    }
                    //Change rabbits state randomly:
                    RabbitState = (States)(1 + rand() % 6);
                    //Display the rabbit's state:
                    cout << "The rabbit is now " << RabbitState << endl;


                    cin >> statechange;
                    if (statechange == 2)
                        playerState = Stand;
                    else if (statechange == 3)
                        playerState = Duck;
                    else if (statechange == 4)
                        playerState = Crouch;
                    else if (statechange == 5)
                        playerState = JumpAttack;
                    else if (statechange == 6)
                        playerState = DuckAttack;
                    else if (statechange == 1)
                        playerState = Jump;
                    break;
                case JumpAttack:
                    cout << "You are Jump Attacking" << endl;
                    cout << "The rabbit is now " << RabbitState << endl;

                    if (RabbitState == playerState)
                    {
                        cout << "You are in the same state as the rabbit" << endl;
                        counter++;
                        if (counter == 5)
                            mainPlayer.setGold(mainPlayer.getGold() + 200);
                        if (counter == 10)
                            mainPlayer.setGold(mainPlayer.getGold() + 500);
                        if (counter == 20)
                            mainPlayer.setGold(mainPlayer.getGold() + 700);
                        if (counter == 30)
                            mainPlayer.setGold(mainPlayer.getGold() + 1000);

                    }
                    else {
                        cout << "You are not in the same state as the rabbit" << endl;
                        minigameSelect = 7;
                        break;

                    }
                    //Change rabbits state randomly:
                    RabbitState = (States)(1 + rand() % 6);
                    //Display the rabbit's state:
                    cout << "The rabbit is now " << RabbitState << endl;


                    cin >> statechange;
                    if (statechange == 2)
                        playerState = Stand;
                    else if (statechange == 3)
                        playerState = Duck;
                    else if (statechange == 4)
                        playerState = Crouch;
                    else if (statechange == 5)
                        playerState = JumpAttack;
                    else if (statechange == 6)
                        playerState = DuckAttack;
                    else if (statechange == 1)
                        playerState = Jump;
                    break;
                case DuckAttack:
                    cout << "You are Duck Attacking" << endl;
                    cout << "The rabbit is now " << RabbitState << endl;

                    if (RabbitState == playerState)
                    {
                        cout << "You are in the same state as the rabbit" << endl;
                        counter++;
                        if (counter == 5)
                            mainPlayer.setGold(mainPlayer.getGold() + 200);
                        if (counter == 10)
                            mainPlayer.setGold(mainPlayer.getGold() + 500);
                        if (counter == 20)
                            mainPlayer.setGold(mainPlayer.getGold() + 700);
                        if (counter == 30)
                            mainPlayer.setGold(mainPlayer.getGold() + 1000);

                    }
                    else {
                        cout << "You are not in the same state as the rabbit" << endl;
                        minigameSelect = 7;
                        break;

                    }
                    //Change rabbits state randomly:
                    RabbitState = (States)(1 + rand() % 6);
                    //Display the rabbit's state:
                    cout << "The rabbit is now " << RabbitState << endl;


                    cin >> statechange;
                    if (statechange == 2)
                        playerState = Stand;
                    else if (statechange == 3)
                        playerState = Duck;
                    else if (statechange == 4)
                        playerState = Crouch;
                    else if (statechange == 5)
                        playerState = JumpAttack;
                    else if (statechange == 6)
                        playerState = DuckAttack;
                    else if (statechange == 1)
                        playerState = Jump;

                    break;







                }


            } //End of while (minigameSelect != 7)

            break;
        }// End of case 6
          //Save the player's data to a file (case 7)
        case 7:
            //Save the player's data to a file
            mainPlayer.saveGame(mainPlayer, gameMap, playerInv);
            cout << "Game Saved" << endl;
            break;
            //Load the player's data from a file (case 8)
        case 8:
            //Load the player's data from a file
            mainPlayer.loadGame(mainPlayer, gameMap, playerInv);
            break;









            /*case 5:

              done = true;
              break;
            case 6:

              done = true;
              break;*/
        }// End Switch Statement

    }// End While Statement

    return 0;
}// End main function.