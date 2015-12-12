#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int C, M, n[3500], k[3500], dp[2][13000];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> M;
    for (int i = 1; i <= C; i++) cin >> k[i] >> n[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= C; i++){
        for (int j = 0; j <= M; j++){
            if (j - k[i] < 0){
                dp[i % 2][j] = dp[(i - 1) % 2][j];
            } else {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - k[i]] + n[i]);
            }
        }
    }


    cout << max(dp[0][M], dp[1][M]) << "\n";
}
