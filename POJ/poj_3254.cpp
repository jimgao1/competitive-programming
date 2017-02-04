
#include <bits/stdc++.h>

#define MAXN 13
#define ll long long

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }

int R, C, grid[MAXN];
ll dp[MAXN][(1 << MAXN)];
vector<int> pos;

ll calc(int cur, int pre){
    if (cur == R) return 1;
    if (dp[cur][pre] != -1) return dp[cur][pre];

    ll ans = 0;
    for (int cc : pos){
        if (cc & grid[cur]) continue;
        if (cc & pre) continue;
        ans += calc(cur + 1, cc);
    }

    return dp[cur][pre] = ans;
}

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0, x; j < C; j++){
            cin >> x;
            if (x == 0)
                grid[i] = setBit(grid[i], j);
        }
    }

    for (int i = 0; i < (1 << C); i++){
        bool flag = true;
        for (int j = 1; j < C - 1; j++){
            if (getBit(i, j)){
                if (getBit(i, j - 1) || getBit(i, j + 1)){
                    flag = false;
                    break;
                }
            }
        }

        if (flag) pos.push_back(i);
    }

    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << endl;
}

