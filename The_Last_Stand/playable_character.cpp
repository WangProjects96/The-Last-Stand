#include "playable_character.h"
#include "string"



playable_character::playable_character(std::string n, int newrarity) : character(n)
{
	
	rarity = newrarity;

}

playable_character::playable_character(std::string n, Type t, int newRarity) : character(n,t)
{
	rarity = newRarity;
}


playable_character::~playable_character()
{
}
