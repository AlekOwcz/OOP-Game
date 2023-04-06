#include "../Headers/RangedWeapon.h"

RangedWeapon::RangedWeapon(std::string name, float attack, float defence, float dexterity) {
	this->name = name;
	this->ATK = attack;
	this->DEF = defence;
	this->DEX = dexterity;
}
float RangedWeapon::getINT() { return 0; }
void RangedWeapon::setINT(float inteligence) { return; }

float RangedWeapon::getDEX() { return this->DEX; }
void RangedWeapon::setDEX(float dexterity) { this->DEX = dexterity; return; }

float RangedWeapon::getSTR() { return 0; }
void RangedWeapon::setSTR(float strength) { return; }