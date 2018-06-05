#include "Iskill.h"
#include "string"


Iskill::Iskill()
{
	name = "undefined";
}

Iskill::Iskill(std::string newName)
{
	name = newName;
}

void Iskill::setName(std::string newName)
{
	name = newName;
}

std::string Iskill::getName()
{
	return name;
}





Iskill::~Iskill()
{
}
