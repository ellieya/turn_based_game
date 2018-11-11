monster::monster(int ID) {
	switch (ID) {
	case 0:
		name = "TYPE 0";
		HP = 20;
		ATK = 10;
		DEF = 5;
		SPD = 5;
		break;
	case 1:
		name = "TYPE 1";
		HP = 20;
		ATK = 10;
		DEF = 5;
		SPD = 5;
		break;
	case 2:
		name = "TYPE 2";
		HP = 40;
		ATK = 15;
		DEF = 10;
		SPD = 5;
		break;
	}
}