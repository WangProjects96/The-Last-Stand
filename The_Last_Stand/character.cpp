#include "character.h"
#include "Buff.h"
#include "Spells.h"
#include "Iskill.h"
character::character()
{
	strength = 6;
	speed = 4;
	defense = 1;
	resistance = 0;
	range = 1;
	movement = 1;
	hp = 10;
	type = Normal;
	applyType();
}

character::character(std::string n) {
	name = n;
	strength = 6;
	speed = 4;
	defense = 1;
	resistance = 0;
	range = 1;
	movement = 1;
	hp = 10;
	type = Normal;
	applyType();
}

character::character(std::string n, Type t)
{
	name = n;
	strength = 6;
	speed = 4;
	defense = 1;
	resistance = 0;
	range = 1;
	movement = 1;
	hp = 10;
	type = t;
	applyType();
}





character::~character()
{
}

std::string character::getName()
{
	return name;
}

int character::getStrength()
{
	return strength;
}

int character::getSpeed()
{
	return speed;
}

void character::setSpeed(int newspeed)
{
	speed = newspeed;
}

int character::getDefense()
{
	return defense;
}

int character::getRange() {
	return range;
}

void character::setMovement(int new_mouvement) {
	movement = new_mouvement;
}

int character::getMovement() {
	return movement;
}

int character::getHP() {
	return hp;
}

int character::getResistance()
{
	return resistance;
}

void character::use(Iskill *Skill)
{
	if (Buff *b = dynamic_cast<Buff*>(Skill)) {
		b->use(this);
	}
}

void character::attacking(character & e) {
	int damage;
	damage = strength - e.defense;
	
	if (Spells *s = dynamic_cast<Spells*>(Skill)) {
		 damage += s->use(this,	&e);
	}
	e.hp -= damage;
}

void character::setSkill(Iskill* skill)
{
	Skill = skill;
	use(skill);
}


void character::applyType()
{
	switch (type) {
		case Normal:
			break;
		case Tank:
			hp += 10;
			defense += 10;
			movement -= 1;
			break;
		case Ninja:
			speed += 10;
			movement += 1;
			break;
		case Berserk:
			strength += 15;
			hp += 5;
			break;
		case Bowman:
			speed += 10;
			range += 1;
			break;
		}
}

void character::incStat() {
	strength+=15;
	hp += 5;
}

/*
void character::applyBuff(Buff *b)
{

	characteristics actualstat = statCode[b->getStat()];

	switch (actualstat) {
	case characteristics::Strength:
		strength += b->getValue();
		break;
	case characteristics::Speed:
		speed += b->getValue();
		break;
	case characteristics::Defense:
		defense += b->getValue();
		break;
	case characteristics::Resistance:
		resistance += b->getValue();
		break;
	case characteristics::Range:
		range += b->getValue();
		break;
	case characteristics::Movement:
		movement += b->getValue();
		break;
	case characteristics::Hp:
		hp += b->getValue();
		break;
	default:
		std::cout << "Buff invalide";
	}

}
*/
