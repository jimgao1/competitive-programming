
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int X, Y, M;
char grid[81][376];
bool possible[81][376];
vector<char> directions;

int main(){
    memset(grid, 0, sizeof grid);
    memset(possible, 0, sizeof possible);

    cin >> Y >> X;

    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X; j++){
            cin >> grid[j][i];
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++){
        char cur;
        cin >> cur;

        directions.push_back(cur);
    }

    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++){
            //if (grid[i][j] == 'X') continue;
            for (int k = 0; k < 4; k++){
                int cx = i, cy = j;

                int facing = k;
                bool flag = false;

                for (char c : directions){
                    if (cx < 0 || cx >= X || cy < 0 || cy >= Y) {
                        flag = true;
                        break;
                    }

                    if (grid[cx][cy] == 'X') {
                        flag = true;
                        break;
                    }

                    if (c == 'F'){
                        cx += dx[facing], cy += dy[facing];
                    } else if (c == 'L'){
                        facing -= 1;
                        while(facing < 0) facing += 4;
                    } else if (c == 'R'){
                        facing += 1;
                        while(facing >= 4) facing -= 4;
                    }
                }

                if (!flag){
                    possible[cx][cy] = true;
                }
            }
        }
    }

    for (int i = 0; i < Y; i++){
        for (int j = 0; j < X; j++){
            if (grid[j][i] == '.'){
                if (possible[j][i])
                    printf("*");
                else
                    printf(".");
            } else {
                printf("X");
            }
        }

        printf("\n");
    }
}
