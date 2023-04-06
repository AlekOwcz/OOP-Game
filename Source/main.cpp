#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
#include "Headers/CharacterClass.h"
#include "Headers/MagicChar.h"
#include "Headers/MeleeChar.h"
#include "Headers/RangedChar.h"
#include "Headers/Weapon.h"
#include "Headers/MagicWeapon.h"
#include "Headers/MeleeWeapon.h"
#include "Headers/RangedWeapon.h"
#include "Headers/SaveGame.h"

#define CONSOLE_CLEAR "cls"
#define MAGICCHAR 1
#define RANGEDCHAR 2
#define MELEECHAR 3
//std::this_thread::sleep_for(std::chrono::milliseconds(x));

std::string listCharacters(std::vector<CharacterClass*>& Characters, int classType, int pointer){
    std::string list;
    int i = 1;
    int j = (classType - 1) * 3;
    for (j; j < (classType - 1) * 3 + 3; j++) {
        list+=std::to_string(i++);
        list+=". ";
        list+=Characters[j]->getName();
        if(pointer == j) list += " <\n";
        else list+='\n';
    }
    if (pointer == -2) list += "\nb. Back <\n";
    else list += "\nb. Back\n";
    return list;
}

std::string listWeapons(std::vector<Weapon*>& Weapons, int weaponType, int pointer) {
    std::string list;
    int i = 1;
    int j = (weaponType - 1) * 3;
    for (j; j < (weaponType - 1) * 3 + 3; j++) {
        list += std::to_string(i++);
        list += ". ";
        list += Weapons[j]->getName();
        if (pointer == j) list += " <\n";
        else list += '\n';
    }
    if(pointer == -2) list += "\nb. Back <\n";
    else list += "\nb. Back\n";
    
    return list;
}

void newGame(std::vector<CharacterClass*>& Classes, std::vector<Weapon*>& Weapons, SavedGame* saved_game = nullptr) {
    CharacterClass* Player1,
        * Player2;
    Weapon* Player1Weapon,
        * Player2Weapon;
    int player1Choice = -1,
        player2Choice = -1,
        player1UsedAbility = 0,
        player2UsedAbility = 0;
    double player1Attack = -1, player1Defence = -1,
        player2Attack = -1, player2Defence = -1,
        player1DamageTaken = -1,
        player2DamageTaken = -1;

    char ct, cc;
    int c1_c, c1_w, c2_c, c2_w;
    int classType;
    int picked;

    if (saved_game == nullptr)
    {
        while (1) {
            picked = 1;
            system(CONSOLE_CLEAR);
            std::cout << "Player 1 - Pick your fighter: \n" << "1. Magic Classes\n" << "2. Ranged Classes\n" << "3. Melee Classes\n";
            ct = _getch();
            classType = atoi(&ct);
            if (classType == 1 || classType == 2 || classType == 3) {
                switch (classType) {
                case 1:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1 - Pick your fighter: \n" << "1. Magic Classes <\n" << "2. Ranged Classes\n" << "3. Melee Classes\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 2:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1 - Pick your fighter: \n" << "1. Magic Classes\n" << "2. Ranged Classes <\n" << "3. Melee Classes\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 3:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1 - Pick your fighter: \n" << "1. Magic Classes\n" << "2. Ranged Classes\n" << "3. Melee Classes <\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                }
                while (1) {
                    system(CONSOLE_CLEAR);
                    std::cout << listCharacters(Classes, classType, -1);
                    cc = _getch();
                    switch (cc) {
                    case '1':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, (classType - 1) * 3);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c1_c = (classType - 1) * 3;
                        break;
                    case '2':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, (classType - 1) * 3 + 1);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c1_c = (classType - 1) * 3 + 1;
                        break;
                    case '3':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, (classType - 1) * 3 + 2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c1_c = (classType - 1) * 3 + 2;
                        break;
                    case 'b':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, -2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        picked = 0;
                        break;
                    default:
                        continue;
                    }
                    break;
                }
            }
            else continue;

            if (picked == 0) continue;
            else break;
        }
    }
    else
    {
        c1_c = saved_game->getCharacter(1);
    }
    switch (c1_c) {
        case 0:
        case 1:
        case 2:
            Player1 = new MagicChar(Classes[c1_c]);
            break;
        case 3:
        case 4:
        case 5:
            Player1 = new RangedChar(Classes[c1_c]);
            break;
        case 6:
        case 7:
        case 8:
            Player1 = new MeleeChar(Classes[c1_c]);
            break;
        default:
            Player1 = new MagicChar(Classes[0]);
    }
    
    int weaponType;
    if (saved_game == nullptr)
    {
        while (1) {
            picked = 1;
            system(CONSOLE_CLEAR);
            std::cout << "Player 1 - Pick a weapon: \n" << "1. Magic Weapons\n" << "2. Ranged Weapons\n" << "3. Melee Weapons\n";
            ct = _getch();
            weaponType = atoi(&ct);
            if (weaponType == 1 || weaponType == 2 || weaponType == 3) {
                switch (weaponType) {
                case 1:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1 - Pick a weapon: \n" << "1. Magic Weapons <\n" << "2. Ranged Weapons\n" << "3. Melee Weapons\n";                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 2:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1 - Pick a weapon: \n" << "1. Magic Weapons\n" << "2. Ranged Weapons <\n" << "3. Melee Weapons\n";                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 3:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1 - Pick a weapon: \n" << "1. Magic Weapons\n" << "2. Ranged Weapons\n" << "3. Melee Weapons <\n";                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                }
                while (1) {
                    system(CONSOLE_CLEAR);
                    std::cout << listWeapons(Weapons, weaponType, -1);
                    cc = _getch();
                    switch (cc) {
                    case '1':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, (weaponType - 1) * 3);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c1_w = (weaponType - 1) * 3;
                        break;
                    case '2':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, (weaponType - 1) * 3 + 1);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c1_w = (weaponType - 1) * 3 + 1;
                        break;
                    case '3':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, (weaponType - 1) * 3 + 2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c1_w = (weaponType - 1) * 3 + 2;
                        break;
                    case 'b':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, -2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        picked = 0;
                        break;
                    default:
                        continue;
                    }
                    break;
                }
            }
            else continue;

            if (picked == 0) continue;
            else break;
        }
    }
    else
    {
        c1_w = saved_game->getWeapon(1);
    }

    switch (c1_w) {
        case 0:
        case 1:
        case 2:
            Player1Weapon = Weapons[c1_w];
            break;
        case 3:
        case 4:
        case 5:
            Player1Weapon = Weapons[c1_w];
            break;
        case 6:
        case 7:
        case 8:
            Player1Weapon = Weapons[c1_w];
            break;
        default:
            Player1Weapon = Weapons[0];
    }

    if (saved_game == nullptr)
    {
        while (1) {
            system(CONSOLE_CLEAR);
            std::cout << "Player 2 - Pick your fighter: \n" << "1. Magic Classes\n" << "2. Ranged Classes\n" << "3. Melee Classes\n";
            ct = _getch();
            classType = atoi(&ct);
            if (classType == 1 || classType == 2 || classType == 3) {
                switch (classType) {
                case 1:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2 - Pick your fighter: \n" << "1. Magic Classes <\n" << "2. Ranged Classes\n" << "3. Melee Classes\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 2:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2 - Pick your fighter: \n" << "1. Magic Classes\n" << "2. Ranged Classes <\n" << "3. Melee Classes\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 3:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2 - Pick your fighter: \n" << "1. Magic Classes\n" << "2. Ranged Classes\n" << "3. Melee Classes <\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                }
                while (1) {
                    system(CONSOLE_CLEAR);
                    std::cout << listCharacters(Classes, classType, -1);
                    cc = _getch();
                    switch (cc) {
                    case '1':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, (classType - 1) * 3);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c2_c = (classType - 1) * 3;
                        break;
                    case '2':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, (classType - 1) * 3 + 1);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c2_c = (classType - 1) * 3 + 1;
                        break;
                    case '3':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, (classType - 1) * 3 + 2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c2_c = (classType - 1) * 3 + 2;
                        break;
                    case 'b':
                        system(CONSOLE_CLEAR);
                        std::cout << listCharacters(Classes, classType, -2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        picked = 0;
                        break;
                    default:
                        continue;
                    }
                    break;
                }
            }
            else continue;

            if (picked == 0) continue;
            else break;
        }
    }
    else
    {
        c2_c = saved_game->getCharacter(2);
    }

    switch (c2_c) {
        case 0:
        case 1:
        case 2:
            Player2 = new MagicChar(Classes[c2_c]);
            break;
        case 3:
        case 4:
        case 5:
            Player2 = new RangedChar(Classes[c2_c]);
            break;
        case 6:
        case 7:
        case 8:
            Player2 = new MeleeChar(Classes[c2_c]);
            break;
        default:
            Player2 = new MagicChar(Classes[0]);
    }

    if (saved_game == nullptr)
    {
        while (1) {
            picked = 1;
            system(CONSOLE_CLEAR);
            std::cout << "Player 2 - Pick a weapon: \n" << "1. Magic Weapons\n" << "2. Ranged Weapons\n" << "3. Melee Weapons\n";
            ct = _getch();
            weaponType = atoi(&ct);
            if (weaponType == 1 || weaponType == 2 || weaponType == 3) {
                switch (weaponType) {
                case 1:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2 - Pick a weapon: \n" << "1. Magic Weapons <\n" << "2. Ranged Weapons\n" << "3. Melee Weapons\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 2:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2 - Pick a weapon: \n" << "1. Magic Weapons\n" << "2. Ranged Weapons <\n" << "3. Melee Weapons\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                case 3:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2 - Pick a weapon: \n" << "1. Magic Weapons\n" << "2. Ranged Weapons\n" << "3. Melee Weapons <\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    break;
                }
                while (1) {
                    system(CONSOLE_CLEAR);
                    std::cout << listWeapons(Weapons, weaponType, -1);
                    cc = _getch();
                    switch (cc) {
                    case '1':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, (weaponType - 1) * 3);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c2_w = (weaponType - 1) * 3;
                        break;
                    case '2':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, (weaponType - 1) * 3 + 1);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c2_w = (weaponType - 1) * 3 + 1;
                        break;
                    case '3':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, (weaponType - 1) * 3 + 2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        c2_w = (weaponType - 1) * 3 + 2;
                        break;
                    case 'b':
                        system(CONSOLE_CLEAR);
                        std::cout << listWeapons(Weapons, weaponType, -2);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        picked = 0;
                        break;
                    default:
                        continue;
                    }
                    break;
                }
            }
            else continue;

            if (picked == 0) continue;
            else break;
        }
    }
    else
    {
        c2_w = saved_game->getWeapon(2);
    }

    switch (c2_w) {
    case 0:
    case 1:
    case 2:
        Player2Weapon = Weapons[c2_w];
        break;
    case 3:
    case 4:
    case 5:
        Player2Weapon = Weapons[c2_w];
        break;
    case 6:
    case 7:
    case 8:
        Player2Weapon = Weapons[c2_w];
        break;
    default:
        Player2Weapon = Weapons[0];
    }

    char action, continuation;
    float ability1, ability2;
    int doubled1 = 0, doubled2 = 0;
    if (saved_game != nullptr)
    {
        Player1->loadHP(saved_game->getHP(1));
        Player2->loadHP(saved_game->getHP(2));
        player1UsedAbility = saved_game->getUsedAbility(1);
        player2UsedAbility = saved_game->getUsedAbility(2);
    }

    while (Player1->getHP() > 0 && Player2->getHP() > 0) {
        while (1) {
            system(CONSOLE_CLEAR);
            std::cout << "Player 1, what do you want to do?\n" << "1. Attack\n" << "2. Defend\n" << "3. Use class ability.\n";
            action = _getch();
            player1Choice = atoi(&action);
            switch (player1Choice) {
                case 1:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1, what do you want to do?\n" << "1. Attack <\n" << "2. Defend\n" << "3. Use class ability.\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    player1Attack = Player1->getAttack(player1Choice, Player1Weapon);
                    player1Defence = Player1->getDefence(player1Choice, Player1Weapon);
                    break;
                case 2:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 1, what do you want to do?\n" << "1. Attack\n" << "2. Defend <\n" << "3. Use class ability.\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    player1Attack = Player1->getAttack(player1Choice, Player1Weapon);
                    player1Defence = Player1->getDefence(player1Choice, Player1Weapon);
                    break;
                case 3:
                    if (player1UsedAbility >= 2) {
                        system(CONSOLE_CLEAR);
                        std::cout << "Player 1, what do you want to do?\n" << "1. Attack\n" << "2. Defend\n" << "3. Use class ability. X\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        continue;
                    }
                    else {
                        system(CONSOLE_CLEAR);
                        std::cout << "Player 1, what do you want to do?\n" << "1. Attack\n" << "2. Defend\n" << "3. Use class ability. <\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        player1UsedAbility++;
                        ability1 = Player1->useAbility(Player1Weapon);
                        player1Attack = Player1->getAttack(player1Choice, Player1Weapon);
                        player1Defence = Player1->getDefence(player1Choice, Player1Weapon);
                        if (Player1->getAbility() == 3) Player1->setDEF(-1*(static_cast<int>(ability1)));
                        if (Player1->getAbility() == 2) doubled1++;
                        break;
                    }
                default:
                    continue;
            }
            system(CONSOLE_CLEAR);
            break;
        }
        while (1) {
            system(CONSOLE_CLEAR);
            std::cout << "Player 2, what do you want to do?\n" << "1. Attack\n" << "2. Defend\n" << "3. Use class ability.\n";
            action = _getch();
            player2Choice = atoi(&action);
            switch (player2Choice) {
                case 1:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2, what do you want to do?\n" << "1. Attack <\n" << "2. Defend\n" << "3. Use class ability.\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    player2Attack = Player2->getAttack(player2Choice, Player2Weapon);
                    player2Defence = Player2->getDefence(player2Choice, Player2Weapon);
                    break;
                case 2:
                    system(CONSOLE_CLEAR);
                    std::cout << "Player 2, what do you want to do?\n" << "1. Attack\n" << "2. Defend <\n" << "3. Use class ability.\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    player2Attack = Player2->getAttack(player2Choice, Player2Weapon);
                    player2Defence = Player2->getDefence(player2Choice, Player2Weapon);
                    break;
                case 3:
                    if (player2UsedAbility >= 2) {
                        system(CONSOLE_CLEAR);
                        std::cout << "Player 2, what do you want to do?\n" << "1. Attack\n" << "2. Defend\n" << "3. Use class ability. X\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        continue;
                    }
                    else {
                        system(CONSOLE_CLEAR);
                        std::cout << "Player 2, what do you want to do?\n" << "1. Attack\n" << "2. Defend\n" << "3. Use class ability. <\n";
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        player2UsedAbility++;
                        ability2 = Player2->useAbility(Player2Weapon);
                        player2Attack = Player2->getAttack(player2Choice, Player2Weapon);
                        player2Defence = Player2->getDefence(player2Choice, Player2Weapon);
                        if (Player2->getAbility() == 3) Player2->setDEF(-1 * (static_cast<int>(ability2)));
                        if (Player2->getAbility() == 2) doubled2++;
                        break;
                    }
            default:
                continue;
            }
            system(CONSOLE_CLEAR);
            break;
        }
        double ddamage1, ddamage2;
        if (doubled1 > 0) {
            ddamage2 = (player1Attack * player1Attack) / (player1Attack + player2Defence);
            ability1 = (ability1 * ability1) / (ability1 + player2Defence);
            player2DamageTaken = ddamage2 + ability1;
        }
        else {    
            player2DamageTaken = (player1Attack * player1Attack) / (player1Attack + player2Defence);
        }
        
        if (doubled2 > 0) {
            ddamage1 = (player2Attack * player2Attack) / (player2Attack + player1Defence);
            ability2 = (ability2 * ability2) / (ability2 + player1Defence);
            player1DamageTaken = ddamage1 + ability2;
        }
        else {
            player1DamageTaken = (player2Attack * player2Attack) / (player2Attack + player1Defence);
        }

        Player1->setHP(player1DamageTaken);
        Player2->setHP(player2DamageTaken);
        if (Player1->getHP() < 0 || Player2->getHP() < 0) break;
        if (doubled2 > 0) std::cout << "Player 1 took " << ddamage1 << " and " << ability2 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
        else std::cout << "Player 1 took " << player1DamageTaken << " damage! " << Player1->getHP() << " HP left.\n";
        if (doubled1 > 0) std::cout << "Player 2 took " << ddamage2 << " and " << ability1 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
        else std::cout << "Player 2 took " << player2DamageTaken << " damage! " << Player2->getHP() << " HP left.\n";
        std::cout << "\nContinue?\n1. Let's go!\n2. Quit without saving\n3. Save&Quit";
        while (1) {
            continuation = _getch();
            if (continuation == '1') {
                system(CONSOLE_CLEAR);
                if (doubled2 > 0) std::cout << "Player 1 took " << ddamage1 << " and " << ability2 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
                else std::cout << "Player 1 took " << player1DamageTaken << " damage! " << Player1->getHP() << " HP left.\n";
                if (doubled1 > 0) std::cout << "Player 2 took " << ddamage2 << " and " << ability1 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
                else std::cout << "Player 2 took " << player2DamageTaken << " damage! " << Player2->getHP() << " HP left.\n";
                doubled1 = 0;
                doubled2 = 0;
                std::cout << "\nContinue?\n1. Let's go! <\n2. Quit without saving\n3. Save&Quit";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                break;
            } else if (continuation == '2') {
                system(CONSOLE_CLEAR);
                if (doubled2 > 0) std::cout << "Player 1 took " << ddamage1 << " and " << ability2 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
                else std::cout << "Player 1 took " << player1DamageTaken << " damage! " << Player1->getHP() << " HP left.\n";
                if (doubled1 > 0) std::cout << "Player 2 took " << ddamage2 << " and " << ability1 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
                else std::cout << "Player 2 took " << player2DamageTaken << " damage! " << Player2->getHP() << " HP left.\n";
                doubled1 = 0;
                doubled2 = 0;
                std::cout << "\nContinue?\n1. Let's go!\n2. Quit without saving <\n3. Save&Quit";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                delete Player1;
                delete Player2;
                if(saved_game != nullptr)
                    delete saved_game;
                return;
            } else if (continuation == '3') {
                system(CONSOLE_CLEAR);
                if (doubled2 > 0) std::cout << "Player 1 took " << ddamage1 << " and " << ability2 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
                else std::cout << "Player 1 took " << player1DamageTaken << " damage! " << Player1->getHP() << " HP left.\n";
                if (doubled1 > 0) std::cout << "Player 2 took " << ddamage2 << " and " << ability1 << " damage! Double attack! " << Player1->getHP() << " HP left.\n";
                else std::cout << "Player 2 took " << player2DamageTaken << " damage! " << Player2->getHP() << " HP left.\n";
                doubled1 = 0;
                doubled2 = 0;
                std::cout << "\nContinue?\n1. Let's go!\n2. Quit without saving\n3. Save&Quit <";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                if (saved_game == nullptr)
                {
                    saved_game = new SavedGame;
                    saved_game->setCharacter(c1_c, 1);
                    saved_game->setCharacter(c2_c, 2);
                    saved_game->setWeapon(c1_w, 1);
                    saved_game->setWeapon(c2_w, 2);
                }
                saved_game->setHP(Player1->getHP(), 1);
                saved_game->setHP(Player2->getHP(), 2);
                saved_game->setUsedAbility(player1UsedAbility, 1);
                saved_game->setUsedAbility(player2UsedAbility, 2);
                saved_game->save();
                delete Player1;
                delete Player2;
                delete saved_game;
                return;
            } else continue;
        }
    }

    if (Player1->getHP() <= 0 && Player2->getHP() <= 0) std::cout << "Both players died!\n\t=<>= DRAW =<>=";
    if (Player1->getHP() <= 0 && Player2->getHP() > 0) std::cout << "Player 1 died\n=<>= PLAYER 2 WINS =<>=";
    if (Player1->getHP() > 0 && Player2->getHP() <= 0) std::cout << "Player 2 died\n=<>= PLAYER 1 WINS =<>=";
    std::cout << "\n\n>Press any button to return to main menu";
    _getch();
    delete Player1;
    delete Player2;
}

void continueGame(std::vector<CharacterClass*>& Classes, std::vector<Weapon*>& Weapons) {
    SavedGame* saved_game = new SavedGame;
    if (saved_game->load() == 0)
        newGame(Classes, Weapons, saved_game);
    else
        newGame(Classes, Weapons);
}

int main() {
    srand(2022);
    CharacterClass* magicChar_A = new MagicChar("Monk", 30, 67, 87, 44, 1000, MAGICCHAR);
    CharacterClass* magicChar_B = new MagicChar("Archwizard", 25, 40, 90, 25, 1000, MAGICCHAR);
    CharacterClass* magicChar_C = new MagicChar("Battlemage", 20, 50, 70, 60, 1000, MAGICCHAR);
    CharacterClass* rangedChar_A = new RangedChar("Ninja", 20, 80, 40, 40, 1000, RANGEDCHAR);
    CharacterClass* rangedChar_B = new RangedChar("Sniper", 55, 65, 55, 45, 1000, RANGEDCHAR);
    CharacterClass* rangedChar_C = new RangedChar("Bowson", 50, 70, 30, 50, 1000, RANGEDCHAR);
    CharacterClass* meleeChar_A = new MeleeChar("Pontius", 60, 45, 45, 50, 1000, MELEECHAR);
    CharacterClass* meleeChar_B = new MeleeChar("Pudzian", 90, 20, 20, 50, 1000, MELEECHAR);
    CharacterClass* meleeChar_C = new MeleeChar("Fred", 55, 55, 55, 55, 1000, MELEECHAR);
    std::vector<CharacterClass*> Classes {magicChar_A, magicChar_B, magicChar_C, rangedChar_A, 
    rangedChar_B, rangedChar_C, meleeChar_A, meleeChar_B, meleeChar_C };

    Weapon* MagicWeapon1 = new MagicWeapon("Wand", 10, 15, 5);
    Weapon* MagicWeapon2 = new MagicWeapon("Book of spells", 10, 10, 15);
    Weapon* MagicWeapon3 = new MagicWeapon("Magic sword", 15, 10, 5);
    Weapon* RangedWeapon1 = new RangedWeapon("Bow", 10, 5, 15);
    Weapon* RangedWeapon2 = new RangedWeapon("Rifle", 15, 5, 10);
    Weapon* RangedWeapon3 = new RangedWeapon("Shotgun", 10, 15, 5);
    Weapon* MeleeWeapon1 = new MeleeWeapon("Knife", 15, 5, 10);
    Weapon* MeleeWeapon2 = new MeleeWeapon("Axe", 10, 10, 10);
    Weapon* MeleeWeapon3 = new MeleeWeapon("Hammer", 18, 2, 10);
    std::vector<Weapon*> Weapons = { MagicWeapon1, MagicWeapon2, MagicWeapon3, RangedWeapon1, RangedWeapon2,
    RangedWeapon3, MeleeWeapon1, MeleeWeapon2, MeleeWeapon3 };


    while (1) {
        system(CONSOLE_CLEAR);
        std::cout<<"===The Ancient Scriptures 2: KnifeDrop===\n1. Start\n2. Continue\n3. Quit\n";
        char action = _getch();
        switch(action){
            case '1':
                system(CONSOLE_CLEAR);
                std::cout << "===The Ancient Scriptures 2: KnifeDrop===\n1. Start <\n2. Continue\n3. Quit\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                newGame(Classes, Weapons);
                break;
            case '2':
                system(CONSOLE_CLEAR);
                std::cout << "===The Ancient Scriptures 2: KnifeDrop===\n1. Start\n2. Continue <\n3. Quit\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                continueGame(Classes, Weapons);
                break;
            case '3':
                system(CONSOLE_CLEAR);
                std::cout << "===The Ancient Scriptures 2: KnifeDrop===\n1. Start\n2. Continue\n3. Quit <\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                for (std::vector<CharacterClass*>::iterator k = Classes.begin(); k != Classes.end(); ++k) {
                    delete* k;
                }
                return 0;
            default:
                system(CONSOLE_CLEAR);
                continue;
        }
    }
}