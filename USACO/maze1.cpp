/*
ID: jim_yub1
LANG: C++11
TASK: maze1
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

struct cell{
	bool north, south, east, west;

	void print(){
		cout << north << south << east << west << endl;
	}
};

struct location{
	int x, y;
};

cell map[40][105];
char input[81][210];
int minDistance[40][105];
int width, height;

int firstX = -1, firstY = -1, secondX = -1, secondY = -1;

void update(int x, int y, int dist){
	//cout << "x = " << x << ", y = " << y << ", dist = " << dist << endl;

	if (x < 0 || x >= width || y < 0 || y >= height) return;

	//map[x][y].print();

	if (minDistance[x][y] <= dist) return;

	minDistance[x][y] = dist;

	if (map[x][y].north) update(x, y - 1, dist + 1);
	if (map[x][y].south) update(x, y + 1, dist + 1);
	if (map[x][y].east) update(x + 1, y, dist + 1);
	if (map[x][y].west) update(x - 1, y, dist + 1);
}

int main(){
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

	cin >> width >> height;

	string q;
	getline(cin, q);

	/*
		Constructing the map
	*/
	for (int i = 0; i < height * 2 + 1; i++){
		string s;
		getline(cin, s);

		//cout << "length = " << s.length() << endl;
		for (int j = 0; j < width * 2 + 1; j++){
			char c = s[j];
			input[j][i] = c;

		}
	}

	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			int newPosX = j * 2 + 1, newPosY = i * 2 + 1;

			map[j][i].north = input[newPosX][newPosY - 1] == ' ';
			map[j][i].south = input[newPosX][newPosY + 1] == ' ';
			map[j][i].west = input[newPosX - 1][newPosY] == ' ';
			map[j][i].east = input[newPosX + 1][newPosY] == ' ';

			//cout << map[j][i].north << map[j][i].south << map[j][i].west << map[j][i].east << "\t";
		}
		//cout << endl;
	}

	/*
		Find the exit coordinates
	*/

	for (int i = 0; i < width; i++) {
		if (map[i][0].north)
			if (firstX == -1)
				firstX = i, firstY = 0;
			else
				secondX = i, secondY = 0;

		if (map[i][height - 1].south)
			if (firstX == -1)
				firstX = i, firstY = height - 1;
			else
				secondX = i, secondY = height - 1;
	}

	for (int i = 0; i < height; i++){
		if (map[0][i].west)
			if (firstX == -1)
				firstX = 0, firstY = i;
			else
				secondX = 0, secondY = i;

		if (map[width - 1][i].east)
			if (firstX == -1)
				firstX = width - 1, firstY = i;
			else
				secondX = width - 1, secondY = i;
	}

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			minDistance[j][i] = 1048576;

	update(firstX, firstY, 1);
	update(secondX, secondY, 1);

	int maxDist = -1;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			maxDist = max(maxDist, minDistance[j][i]);

	cout << maxDist << endl;

	//system("pause");
	return 0;
}
