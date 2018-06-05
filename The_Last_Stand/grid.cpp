#include "grid.h"
#include <iostream>
#include "enemy.h"


grid::grid()
{
	map = new cell*[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		map[i] = new cell[SIZE];
	}
}


grid::~grid()
{
	for (int i = 0; i < SIZE; ++i) {
		delete[] map[i];
	}
	delete[] map;
}

cell & grid::getCell(int i, int j)
{
	return map[i][j];
}

void grid::addChara(int i, int j, character& chara)
{
	if (i >= 0 && i < SIZE && j >= 0 && j < SIZE)
		map[i][j].putChara(chara);
}

void grid::moving(character & c, int a)
{
	int k = 0;
	int d = 0;
	switch (a) {

	case TOP:
		k = -c.getMovement();
		break;
	case RIGHT:
		d = c.getMovement();
		break;
	case BOT:
		k = c.getMovement();
		break;
	case LEFT:
		d = - c.getMovement();
		break;
	}
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (&map[i][j].getChara() == &c) {
				if (verifBounds(a, i, j,c)) {
					if (&map[i + k][j + d].getChara() == nullptr) {
						map[i][j].resetChara();
						map[i + k][j + d].putChara(c);
						i = SIZE;
					}
					else {
						map[i][j].getChara().attacking(map[i + k][j + d].getChara());
						if (map[i + k][j + d].getChara().getHP() <= 0) {
							map[i + k][j + d].resetChara();
						}
						else {
							map[i + k][j + d].getChara().attacking(map[i][j].getChara());
							if (c.getHP() <= 0) {
								map[i][j].resetChara();
							}
						}
					}
					break;
				}
			}
		}

	}


}
bool verifBounds(int a, int i, int j,character &c) {
	switch (a) {
	case TOP:
		if (i > 0 + c.getMovement()) {
			return true;
		}
		break;
	case RIGHT:
		if (j < SIZE - c.getMovement()) {
			return true;
		}
		break;
	case BOT:
		if (i < SIZE - c.getMovement()) {
			return true;
		}
		break;
	case LEFT:
		if (j > 0 + c.getMovement()) {
			return true;
		}
		break;

	}
	return false;
}

int grid::caracterOnLane(character& e, int lane, int currentPosition) {
	for (int i = 0; i < SIZE; ++i) {
		if (&map[lane][i].getChara() != nullptr && &map[lane][i].getChara() != &e) {
			if (enemy *b = dynamic_cast<enemy*>(&map[lane][i].getChara())) {
				
			}
			else {
				if (i > currentPosition) {
					return 1;
				}
				else {
					return -1;
				}
			}
		}
	}
	return 0;
}

int grid::caracterOnRow(character& e, int row, int currentPosition) {
	for (int i = 0; i < SIZE; ++i) {
		if (&map[i][row].getChara() != nullptr && &map[i][row].getChara() != &e) {
			//character * a = &map[i][row].getChara();
			if (enemy *b = dynamic_cast<enemy*>(&map[i][row].getChara())) {
				
			}
			else {
				if (i > currentPosition) {
					return 1;
				}
				else {
					return -1;
				}
			}
		}
	}
	return 0;
}

void grid::movingEnemy(character& e) {
	int line = 0, row = 0;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (&map[i][j].getChara() == &e) {
				line = i;
				row = j;
			}
		}
	}
	int a, b = 0;
	a = caracterOnLane(e, line, row);
	b = caracterOnRow(e, row, line);
	if (b != 0) {
		if (b > 0) {
			moving(e, BOT);
		}
		else {
			moving(e, TOP);
		}
	}
	else {
		if (a != 0) {
			if (a > 0) {
				moving(e, RIGHT);
			}
			else {
				moving(e, LEFT);
			}
		}
		else {
			moving(e, rand() % 4);
		}
	}
}
