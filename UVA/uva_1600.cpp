
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct state{
    int x, y, steps, turbo;
    state(int a, int b, int c, int d) {
        x = a, y = b, steps = c, turbo = d;
    }
};

int dX[] = {1, 0, -1, 0};
int dY[] = {0, 1, 0, -1};

int C, K, M, N, minDist, bestTime[21][21], bestTurbo[21][21];
bool room[21][21];

queue<state> q;

inline int nmin(int a, int b) { return (a < b ? a : b); }

int main(){
    scanf("%d", &C);

    while(C--){
        memset(room, 0, sizeof room);
        memset(bestTime, 0x3f, sizeof bestTime);
        memset(bestTurbo, 0x3f, sizeof bestTurbo);

        minDist = INF;

        scanf("%d%d%d", &M, &N, &K);
        for (int i = 0; i < M; i++){
            for (int j = 0, x; j < N; j++){
                scanf("%d", &x);
                room[j][i] = (x == 1);
            }
        }

        q.push(state(0, 0, 0, 0));
        while(!q.empty()){
            state cur = q.front();
            q.pop();

            if (cur.turbo > K) continue;
            if (cur.steps > minDist) continue;

            if (cur.steps >= bestTime[cur.x][cur.y] && cur.turbo >= bestTurbo[cur.x][cur.y]) continue;

            bestTime[cur.x][cur.y] = nmin(bestTime[cur.x][cur.y], cur.steps);
            bestTurbo[cur.x][cur.y] = nmin(bestTurbo[cur.x][cur.y], cur.turbo);

            if (cur.x == N - 1 && cur.y == M - 1){
                minDist = nmin(minDist, cur.steps);
                continue;
            }

            for (int i = 0; i < 4; i++){
                int nX = cur.x + dX[i], nY = cur.y + dY[i];

                if (nX < 0 || nX >= N || nY < 0 || nY >= M) continue;

                if (room[nX][nY])
                    q.push(state(nX, nY, cur.steps + 1, cur.turbo + 1));
                else
                    q.push(state(nX, nY, cur.steps + 1, 0));
            }
        }

        printf("%d\n", (minDist == INF ? -1 : minDist));
    }
}
