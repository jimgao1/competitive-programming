#include <bits/stdc++.h>

#define MAXN 60

using namespace std;

int dirX[] = {0, 0, 1, -1, -1, 1, 1, -1};
int dirY[] = {1, -1, 0, 0, -1, 1, -1, 1};

int T, R, C, W;
char grid[MAXN][MAXN];

bool search(int r, int c, int d, string str){
	if (str.size() == 0) return true;
	
	if (r < 0 || r >= R || c < 0 || c >= C) return false;
	if (tolower(grid[r][c]) != tolower(str[0])) return false;
	if (grid[r][c] == 0) return false;

        return search(r + dirX[d], c + dirY[d], d, str.substr(1));
}

int main(){
	cin >> T;
	while(T--){
	        memset(grid, 0, sizeof grid);
		
		cin >> R >> C;
		for (int i = 0; i < R; i++){
			string line;
			cin >> line;

			for (int j = 0; j < C; j++){
				grid[i][j] = line[j];
			}
		}

		cin >> W;
		while(W--){
			bool flag = false;
			string word;
			cin >> word;

			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					for (int k = 0; k < 8; k++){
						if (search(i, j, k, word)){
							printf("%d %d\n", i + 1, j + 1);
							flag = true;
							break;
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}
		}
		
		if (T != 0)
			cout << endl;
	}
}
 
