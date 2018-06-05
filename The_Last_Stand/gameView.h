#ifndef H_GAMEVIEW
#define H_GAMEVIEW
#include <iostream>
#include "character.h"
#include "grid.h"
#include "game.h"
class gameView
{
public:
	gameView();
	~gameView();
	void printGrid(grid& g);
	void printCell(cell& c);
	void printGame(game& g);

};

std::ostream& operator<<(std::ostream& file, character& c);

#endif;