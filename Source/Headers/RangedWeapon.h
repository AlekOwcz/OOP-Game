#ifndef RANGEDWEAPON_H
#define RANGEDWEAPON_H

#include "Weapon.h"

class RangedWeapon : public Weapon{
private:
    float DEX;
public:
    RangedWeapon(std::string, float, float, float);
	float getINT(void);
	void setINT(float);

	float getDEX(void);
	void setDEX(float);

	float getSTR(void);
	void setSTR(float);
};

#endif