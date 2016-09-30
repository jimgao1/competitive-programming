#include <bits/stdc++.h>

#define MAXN 200

using namespace std;

int R, C, T;
char grid[MAXN][MAXN];

int main(){
    int r = 0, c = 0, dr = 0, dc = 1, t = 0;

    cin >> C >> R >> T;
    for (int i = 0; i < R; i++){
        string line;
        cin >> line;
        for (int j = 0; j < C; j++){
            grid[i][j] = line[j];

            if (line[j] == 'O'){
                r = i, c = j;
                grid[i][j] = '.';
            }
        }
    }

    while(true){
        //printf("r = %d, c = %d, dr = %d, dc = %d, t = %d\n", r, c, dr, dc, t);

        if (t > T) {
            printf("The observer stays within the grid.\n");
            return 0;
        }

        if (r < 0 || r >= R || c < 0 || c >= C){
            printf("The observer leaves the grid after %d tick(s).\n", t);
            return 0;
        }

        if (grid[r][c] == '/'){
            swap(dr, dc);
            dr = -1 * dr;
            dc = -1 * dc;

            grid[r][c] = '\\';
        } else if (grid[r][c] == '\\') {
            swap(dr, dc);

            grid[r][c] = '/';
        } else if (grid[r][c] == '-'){
            dr = -dr;

            if (dr != 0) grid[r][c] = '|';
        } else if (grid[r][c] == '|'){
            dc = -dc;

            if (dc != 0) grid[r][c] = '-';
        }

        r += dr, c += dc;
        t++;


    }


}
