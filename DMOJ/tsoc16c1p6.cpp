#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, M, dp[MAXN][MAXN];
string a, b;

int calc(int i, int j){
    if (i > N || j > M) return 1e9;
    if (i == N && j == M) return 0;

    if (a[i] == b[j]) return calc(i + 1, j + 1);
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 1e9;

    ans = min(ans, calc(i + 1, j + 1) + 1);
    for (int k = 1; k <= 3; k++){
        ans = min(ans, calc(i + k, j) + 1);
        ans = min(ans, calc(i, j + k) + 1);
    }


    return dp[i][j] = ans;
}

int main(){
    cin >> N >> M >> a >> b;
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << endl;
}
