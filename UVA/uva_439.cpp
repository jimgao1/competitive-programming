
#include <bits/stdc++.h>

using namespace std;

int minDist[20][20], ax, ay, bx, by;
bool visited[20][20];
string src, tar;

queue<pair<int, int> > q;

int dX[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dY[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

pair<int, int> translate(string str) {
	return{ (int)(str[0] - 'a'), (int)(str[1] - '0' - 1) };
}

int main() {

	while (cin >> src >> tar) {
		memset(minDist, 0x3f, sizeof minDist);
		memset(visited, 0, sizeof visited);

		ax = translate(src).first, ay = translate(src).second;
		bx = translate(tar).first, by = translate(tar).second;

		minDist[ax][ay] = 0;
        q.push({ax, ay});

        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++){
                int alt = minDist[x][y] + 1;
                int nX = x + dX[i], nY = y + dY[i];

                if (nX < 0 || nX >= 8 || nY < 0 || nY >= 8) continue;

                if (alt < minDist[nX][nY]){
                    minDist[nX][nY] = alt;
                    q.push({nX, nY});
                }
            }
        }

		printf("To get from %s to %s takes %d knight moves.\n", src.c_str(), tar.c_str(), minDist[bx][by]);
	}

}
