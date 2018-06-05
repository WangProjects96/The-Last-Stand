#ifndef H_SKILL
#define H_SKILL
#include "string"
 class Iskill
{
protected:
	std::string name;
public:
	Iskill();
	Iskill(std::string newName);
	void setName(std::string newName);
	std::string getName();
	virtual ~Iskill();
	
};
#endif

