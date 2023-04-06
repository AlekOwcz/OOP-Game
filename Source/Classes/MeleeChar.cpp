#include "../Headers/MeleeChar.h"

MeleeChar::MeleeChar(std::string name, int strength, int dexterity, int inteligence, int defence, float health, int ability) {
	this->name = name;
	this->STR = strength;
	this->DEX = dexterity;
	this->INT = inteligence;
	this->DEF = defence;
	this->HP = health;
	this->ability = ability;
}
MeleeChar::MeleeChar(CharacterClass* Char) {
	this->name = Char->getName();
	this->STR = Char->getSTR();
	this->DEX = Char->getDEX();
	this->INT = Char->getINT();
	this->DEF = Char->getDEF();
	this->HP = Char->getHP();
	this->ability = Char->getAbility();
}
float MeleeChar::useAbility(Weapon* weapon) {
	int DEFBonus = 7 + rand() % 6;
	this->DEF += DEFBonus;
	return DEFBonus;
}

float MeleeChar::getAttack(int choice, Weapon* weapon) {
	double STRmodifier, DEXmodifier, INTmodifier;
	INTmodifier = (250.0 + (rand() % 221)) / 1000.0; //25.0% - 47.0%
	DEXmodifier = (510.0 + (rand() % 221)) / 1000.0; //51.0% - 73.0% 
	STRmodifier = (1100.0 + (rand() % 221)) / 1000.0; //110.0% - 132.0%
	switch (choice) {
	case 1: //Attack
		return ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK());

	case 2: //Defence
		return (0.5 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK()));

	case 3: //Ability 
		return (0.35 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK()));
	}
}

float MeleeChar::getDefence(int choice, Weapon* weapon) {
	double STRmodifier, DEXmodifier, INTmodifier, DEFmodifier;
	INTmodifier = (150.0 + (rand() % 201)) / 1000.0; // 1.5% - 3.5%
	DEXmodifier = (400.0 + (rand() % 201)) / 1000.0; // 4.0% - 6.0%
	STRmodifier = (900.0 + (rand() % 201)) / 1000.0; // 9.0% - 11.0%
	DEFmodifier = (900.0 + (rand() % 201)) / 100.0; // 90.0% - 110.0%
	switch (choice) {
	case 1: //Attack
		return (0.5 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getDEF()));

	case 2: //Defence
		return ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getDEF());

	case 3: //Ability?
		return (1.25 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getDEF()));
	}
}