#include "game.h"
#include "enemy.h"



game::game()
{
	map = new grid();
}


game::~game()
{
	for (int i = 0; i < spawn.size(); ++i) {
		delete spawn[i];
	}
	delete map;
}

grid & game::getMap()
{
	return *map;
}

void game::addPlayable(playable_character & c)
{
	playable.push_back(&c);
}

void game::addEnemy(character & c)
{
	enemies.push_back(&c);
}

void game::movingCharacter(character & c, int choice)
{
	map->moving(c, choice);
}

void game::enemyPhase()
{
	for (unsigned int i = 0; i < enemies.size(); ++i) {
		map->movingEnemy(*enemies[i]);
		if (enemies[i]->getHP() <= 0) {
			enemies.erase(enemies.begin() + i);
		}
	}
	for (unsigned int i = 0; i < spawn.size(); ++i) {
		map->movingEnemy(*spawn[i]);
	}
	//spawning();
}

int game::getIndex(character& c) {
	for (int i = 0; i < playable.size(); ++i) {
		if (&c == playable[i]) {
			return i;
		}
	}
	return 0;
}

void game::addChara(int line, int row, character & c)
{
	map->addChara(line, row, c);
}

bool game::gameOver()
{
	bool playableDead = true;
	bool enemiesDead = true;
	bool spawnDead = true;
	for (unsigned int i = 0; i < playable.size(); ++i) {
		if (playable[i]->getHP() > 0) {
			playableDead = false;
		}
	}
	for (unsigned int i = 0; i < enemies.size(); ++i) {
		if (enemies[i]->getHP() > 0) {
			enemiesDead = false;
		}
	}
	for (unsigned int i = 0; i < spawn.size(); ++i) {
		if (spawn[i]->getHP() > 0) {
			spawnDead = false;
		}
	}
	return playableDead || (enemiesDead && spawnDead);
}

void game::spawning() {
	if (&map->getCell(0,9).getChara() == nullptr) {
		character * e = new enemy("Peon");
		e->incStat();
		spawn.push_back(e);
		map->getCell(0, 9).putChara(*e);
	}
}

std::vector<playable_character*>& game::getplayable()
{
	// TODO: insérer une instruction return ici
	return playable;
}

int game::getTurn()
{
	return turn;
}

void game::incTurn()
{
	turn++;
}



