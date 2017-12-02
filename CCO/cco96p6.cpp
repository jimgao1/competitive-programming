
#include <bits/stdc++.h>

#define MAXN 17
#define INF 0x3f3f3f3f

using namespace std;

struct state{
    int cx, cy, dx, dy, st = 0;
    state(){  }
};

int T, X, Y, N;
int sx, sy, tx, ty;
bool blocked[MAXN][MAXN], visited[MAXN][MAXN][MAXN * 2 + 1][MAXN * 2 + 1];

queue<state> q;

int main(){
    cin >> T;
    while(T--){
        //fuck
        while(!q.empty()) q.pop();
        memset(blocked, 0, sizeof blocked);
        memset(visited, 0, sizeof visited);

        cin >> X >> Y;
        cin >> sx >> sy >> tx >> ty;
        cin >> N;
        for (int i = 0, x1, x2, y1, y2; i < N; i++){
            cin >> x1 >> x2 >> y1 >> y2;
            for (int j = x1; j <= x2; j++){
                for (int k = y1; k <= y2; k++){
                    blocked[j][k] = true;
                }
            }
        }
        state initial;
        initial.cx = sx, initial.cy = sy;
        initial.dx = 0, initial.dy = 0;
        q.push(initial);

        bool solved = false;
        while(!q.empty()){
            state cur = q.front();
            q.pop();

            if (abs(cur.dx) > 3 || abs(cur.dy) > 3) continue;

            if (visited[cur.cx][cur.cy][cur.dx + 4][cur.dy + 4]) continue;
            visited[cur.cx][cur.cy][cur.dx + 4][cur.dy + 4] = true;

            if (cur.cx == tx && cur.cy == ty){
               printf("Optimal solution takes %d hop(s).\n", cur.st);
               solved = true;
               break;
            }

            //printf("x = %d, y = %d, st = %d\n", cur.cx, cur.cy, cur.st);

            for (int ddx = -1; ddx <= 1; ddx++){
                for (int ddy = -1; ddy <= 1; ddy++){
                    int nx = cur.cx + cur.dx + ddx;
                    int ny = cur.cy + cur.dy + ddy;
                    if (nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
                    if (blocked[nx][ny]) continue;

                    state nstate;
                    nstate.cx = nx;
                    nstate.cy = ny;
                    nstate.dx = cur.dx + ddx;
                    nstate.dy = cur.dy + ddy;
                    nstate.st = cur.st + 1;
                    //printf("(%d, %d) -> (%d, %d)\n", cur.cx, cur.cy, nx, ny);

                    q.push(nstate);
                }
            }
        }

        if (!solved){
            printf("No solution.\n");
        }
    }
}

