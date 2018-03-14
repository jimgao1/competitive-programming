
#include <bits/stdc++.h>

#define MAXN 21

using namespace std;

int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

int r, c, r1, c1, st, dir = 0;
bool visited[MAXN][MAXN];

int main(){
	cin >> c >> r >> c1 >> r1 >> st;

	for (int i = 0; i < r1; i++)
		for (int j = 0; j < c1; j++)
			visited[i][j] = visited[i][c - j - 1] = visited[r - i - 1][j] = visited[r - i - 1][c - j - 1] = 1;

	int cr = 0, cc = c1;
	while(true) {
		st--;
		visited[cr][cc] = 1;
		bool f = 0;
		dir = (dir + 3) % 4;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[dir], nc = cc + dc[dir];
			if (nr >= 0 && nr < r && nc >= 0 && nc < c && !visited[nr][nc]) {
				f = 1;
				cr = nr, cc = nc;
				break;
			}
			dir = (dir + 1) % 4;
		}
		if (!f || st == 0) {
			printf("%d\n%d\n", ++cc, ++cr);
			return 0;
		}
	}
}
