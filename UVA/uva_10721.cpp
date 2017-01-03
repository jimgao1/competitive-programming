
#include <bits/stdc++.h>

#define ll long long
#define MAXN 51

using namespace std;

ll N, K, M, dp[MAXN][MAXN];

ll calc(int cur, int left){
    if (cur == N && left == 0) return 1LL;
    if (cur == N || left == 0) return 0LL;

    if (dp[cur][left] != -1) return dp[cur][left];

    ll ans = 0;
    for (int i = 1; i <= M && cur + i <= N; i++){
        ans += calc(cur + i, left - 1);
    }

    return dp[cur][left] = ans;
}

int main(){
    while(cin >> N >> K >> M){
        memset(dp, -1, sizeof dp);
        cout << calc(0, K) << endl;
    }
}

