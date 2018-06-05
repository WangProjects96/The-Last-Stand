#ifndef H_ENEMY
#define H_ENEMY
#include "character.h"
class enemy : public character
{
public:
	enemy(std::string n);
	enemy();
	virtual ~enemy();
};
#endif

