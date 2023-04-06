#include "../Headers/CharacterClass.h"

std::string CharacterClass::getName() { return this->name; }
void CharacterClass::setName(std::string name) { this->name = name; }

int CharacterClass::getSTR() { return this->STR; }
void CharacterClass::setSTR(int strength) { this->STR += strength; return; }

int CharacterClass::getDEX() { return this->DEX; }
void CharacterClass::setDEX(int dexterity) { this->DEX += dexterity; return; }

int CharacterClass::getINT() { return this->INT; }
void CharacterClass::setINT(int inteligence) { this->INT += inteligence; return; }

int CharacterClass::getDEF() { return this->DEF; }
void CharacterClass::setDEF(int defence) { this->DEF += defence; return; }

float CharacterClass::getHP() { return this->HP; }
void CharacterClass::setHP(float health) { this->HP -= health; return; }
void CharacterClass::loadHP(float health) { this->HP = health; return; }

int CharacterClass::getAbility() { return this->ability; }
void CharacterClass::setAbility() { this->ability = -1; return;}