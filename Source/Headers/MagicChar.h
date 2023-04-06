#ifndef MAGICCHAR_H
#define MAGICCHAR_H

#include "CharacterClass.h"

class MagicChar : public CharacterClass {
public:
	MagicChar(std::string, int, int, int, int, float, int);
	MagicChar(CharacterClass*);
	float useAbility(Weapon*);
	float getAttack(int, Weapon*);
	float getDefence(int, Weapon*);
};

#endif