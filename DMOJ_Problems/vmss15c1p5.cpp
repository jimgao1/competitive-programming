
#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int N, R, S, dp[11][1001][1001];
int value[11], cost[11], weight[11];

string name[1001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> S;
    for (int i = N; i > 0; i--)
        cin >> name[i] >> value[i] >> cost[i] >> weight[i];

    for (int i = 1; i <= N; i++){
        for (int j = cost[i]; j <= R; j++){
            for (int k = weight[i]; k <= S; k++){
                dp[i][j][k] = max(dp[i - 1][j][k],
                            dp[i][j - cost[i]][k - weight[i]] + value[i]);

            }
        }
    }

    cout << dp[N][R][S] << endl;

    for (int i = N; i > 0; i--){
        int cnt = 0;
        while(true){
            if (R <= 0 && S <= 0) break;
            if (dp[i][R][S] == dp[i - 1][R][S]) break;

            R -= cost[i], S -= weight[i];
            cnt++;
        }

        cout << name[i] << " " << cnt << endl;
    }

}
