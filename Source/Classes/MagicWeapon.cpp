#include "../Headers/MagicWeapon.h"

MagicWeapon::MagicWeapon(std::string name, float attack, float defence, float inteligence) { 
	this->name = name;
	this->ATK = attack;
	this->DEF = defence;
	this->INT = inteligence; 
}
float MagicWeapon::getINT() { return this->INT; }
void MagicWeapon::setINT(float inteligence) { this->INT = inteligence; return;}

float MagicWeapon::getDEX() { return 0; }
void MagicWeapon::setDEX(float dexterity) { return; }

float MagicWeapon::getSTR() { return 0; }
void MagicWeapon::setSTR(float strength) { return; }