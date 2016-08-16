
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int M, N, dp[MAXN][MAXN];
bool grid[MAXN][MAXN];

int f(int r, int c){
    if (r < 0 || r >= M || c < 0 || c >= N) return 0;
    if (dp[r][c] != -1) return dp[r][c];

    int ans = 0;
    if (r > 0) ans = max(ans, f(r - 1, c));
    if (c > 0) ans = max(ans, f(r, c - 1));

    if (grid[r][c]) ans++;

    return dp[r][c] = ans;
}

int main(){
    cin >> M >> N;
    memset(dp, -1, sizeof dp);
    while(true){
        int r, c;
        cin >> r >> c;

        if (r == 0 && c == 0) break;
        r--, c--;
        grid[r][c] = true;
    }

    cout << f(M - 1, N - 1) << endl;

}
