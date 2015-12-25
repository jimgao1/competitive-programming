
#include <bits/stdc++.h>

using namespace std;

struct s{
    int x, y, st;
    s(int a, int b, int c){
        x = a, y = b, st = c;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int T, W, H;
char grid[51][51];
bool visited[51][51];

queue<s> q;

int main(){
    cin >> T;
    while(T--){
        memset(visited, 0, sizeof visited);
        memset(grid, 0, sizeof grid);

        cin >> W >> H;

        for (int i = 0; i < H; i++){
            string line;
            cin >> line;
            for (int j = 0; j < W; j++){
                grid[j][i] = line[j];

                if (grid[j][i] == 'C'){
                    q.push(s(j, i, 0));
                }
            }
        }

        bool flag = false;
        while(!q.empty()){
            int curX = q.front().x, curY = q.front().y;
            int cst = q.front().st;
            q.pop();

            if (grid[curX][curY] == 'X') continue;

            if (grid[curX][curY] == 'W'){
                if (cst >= 60)
                    cout << "#notworth" << endl;
                else
                    cout << cst << endl;

                flag = true;
                break;
            }


            for (int i = 0; i < 4; i++){
                int nx = curX + dx[i], ny = curY + dy[i];
                if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                if (grid[nx][ny] == 'X') continue;
                if (visited[nx][ny]) continue;

                q.push(s(nx, ny, cst + 1));
                visited[nx][ny] = true;
            }
        }

        if (!flag) cout << "#notworth" << endl;

        while(!q.empty()) q.pop();
    }
}
