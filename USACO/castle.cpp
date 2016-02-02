/*
ID: jim_yub1
LANG: C++11
TASK: castle
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

#define USACO
#define FILEIN "castle.in"
#define FILEOUT "castle.out"

using namespace std;

struct node{
	bool wallUp, wallDown, wallLeft, wallRight;
};

node map[51][51];
int sizeX, sizeY;

bool searchVisited[51][51];
int largestRoom, roomCount;

void printMap(){
	for (int i = 0; i < sizeY; i++){
		for (int j = 0; j < sizeX; j++){
			cout << "|";
			if (map[j][i].wallUp) cout << "U";
			if (map[j][i].wallDown) cout << "D";
			if (map[j][i].wallLeft) cout << "L";
			if (map[j][i].wallRight) cout << "R";
			cout << "|\t";
		}
		cout << endl;
	}
}

int search(int locationX, int locationY){

	if (locationX < 0 || locationX >= sizeX) return 0;
	if (locationY < 0 || locationY >= sizeY) return 0;

	if (searchVisited[locationX][locationY]) return 0;
	searchVisited[locationX][locationY] = true;

	int searchSize = 1;

	if (!map[locationX][locationY].wallUp) searchSize += search(locationX, locationY - 1);
	if (!map[locationX][locationY].wallDown) searchSize += search(locationX, locationY + 1);
	if (!map[locationX][locationY].wallLeft) searchSize += search(locationX - 1, locationY);
	if (!map[locationX][locationY].wallRight) searchSize += search(locationX + 1, locationY);

	return searchSize;
}

int main()
{

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif // LOCAL

	cin >> sizeX >> sizeY;

	for (int i = 0; i < sizeY; i++){
		for (int j = 0; j < sizeX; j++){
			int nodeInfo;
			cin >> nodeInfo;

			map[j][i].wallDown = false;
			map[j][i].wallLeft = false;
			map[j][i].wallUp = false;
			map[j][i].wallRight = false;

			if (nodeInfo >= 8){
				map[j][i].wallDown = true;
				nodeInfo -= 8;
				//cout << "D";
			}

			if (nodeInfo >= 4){
				map[j][i].wallRight = true;
				nodeInfo -= 4;;
				//cout << "R";
			}

			if (nodeInfo >= 2){
				map[j][i].wallUp = true;
				nodeInfo -= 2;
				//cout << "U";
			}

			if (nodeInfo >= 1){
				map[j][i].wallLeft = true;
				//cout << "L";
			}


			//cout << "data read. i = " << i << ", j = " << j << endl;
		}
	}

	roomCount = 0;
	largestRoom = 0;

	//cout << "mapSizeX: " << sizeX << ", mapSizeY: " << sizeY << endl;
	//();

	for (int i = 0; i < sizeX; i++){
		for (int j = 0; j < sizeY; j++){
			if (!searchVisited[i][j]){
				roomCount += 1;
				largestRoom = max(largestRoom, search(i, j));
			}
		}
	}

	cout << roomCount << endl;
	cout << largestRoom << endl;

	int maxModX = -1;
	int maxModY = -1;
	int maxModSize = 0;
	char modDirection = 0;

	for (int i = 0; i < sizeX; i++){
		for (int j = sizeY - 1; j >= 0; j--){
			//cout << "i = " << i << ", j = " << j << endl;

/*
				North Wall
			*/

			int largest = 0;

			if (map[i][j].wallUp){
				map[i][j].wallUp = false;
				for (int k = 0; k < sizeX; k++)
					for (int l = 0; l < sizeY; l++)
						searchVisited[k][l] = false;

				largest = search(i, j);

				map[i][j].wallUp = true;


			}

			//cout << largest << endl;

			if (largest > maxModSize){
				maxModX = i;
				maxModY = j;
				modDirection = 'N';
				maxModSize = largest;

				//cout << largest << " x = " << maxModX + 1 << ", y = " << maxModY + 1 << ", direction = " << modDirection << endl;
			}


			/*
			East Wall
			*/

			largest = 0;

			if (map[i][j].wallRight){
				map[i][j].wallRight = false;
				for (int k = 0; k < sizeX; k++)
					for (int l = 0; l < sizeY; l++)
						searchVisited[k][l] = false;

				largest = search(i, j);

				map[i][j].wallRight = true;

			}

			//cout << largest << endl;

			if (largest > maxModSize){
				maxModX = i;
				maxModY = j;
				modDirection = 'E';
				maxModSize = largest;

				//cout << largest << " x = " << maxModX + 1 << ", y = " << maxModY + 1 << ", direction = " << modDirection << endl;
			}

			//cout << j + 1 << " " << i + 1 << " E " << largest << endl;


			//cout << j + 1 << " " << i + 1 << " N " << largest << endl;

		}
	}

	cout << maxModSize << endl;
	cout << maxModY + 1 << " " << maxModX + 1 << " " << modDirection << endl;

	return 0;
}

