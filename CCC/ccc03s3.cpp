#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAXN 30

using namespace std;

int room[MAXN][MAXN];
int sizeX;
int sizeY;
int flooring;

vector<int> roomSize;

bool desc(int a, int b){
    return b < a;
}

int dfs(int x, int y){
    if (x < 0 || x >= sizeX) return 0;
    if (y < 0 || y >= sizeY) return 0;

    if (room[x][y] == 1) return 0;

    room[x][y] = 1;

    return dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1) + 1;
}

int main(void){
    int total = 0;

    cin >> flooring >> sizeY >> sizeX;

    for (int i=0; i<sizeY; i++){
        string line;
        cin >> line;

        for (int j=0; j<sizeX; j++){
            if (line[j] == 'I')
                room[j][i] = 1;
            else
                room[j][i] = 0;
        }
    }

    for (int i=0; i<sizeY; i++){
        for (int j=0; j<sizeX; j++){
            if (room[j][i] == 0){
                int cur = dfs(j, i);
                total += cur;
                roomSize.push_back(cur);
            }
        }
    }

    sort(roomSize.begin(), roomSize.end(), desc);

    int roomCount = 0;
    while(true){
        if (flooring < roomSize[roomCount]){
            if (roomCount == 1)
                cout << roomCount << " room, " << flooring << " square metre(s) left over" << endl;
            else
                cout << roomCount << " rooms, " << flooring << " square metre(s) left over" << endl;
            return 0;
        }

        roomCount += 1;
        flooring -= roomSize[roomCount - 1];
    }
}
