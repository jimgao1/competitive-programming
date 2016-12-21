#include <bits/stdc++.h>

using namespace std;

int N, dp[101][26], cnt[26];

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 2; j++){
            memset(cnt, 0, sizeof cnt);
            string str;
            cin >> str;
            for (int k = 0; k < str.size(); k++){
                cnt[str[k] - 'a'] ++;
            }

            for (int k = 0; k < 26; k++){
                dp[i][k] = max(dp[i][k], cnt[k]);
            }
        }

        if (i > 0)
            for (int k = 0; k < 26; k++){
                dp[i][k] += dp[i - 1][k];
            }
    }

    for (int i = 0; i < 26; i++){
        cout << dp[N - 1][i] << endl;
    }
}

