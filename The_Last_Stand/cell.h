#ifndef H_CELL
#define H_CELL
#include <string>
#include <iostream>
#include "character.h"
class cell
{
public:
	cell();
	~cell();
	//void print();
	std::string getType();
	void putChara(character& c);
	character& getChara();
	void resetChara();
private:
	int bonus;
	std::string type;
	character* chara;
};

#endif
