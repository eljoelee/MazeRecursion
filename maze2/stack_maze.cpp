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

	path[position.x][position.y] = '.'; //발자취 기록

	cout << "X : " << position.x << " Y : " << position.y << "\n"; //경로 출력

	if (position.x < 0 || position.y < 0 || position.x > 11 || position.y > 15)
		return;

	if (maze[position.x][position.y] == 'x') { //출구
		cout << "\n====탐색 후====\n";

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

	//끝난 부분 탐색은 더이상 참조할 필요가 없기 때문에 0으로 돌려놓는다.
	path[position.x][position.y] = '0';
}
int main() {
	ifstream file;

	Position pos;

	pos.x = 0;
	pos.y = 0;

	file.open("miro_road.txt");

	cout << "====탐색 전====\n";

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

	cout << "\n====경로 탐색====\n";

	PathOfMaze(pos);

	system("PAUSE");
	return 0;
}