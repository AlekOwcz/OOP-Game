#include "../Headers/RangedChar.h"

RangedChar::RangedChar(std::string name, int strength, int dexterity, int inteligence, int defence, float health, int ability) {
	this->name = name;
	this->STR = strength;
	this->DEX = dexterity;
	this->INT = inteligence;
	this->DEF = defence;
	this->HP = health;
	this->ability = ability;
}
RangedChar::RangedChar(CharacterClass* Char) {
	this->name = Char->getName();
	this->STR = Char->getSTR();
	this->DEX = Char->getDEX();
	this->INT = Char->getINT();
	this->DEF = Char->getDEF();
	this->HP = Char->getHP();
	this->ability = Char->getAbility();
}

float RangedChar::useAbility(Weapon* weapon) {
	return this->getAttack(3, weapon);
}

float RangedChar::getAttack(int choice, Weapon* weapon) {
	double STRmodifier, DEXmodifier, INTmodifier;
	INTmodifier = (250.0 + (rand() % 221)) / 1000.0; //30.0% - 52.0%
	STRmodifier = (510.0 + (rand() % 221)) / 1000.0; //36.0% - 58.0% 
	DEXmodifier = (1100.0 + (rand() % 221)) / 1000.0; //115.0% - 137.0%
	switch (choice) {
	case 1: //Attack
		return ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK());

	case 2: //Defence
		return (0.5 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK()));

	case 3: //Ability 
		return (0.75 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK()));
	}
}

float RangedChar::getDefence(int choice, Weapon* weapon) {
	double STRmodifier, DEXmodifier, INTmodifier, DEFmodifier;
	INTmodifier = (200.0 + (rand() % 201)) / 1000.0; // 2.0% - 4.0%
	DEXmodifier = (700.0 + (rand() % 201)) / 1000.0; // 7.0% - 9.0%
	STRmodifier = (600.0 + (rand() % 201)) / 1000.0; // 6.0% - 8.0%
	DEFmodifier = (900.0 + (rand() % 201)) / 100.0; // 90.0% - 110.0%
	switch (choice) {
	case 1: //Attack
		return (0.5 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getDEF()));

	case 2: //Defence
		return ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getDEF());

	case 3: //Ability?
		return (0.25 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getDEF()));
	}
}