#ifndef H_GRID
#define H_GRID
#include "cell.h"
#define SIZE 10
enum { TOP = 0, RIGHT = 1, BOT = 2, LEFT = 3 };
class grid
{
public:
	grid();
	~grid();
	cell& getCell(int, int);
	void addChara(int, int, character&);
	void moving(character&, int a);

	int caracterOnLane(character & e, int lane, int currentPosition);

	int caracterOnRow(character & e, int row, int currentPosition);

	void movingEnemy(character & e);
	
private:
	cell * * map;
};
bool verifBounds(int a, int i, int j,character &c);
#endif
