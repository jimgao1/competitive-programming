
#include <bits/stdc++.h>

#define MAXN 16

using namespace std;

inline bool getBit(int i, int idx) { return i & (1 << idx); }
inline int setBit(int i, int idx) { return i | (1 << idx); }

int N, M, dp[(1 << MAXN)], group[(1 << MAXN)];
bool matrix[MAXN][MAXN];

int calc(int state){
    if (state == 0) return 0;
    if (dp[state] != -1) return dp[state];

    int ans = 1e9;
    for (int cur = 1; cur < (1 << N); cur++){
        bool flag = true;

        if (cur & (~state)) continue;

        if (!flag) continue;

        for (int i = 0; i < N; i++){
            if (!getBit(cur, i)) continue;
            for (int j = 0; j < N; j++){
                if (!getBit(cur, j)) continue;
                if (matrix[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }

        if (!flag) continue;

        int nxt = 0;
        for (int i = 0; i < N; i++){
            if (getBit(state, i) && !getBit(cur, i))
                nxt = setBit(nxt, i);
        }

        int alt = calc(nxt) + 1;

        if (alt < ans){
            ans = alt;
            group[state] = nxt;
        }
    }

    return dp[state] = ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        a--, b--;
        matrix[a][b] = matrix[b][a] = true;
    }

    int val = calc((1 << N) - 1);
    printf("%d\n", val);

    int cur = (1 << N) - 1;
    while(val--){
        for (int i = 0; i < N; i++){
            if (getBit(cur, i) && !getBit(group[cur], i)){
                printf("%d ", i + 1);
            }
        }
        printf("\n");

        cur = group[cur];
    }
}
