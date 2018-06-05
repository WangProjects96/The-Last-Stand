#ifndef H_GAME
#define H_GAME
#include "grid.h"
#include <iostream>
#include <vector>
#include "playable_character.h"
class game
{
public:
	game();
	~game();
	grid& getMap();
	void addPlayable(playable_character & c);
	void addEnemy(character & c);
	void movingCharacter(character & c, int choice);
	void enemyPhase();
	int getIndex(character & c);
	void addChara(int line, int row, character & c);
	bool gameOver();
	void spawning();
	std::vector<playable_character*> & getplayable();
	int getTurn();
	void incTurn();
private:
	grid * map;
	std::vector<playable_character*> playable;
	std::vector<character*> enemies;
	std::vector<character*> spawn;
	int turn = 0;
};
#endif
