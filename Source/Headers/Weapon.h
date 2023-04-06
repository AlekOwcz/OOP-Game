#ifndef WEAPON_H
#define WEAPON_H

#include<iostream>

class Weapon {
protected:
	std::string name;
	float ATK;
	float DEF;
    int ID;

public:
	std::string getName();
	void setName(std::string);

	float getATK(void);
	void setATK(float);

	float getDEF(void);
	void setDEF(float);

	int getID(void);
	void setID(int);

	virtual float getINT(void) = 0;
	virtual void setINT(float) = 0;

	virtual float getDEX(void) = 0;
	virtual void setDEX(float) = 0;

	virtual float getSTR(void) = 0;
	virtual void setSTR(float) = 0;
};

#endif