#include <cstdlib>
#include "../Headers/MagicChar.h"
#include "../Headers/Weapon.h"

MagicChar::MagicChar(std::string name, int strength, int dexterity, int inteligence, int defence, float health, int ability) {
	this->name = name;
	this->STR = strength;
	this->DEX = dexterity;
	this->INT = inteligence;
	this->DEF = defence;
	this->HP = health;
	this->ability = ability;
}

MagicChar::MagicChar(CharacterClass* Char) {
	this->name = Char->getName();
	this->STR = Char->getSTR();
	this->DEX = Char->getDEX();
	this->INT = Char->getINT();
	this->DEF = Char->getDEF();
	this->HP = Char->getHP();
	this->ability = Char->getAbility();
}

float MagicChar::useAbility(Weapon* weapon) {
	int additionalINT = (this->INT + weapon->getINT()) - 50;
	if (additionalINT < 0) additionalINT = 0;
	float a = 0.002;
	float b = 0.05;
	float absoluteHealing = a * additionalINT + b;
	float healed = (absoluteHealing - 0.01) + ((rand() % 201) / 10000.0);
	this->HP += healed;
	return healed;
}

float MagicChar::getAttack(int choice, Weapon* weapon) {
	double STRmodifier, DEXmodifier, INTmodifier;
	STRmodifier = (300.0 + (rand() % 221)) / 1000.0; //30.0% - 52.0%
	DEXmodifier = (460.0 + (rand() % 221)) / 1000.0; //46.0% - 68.0% 
	INTmodifier = (1100.0 + (rand() % 221)) / 1000.0; //110.0% - 132.0%
	switch(choice){
		case 1: //Attack
			return ( (this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK());

		case 2: //Defence
			return (0.5 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK()));

		case 3: //Ability 
			return (0.05 * ((this->STR + weapon->getSTR()) * STRmodifier + (this->DEX + weapon->getDEX()) * DEXmodifier + (this->INT + weapon->getINT()) * INTmodifier + weapon->getATK()));
	}
}

float MagicChar::getDefence(int choice, Weapon* weapon) {
	double STRmodifier, DEXmodifier, INTmodifier, DEFmodifier;
	STRmodifier = (150.0 + (rand() % 201)) / 1000.0; // 1.5% - 3.5%
	DEXmodifier = (400.0 + (rand() % 201)) / 1000.0; // 4.0% - 6.0%
	INTmodifier = (900.0 + (rand() % 201)) / 1000.0; // 9.0% - 11.0%
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