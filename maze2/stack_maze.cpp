#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

typedef struct Position {
	int x;
	int y;
}Position;

char maze[11][15];
char path[11][15];

void PathOfMaze(Position position) {
	
	Position tmp;

	path[position.x][position.y] = '.'; //������ ���

	cout << "X : " << position.x << " Y : " << position.y << "\n"; //��� ���

	if (position.x < 0 || position.y < 0 || position.x > 11 || position.y > 15)
		return;

	if (maze[position.x][position.y] == 'x') { //�ⱸ
		cout << "\n====Ž�� ��====\n";

		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 15; j++) {
				cout << path[i][j];
			}
			cout << "\n";
		}
		system("pause");
		exit(1);
	}

	if (maze[position.x][position.y + 1] != '1' && path[position.x][position.y + 1] == '0') {
		tmp.x = position.x;
		tmp.y = position.y + 1;
		PathOfMaze(tmp);
	}
	if (maze[position.x][position.y - 1] != '1' && path[position.x][position.y - 1] == '0') {
		tmp.x = position.x;
		tmp.y = position.y - 1;
		PathOfMaze(tmp);
	}
	if (maze[position.x + 1][position.y] != '1' && path[position.x + 1][position.y] == '0') {
		tmp.x = position.x + 1;
		tmp.y = position.y;
		PathOfMaze(tmp);
	}
	if (maze[position.x - 1][position.y] != '1' && path[position.x - 1][position.y] == '0') {
		tmp.x = position.x - 1;
		tmp.y = position.y;
		PathOfMaze(tmp);
	}
	if (maze[position.x + 1][position.y + 1] != '1' && path[position.x + 1][position.y + 1] == '0') {
		tmp.x = position.x + 1;
		tmp.y = position.y + 1;
		PathOfMaze(tmp);
	}
	if (maze[position.x + 1][position.y - 1] != '1' && path[position.x + 1][position.y - 1] == '0') {
		tmp.x = position.x + 1;
		tmp.y = position.y - 1;
		PathOfMaze(tmp);
	}
	if (maze[position.x + 1][position.y - 1] != '1' && path[position.x + 1][position.y - 1] == '0') {
		tmp.x = position.x + 1;
		tmp.y = position.y - 1;
		PathOfMaze(tmp);
	}
	if (maze[position.x - 1][position.y + 1] != '1' && path[position.x - 1][position.y + 1] == '0') {
		tmp.x = position.x - 1;
		tmp.y = position.y + 1;
		PathOfMaze(tmp);
	}

	//���� �κ� Ž���� ���̻� ������ �ʿ䰡 ���� ������ 0���� �������´�.
	path[position.x][position.y] = '0';
}
int main() {
	ifstream file;

	Position pos;

	pos.x = 0;
	pos.y = 0;

	file.open("miro_road.txt");

	cout << "====Ž�� ��====\n";

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 15; j++) {
			file >> maze[i][j];
			cout << maze[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 15; j++) {
			path[i][j] = '0';
		}
	}

	cout << "\n====��� Ž��====\n";

	PathOfMaze(pos);

	system("PAUSE");
	return 0;
}