#include "Buff.h"
#include "string"


Buff::Buff() : Iskill("undefined") 
{

}


Buff::Buff(std::string newName, std::string newStat, int newValue) : Iskill(newName)
{
	stat = newStat;
	value = newValue;
}

Buff::~Buff()
{
}

std::string Buff::getStat()
{
	return stat;
}

void Buff::setStat(std::string newStat)
{
	stat = newStat;
}

int Buff::getValue()
{
	return value;
}

int Buff::use(character *c)
{
	
	characteristics actualstat = statCode[stat];

	switch (actualstat) {
	case characteristics::Strength:
		
		c->strength += value;
		break;
	case characteristics::Speed:
		c->speed += value;
		break;
	case characteristics::Defense:
		c->defense += value;
		break;
	case characteristics::Resistance:
		c->resistance += value;
		break;
	case characteristics::Range:
		c->range += value;
		break;
	case characteristics::Movement:
		c->movement += value;
		break;
	case characteristics::Hp:
		c->hp += value;
		break;
	default:
		return -1;
	}
	return 0;
	
}

void Buff::setValue(int newValue)
{
	value = value;

}


