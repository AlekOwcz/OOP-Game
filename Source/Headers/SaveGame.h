#ifndef SAVEGAME_H
#define SAVEGAME_H

#include<fstream>

class SavedGame
{
private:
	int Character1;
	int Weapon1;
	int player1UsedAbility;
	float Player1_HP;
	int Character2;
	int Weapon2;
	int player2UsedAbility;
	float Player2_HP;

public:
	void setCharacter(int, int);
	void setWeapon(int, int);
	void setUsedAbility(int, int);
	void setHP(float, int);
	void save();
	int getCharacter(int);
	int getWeapon(int);
	int getUsedAbility(int);
	float getHP(int);
	int load();
};
#endif