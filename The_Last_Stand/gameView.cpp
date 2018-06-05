#include "gameView.h"



gameView::gameView()
{
}


gameView::~gameView()
{
}

void gameView::printGrid(grid& g)
{
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			//map[i][j].print();
			printCell(g.getCell(i, j));
		}
		std::cout << std::endl;
	}
}

void gameView::printCell(cell& c) {
	if (&c.getChara() == nullptr)
		std::cout << "[" << c.getType() << "]";
	else
		std::cout << "[" << c.getChara().getName()[0] << "]";
}

void gameView::printGame(game & g)
{
	printGrid(g.getMap());
}

std::ostream & operator<<(std::ostream& file, character & c)
{
	file << c.getName() << std::endl;
	file << "HP: " << c.getHP() << std::endl;
	file << "Str: " << c.getStrength() << std::endl;
	file << "Spd: " << c.getSpeed() << std::endl;
	file << "Def: " << c.getDefense() << std::endl;
	file << "Res: " << c.getResistance() << std::endl;
	file << "Rge: " << c.getRange() << std::endl;
	file << "Mvt: " << c.getMovement() << std::endl;
	return file;
}