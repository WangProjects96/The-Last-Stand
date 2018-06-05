#ifndef H_SPELLS
#define H_SPELLS
#include "Iskill.h"
#include "playable_character.h"
#include "enemy.h"
#include <map>
enum Spell{
	fireball,
	TimeControl,
};
static std::map<std::string, Spell>SpeelBook{
	{ "fireball", fireball },
	{ "TimeControl", TimeControl },
};
class Spells : public Iskill

{
protected:
	int cooldown;
	bool available;
public:
	Spells(std::string n, int cd);
	Spells();
	
	int use(character* c, character* e);
	void decCooldown();

	virtual ~Spells();
};


#endif

