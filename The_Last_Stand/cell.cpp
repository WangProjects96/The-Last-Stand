#include "cell.h"
#include <iostream>


cell::cell()
{
	bonus = 0;
	type = " ";
	chara = nullptr;
}


cell::~cell()
{
}

std::string cell::getType()
{
	return type;
}

void cell::putChara(character& c) {
	chara = &c;
}

character & cell::getChara()
{
	return *chara;
}

void cell::resetChara()
{
	chara = nullptr;
}
