#include "../Headers/SaveGame.h"

void SavedGame::setCharacter(int character, int player)
{
	if (player == 1)
		Character1 = character;
	else
		Character2 = character;
}

void SavedGame::setWeapon(int weapon, int player) 
{
	if (player == 1)
		Weapon1 = weapon;
	else
		Weapon2 = weapon;
}

void SavedGame::setUsedAbility(int n, int player)
{
	if (player == 1)
		player1UsedAbility = n;
	else
		player2UsedAbility = n;
}

void SavedGame::setHP(float HP, int player) 
{
	if (player == 1)
		Player1_HP = HP;
	else
		Player2_HP = HP;
}

void SavedGame::save() 
{
	std::ofstream file("save.txt");

	file << Character1 << std::endl;
	file << Weapon1 << std::endl;
	file << player1UsedAbility << std::endl;
	file << Player1_HP << std::endl;
	file << Character2 << std::endl;
	file << Weapon2 << std::endl;
	file << player2UsedAbility << std::endl;
	file << Player2_HP << std::endl;

	file.close();
}

int SavedGame::getCharacter(int player)
{
	if (player == 1)
		return Character1;
	else
		return Character2;
}

int SavedGame::getWeapon(int player)
{
	if (player == 1)
		return Weapon1;
	else
		return Weapon2;
}

int SavedGame::getUsedAbility(int player)
{
	if (player == 1)
		return player1UsedAbility;
	else
		return player2UsedAbility;
}

float SavedGame::SavedGame::getHP(int player)
{
	if (player == 1)
		return Player1_HP;
	else
		return Player2_HP;
}

int SavedGame::load()
{
	std::ifstream file("save.txt");

	if (file.fail())
		return -1;

	file >> Character1;
	file >> Weapon1;
	file >> player1UsedAbility;
	file >> Player1_HP;
	file >> Character2;
	file >> Weapon2;
	file >> player2UsedAbility;
	file >> Player2_HP;

	file.close();
	return 0;
}