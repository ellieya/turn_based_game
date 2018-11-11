#include "battlers.h"

class party {
	hero* main_party = new hero[4];

public:
	party();

};

party::party() {
	hero warrior(0);
	main_party[0] = warrior;
}
