
#include <bits/stdc++.h>

#define MAXN 100010
#define INF 1e9

using namespace std;

struct {
    int moves, turns;
} dp[MAXN][7][3];

int N;
bool pos[MAXN][7];

int main(){
    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        for (int j = 0, t; j < x; j++){
            cin >> t;
            pos[i][t - 1] = 1;
        }
    }

    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < 7; j++){
            for (int k = 0; k < 3; k++){
                dp[i][j][k].moves = INF;
                dp[i][j][k].turns = INF;
            }
        }
    }

    for (int i = 0; i < 7; i++){
        if (!pos[0][i]) continue;
        for (int j = 0; j < 3; j++){
            dp[0][i][j].moves = 0;
            dp[0][i][j].turns = 0;
        }
    }

    for (int i = 1; i < N; i++){
        for (int src = 0; src < 7; src++){
            if (!pos[i - 1][src]) continue;
            for (int d = 0; d < 3; d++){
                for (int tar = 0; tar < 7; tar++){
                    if (!pos[i][tar]) continue;

                    int mDist = dp[i - 1][src][d].moves + abs(src - tar);
                    int mTurns = dp[i - 1][src][d].turns;
                    int dir = 0;

                    if (tar < src) dir = 1;
                    if (tar > src) dir = 2;

                    if (dir != d && i != 1) mTurns++;

                    if (mDist < dp[i][tar][dir].moves){
                        dp[i][tar][dir].moves = mDist;
                        dp[i][tar][dir].turns = mTurns;
                    } else if (mDist == dp[i][tar][dir].moves){
                        dp[i][tar][dir].turns = min(dp[i][tar][dir].turns, mTurns);
                    }
                }
            }
        }
    }

    int ans1 = INF, ans2 = INF;
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 3; j++){
            if (dp[N - 1][i][j].moves < ans1){
                ans1 = dp[N - 1][i][j].moves;
                ans2 = dp[N - 1][i][j].turns;
            } else if (dp[N - 1][i][j].moves == ans1){
                ans2 = min(ans2, dp[N - 1][i][j].turns);
            }
        }
    }

    printf("%d %d\n", ans1, ans2);
}
