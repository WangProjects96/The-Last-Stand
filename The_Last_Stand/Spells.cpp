#include "Spells.h"



Spells::Spells(std::string n, int cd) : Iskill(n)
{
	cooldown = cd;
	available = true;
}


Spells::Spells()
{
}



int Spells::use(character *c, character *e)
{
	if (!available) {
		return 0;

	}
	available = false;
	switch (SpeelBook[name]) {
	case fireball:
		return 10;
		break;

	case TimeControl:
		c->speed += e->speed;
		e->speed = 0;
		return 0;
		break;
	default:
		return 0;
	}
	return 0;
}

void Spells::decCooldown()
{
	if (cooldown != 0)
		cooldown--;
}

Spells::~Spells()
{
}
