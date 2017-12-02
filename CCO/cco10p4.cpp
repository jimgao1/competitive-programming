
#include <bits/stdc++.h>

using namespace std;

int T, N, B, dp[10][4000];
vector<pair<int, int>> comp[10];

int main(){
    cin >> T >> N;
    for (int i = 0, a, b, c; i < N; i++){
        cin >> a >> b >> c;
        comp[c].push_back({a, b});
    }
    cin >> B;

    for (int i = 1; i <= T; i++){
        for (int j = 0; j <= B; j++){

            dp[i][j] = dp[i - 1][j];

            for (int k = 0; k < comp[i].size(); k++){
                if (comp[i][k].first >= j){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - comp[i][k].first] + comp[i][k].second);
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= B; i++){
        ans = max(ans, dp[T][i]);
    }

    cout << (ans == 0 ? -1 : ans) << endl;
}
