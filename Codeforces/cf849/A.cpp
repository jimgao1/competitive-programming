#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, A[MAXN];
int dp[MAXN][MAXN];

bool calc(int cur, int cnt){
    if (cur == N) return (cnt % 2 == 1);
    if (dp[cur][cnt] != -1) return dp[cur][cnt] == 1;
    for (int j = cur; j < N; j++){
        if (A[cur] % 2 == 1 && A[j] % 2 == 1 && (j - cur + 1) % 2 == 1){
            if (calc(j + 1, cnt + 1)) {
                dp[cur][cnt] = 1;
                return true;
            }
        }
    }
    dp[cur][cnt] = 0;
    return false;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    memset(dp, -1, sizeof dp);
    cout << (calc(0, 0) ? "Yes": "No") << endl;
}
