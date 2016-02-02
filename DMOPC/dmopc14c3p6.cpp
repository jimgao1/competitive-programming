
#include <bits/stdc++.h>

using namespace std;

int N, T, P[2002][3], V[2002][3], dp[10001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 3; j++)
            cin >> P[i][j] >> V[i][j];

    for (int i = 1; i <= N; i++){
        for (int j = T; j >= 0; j--){
            for (int k = 0; k < 3; k++){
                if (j - P[i][k] >= 0)
                    dp[j] = max(dp[j], dp[j - P[i][k]] + V[i][k]);
            }
        }
    }

    int m = 0;
    for (int i = 0; i <= T; i++)
        m = max(m, dp[i]);

    cout << m << "\n";
}
