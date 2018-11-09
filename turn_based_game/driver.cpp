#include "libraries.h"

int** read_dungeon_data(string filename);
void print_dungeon(int **working);
void run_dungeon(int **working);
void search(int **working, int& x, int& y, int match);
void move(int** working, int** original, int &x, int &y, char userInput);

int main() {

	int** working_dungeon;
	string ui_filename;

	//Select dungeon
	cout << "Select dungeon to run: "; cin >> ui_filename;
	//Read dungeon
	working_dungeon = read_dungeon_data(ui_filename);
	//Message
	cout << "LOADED SUCCESSFULLY!" << endl;

	system("pause");
	system("cls");

	//Run dungeon
	run_dungeon(working_dungeon);

	system("pause");

	return 0;

}


int** read_dungeon_data(string filename) {
	ifstream i_file;
	int** holder = new int*[9];

	i_file.open(filename + ".txt");

	assert(!i_file.fail());

	for (int i = 0; i < 9; i++) {
		holder[i] = new int[9];
		for (int j = 0; j < 9; j++) {
			i_file >> holder[i][j];
		}
	}

	i_file.close();

	return holder;

}
void print_dungeon(int **working) {
	char x;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			switch (working[i][j]) {
			case 0:
				x = 'X';
				break;
			case 1:
				x = 'O';
				break;
			case 2:
			case 3:
				x = ' ';
				break;
			case 9:
				x = 'B';
				break;
			case -1:
				x = 'H';
				break;
			}

			wcout << x << ' ';
		}
		cout << '\n';
	}
}
void search(int **working, int& x, int& y, int match) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (working[i][j] == match) {
				y = i;
				x = j;
			}
		}
	}
}

void run_dungeon(int **working) {
	char userInput;
	int x, y;

	//Create a copy of working in order to restore when player moves
	int **original = new int*[9];
	for (int i = 0; i < 9; i++) {
		original[i] = new int[9];
		for (int j = 0; j < 9; j++) {
			original[i][j] = working[i][j];
		}
	}

	search(working, x, y, 1);
	working[y][x] = -1;

	do {
	print_dungeon(working);
	cout << "\nMove (w/a/s/d): "; cin >> userInput;
	move(working, original, x, y, userInput);
	system("cls");
		
	} while (original[y][x] != 9);

	cout << "You reached the boss! Congratulations!" << endl;
}

void move(int** working, int** original, int &x, int &y, char userInput) {

	int org_x = x;
	int org_y = y;

	switch (userInput) {
	case 'w':
		y++;
		break;
	case 'a':
		x--;
		break;
	case 's':
		y--;
		break;
	case 'd':
		x++;
		break;
	}

	if (working[y][x] != 0 && (x < 9 && y < 9 && x > -1 && y > -1) ) {
		working[org_y][org_x] = original[org_y][org_x];
		working[y][x] = -1;
	}
	else {
		cout << "Invalid move!" << endl;
		x = org_x; y = org_y;
		system("pause");
	}
}





