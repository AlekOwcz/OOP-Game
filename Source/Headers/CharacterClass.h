#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

#include<iostream>
#include "Weapon.h"

class CharacterClass {
protected:
	std::string name;
	int STR;
	int DEX;
	int INT;
	int DEF;
	float HP;
	int ability;
public:
	std::string getName();
	void setName(std::string);

	int getSTR(void);
	void setSTR(int);

	int getDEX(void);
	void setDEX(int);

	int getINT(void);
	void setINT(int);

	int getDEF(void);
	void setDEF(int);

	float getHP(void);
	void setHP(float);
	void loadHP(float);

	int getAbility(void);
	void setAbility(void);

	virtual float getAttack(int, Weapon*) = 0;
	virtual float getDefence(int, Weapon*) = 0;
	virtual float useAbility(Weapon*) = 0;
};

#endif