#ifndef RANGEDCHAR_H
#define RANGEDCHAR_H

#include "CharacterClass.h"

class RangedChar : public CharacterClass {
public:
	RangedChar(std::string, int, int, int, int, float, int);
	RangedChar(CharacterClass*);
	float useAbility(Weapon*);
	float getAttack(int, Weapon*);
	float getDefence(int, Weapon*);
};

#endif