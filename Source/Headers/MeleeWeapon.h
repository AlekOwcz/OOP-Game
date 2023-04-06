#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "Weapon.h"

class MeleeWeapon : public Weapon{
private:
    float STR;
public:
    MeleeWeapon(std::string, float, float, float);
	float getINT(void);
	void setINT(float);

	float getDEX(void);
	void setDEX(float);

	float getSTR(void);
	void setSTR(float);
};

#endif