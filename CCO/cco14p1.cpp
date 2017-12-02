
#include <bits/stdc++.h>

using namespace std;

char c[2001][2001];
int N, dp[2001][2001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> c[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (c[i][j] == '#') dp[i][j] = 1;

    for (int i = N - 2; i >= 0; i--){
        for (int j = 1; j < N - 1; j++){
                
                
            if (c[i][j] == '#' && c[i + 1][j] == '#' && c[i + 1][j - 1] == '#' && c[i + 1][j + 1] == '#')
                dp[i][j] += min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans += dp[i][j];

    printf("%d\n", ans);

}
