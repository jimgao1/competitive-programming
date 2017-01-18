#include <bits/stdc++.h>

#define MAXN 251

using namespace std;

int N, K, dp[MAXN][MAXN][MAXN];

int calc(int people, int pies, int m){
    if (people == 0){
        if (pies == 0) return 1;
        return 0;
    }
    if (pies == 0) return 0;

    if (dp[people][pies][m] != -1) return dp[people][pies][m];

    int ans = 0;
    for (int i = m; i <= pies; i++){
        ans += calc(people - 1, pies - i, i);
    }

    return dp[people][pies][m] = ans;
}

int main(){
    cin >> N >> K;

    memset(dp, -1, sizeof dp);
    cout << calc(K, N, 1) << endl;
}
