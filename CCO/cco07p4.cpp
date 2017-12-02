
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int P, R, votes[11][MAXN], dp[MAXN][MAXN];

int sum(int party, int from, int to){
    int ans = votes[party][to];
    if (from > 0) ans -= votes[party][from - 1];
    return ans;
}

int calc(int cur, int merges){
    if (cur == R){
        if (merges > 0) return -1e9;
        return 0;
    }

    if (dp[cur][merges] != -1) return dp[cur][merges];

    int ans = -1e9;
    for (int i = 0; i <= merges && cur + i < R; i++){
        int won = 1;
        for (int j = 1; j < P; j++){
            if (sum(j, cur, cur + i) >= sum(0, cur, cur + i)){
                won = 0;
                break;
            }
        }

        ans = max(ans, calc(cur + i + 1, merges - i) + won);
    }

    return dp[cur][merges] = ans;
}

int main(){
    cin >> R >> P;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < P; j++){
            cin >> votes[j][i];
        }
    }

    for (int i = 0; i < P; i++){
        for (int j = 1; j < R; j++){
            votes[i][j] += votes[i][j - 1];
        }
    }

    memset(dp, -1, sizeof dp);

    for (int i = 0; i < R; i++){
        int cnt = calc(0, i);
        if (cnt >= (R - i) / 2 + 1){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}

