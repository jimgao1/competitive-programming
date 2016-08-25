
#include <bits/stdc++.h>

#define MAXN 46001

using namespace std;

int K, W, T, N, w[11], v[11], dp[MAXN];

int main(){
    cin >> K;
    while(K--){
        cin >> W >> T >> N;
        for (int i = 1; i <= N; i++){
            cin >> w[i] >> v[i];
            w[i] /= 1000;
        }

        for (int k = 0; k < T; k++){
            int total = W / 1000;
            memset(dp, 0, sizeof dp);

            for (int i = 1; i <= N; i++){
                for (int j = w[i]; j <= total; j++){
                    dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                }
            }

            W += dp[total];
        }

        cout << W << endl;
    }
}

