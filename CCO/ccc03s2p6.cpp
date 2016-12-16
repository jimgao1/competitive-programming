


#include <bits/stdc++.h>

#define MAXN 110

using namespace std;

struct state{
    int r, c, left;
    double cost;
    state(int rr, int cc, int _, double d){
        r = rr, c = cc, left = _, cost = d;
    }
};

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int T, R, C, F, K;
double gas[MAXN][MAXN], dp[MAXN][MAXN][2 * MAXN];
queue<state> q;

int main(){
    cin.sync_with_stdio(0);
    cin.tie();

    cin >> T;
    while(T--) {
        cin >> R >> C >> F >> K;
        F = min(F, R * C);

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                for (int k = 0; k <= F; k++)
                    dp[i][j][k] = 1e9;

                gas[i][j] = 1e9;
            }
        }

        for (int i = 0; i < K; i++) {
            int rr, cc;
            double price;
            cin >> rr >> cc >> price;
            rr-- ,cc--;

            gas[rr][cc] = min(gas[rr][cc], price);
        }

        q.push(state(0, 0, F, 0));
        dp[0][0][F] = 0;
        while (!q.empty()) {
            state cur = q.front();
            q.pop();

            if (cur.left < 0) continue;
            if (cur.cost > dp[cur.r][cur.c][cur.left]) continue;
            //if (cur.r == R - 1 && cur.c == C - 1) continue;

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dx[i], nc = cur.c + dy[i];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

                if (gas[cur.r][cur.c] != 1e9){
                    for (int j = 0; cur.left + j <= F; j++){
                        double alt = cur.cost + j * gas[cur.r][cur.c];
                        int left = cur.left + j - 1;
                        if (left >= 0 && alt < dp[nr][nc][left]){
                            dp[nr][nc][left] = alt;
                            q.push(state(nr, nc, left, alt));
                        }
                    }
                } else {
                    if (cur.left > 0 && cur.cost < dp[nr][nc][cur.left - 1]) {
                        dp[nr][nc][cur.left - 1] = cur.cost;
                        q.push(state(nr, nc, cur.left - 1, cur.cost));
                    }
                }
            }
        }

        double ans = 1e9;
        for (int i = 0; i <= F; i++) {
            ans = min(ans, dp[R - 1][C - 1][i]);
        }

        if (ans == 1e9) {
            printf("Stranded on the shoulder\n");
        } else {
            printf("%.2f\n", ans);
        }
    }
}
