hero::hero() {
	name = "N/A";
}

hero::hero(int ID) {
	switch (ID) {
	case 0:
		name = "Warrior";
		HP = 20;
		ATK = 5;
		DEF = 5;
		SPD = 5;
		break;
	case 1:
		name = "Mage";
		HP = 20;
		ATK = 7;
		DEF = 1;
		SPD = 7;
		break;
	case 2:
		name = "Bowman";
		HP = 20;
		ATK = 5;
		DEF = 2;
		SPD = 8;
		break;
	}
}

void hero::increase_stat(int target, int SP) throw(string) {
	if (SP < 1) {
		throw "Not enough SP!";
	}

	target++;
	SP--;
}