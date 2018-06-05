#ifndef H_CHARACTER
#define H_CHARACTER
#include <string>
#include <iostream>
#include "Iskill.h"
#include <map>
enum characteristics {
	Strength,
	Speed,
	Defense,
	Resistance,
	Range,
	Movement,
	Hp,
};
static std::map<std::string, characteristics> statCode =
{
{ "Strength", Strength },
{ "Speed", Speed },
{ "Defense", Defense },
{ "Resistance", Resistance },
{ "Range", Range },
{ "movement", Movement },
{ "HP", Hp }
};
enum Type {
	Tank,
	Berserk,
	Ninja,
	Bowman,
	Normal,
};
class character
{

public:


	character();
	character(std::string name);
	character(std::string name, Type t);
	virtual ~character();
	std::string getName();
	int getStrength();
	int getSpeed();
	void setSpeed(int newspeed);
	int getDefense();
	int getRange();
	void setMovement(int new_mouvement);
	int getMovement();
	int getHP();
	int getResistance();
	void use(Iskill *I);
	void attacking(character & c);
	void setSkill(Iskill *skill);
	void applyType();
	void incStat();
	//void applyBuff(Buff * b);
	friend class Buff;
	friend class Spells;
private:
	std::string name;
	int strength;
	int speed;
	int defense;
	int resistance;
	int range;
	int movement;
	int hp;
	Iskill *Skill;
	Type type;
};



#endif