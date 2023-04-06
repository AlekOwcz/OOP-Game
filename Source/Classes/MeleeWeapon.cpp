#include "../Headers/MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(std::string name, float attack, float defence, float strength) {
	this->name = name;
	this->ATK = attack;
	this->DEF = defence;
	this->STR = strength;
}
float MeleeWeapon::getINT() { return 0; }
void MeleeWeapon::setINT(float inteligence) { return; }

float MeleeWeapon::getDEX() { return 0; }
void MeleeWeapon::setDEX(float dexterity) { return; }

float MeleeWeapon::getSTR() { return this->STR; }
void MeleeWeapon::setSTR(float strength) { this->STR = strength; return; }