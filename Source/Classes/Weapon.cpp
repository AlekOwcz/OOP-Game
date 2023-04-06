#include "../Headers/Weapon.h"

std::string Weapon::getName() { return this->name; }
void Weapon::setName(std::string name) { this->name = name; return; }

float Weapon::getATK() { return this->ATK; }
void Weapon::setATK(float attack) { this->ATK = attack; return; }

float Weapon::getDEF() { return this->DEF; }
void Weapon::setDEF(float defence) { this->DEF = defence; return; }

int Weapon::getID() { return this->ID; }
void Weapon::setID(int id) { this->ID = id; return; }