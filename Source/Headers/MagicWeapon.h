#ifndef MAGICWEAPON_H
#define MAGICWEAPON_H

#include "Weapon.h"

class MagicWeapon : public Weapon{
private:
    float INT;
public:
    MagicWeapon(std::string, float, float, float);
    float getINT(void);
    void setINT(float);

	float getDEX(void);
	void setDEX(float);

	float getSTR(void);
	void setSTR(float);
};

#endif