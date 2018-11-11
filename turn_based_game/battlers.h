#include "libraries.h"

class hero {
	string name;
	int HP, ATK, DEF, SPD;
	int SP;

public:
	hero();
	hero(int ID);
	void increase_stat(int target, int SP) throw(string);
};
#include "hero.cpp"


class monster {
	string name;
	int HP, ATK, DEF, SPD;

public:
	monster(int ID);
};
#include "monster.cpp"

