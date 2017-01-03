
#include <bits/stdc++.h>

#define MAXN 1001
#define INF 0x3f3f3f3f

using namespace std;

int T, X, cost[MAXN][11], dp[MAXN][11];

int main(){
    cin >> T;
    while(T--){
        cin >> X; X /= 100;

        for (int i = 9; i >= 0; i--){
            for (int j = 1; j <= X; j++){
                cin >> cost[j][i];
            }
        }
        memset(dp, 0x3f, sizeof dp);

        dp[0][0] = 0;
        for (int i = 0; i <= X; i++){
            for (int j = 0; j < 10; j++){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 30 - cost[i + 1][j]);
                if (i > 0)
                    dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + 20 - cost[i + 1][j]);
                if (i < 9)
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 60 - cost[i + 1][j]);
            }
        }


        cout << dp[X][0] << endl << endl;
    }
}

