#ifndef MELEECHAR_H
#define MELEECHAR_H

#include "CharacterClass.h"

class MeleeChar : public CharacterClass {
public:
	MeleeChar(std::string, int, int, int, int, float, int);
	MeleeChar(CharacterClass*);
	float useAbility(Weapon*);
	float getAttack(int, Weapon*);
	float getDefence(int, Weapon*);
};

#endif