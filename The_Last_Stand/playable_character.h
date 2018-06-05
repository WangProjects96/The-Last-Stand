#ifndef H_PCHARACTER
#define H_PCHARACTER
#include "character.h"
class playable_character : public character
{
private:
	int rarity;
public:
	playable_character(std::string n,int rarity);
	playable_character(std::string n,Type t, int rarity);
	virtual ~playable_character();
};
#endif

