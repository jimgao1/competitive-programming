
#include <bits/stdc++.h>

#define MAXN 101
#define MAXK 5000001

using namespace std;

int N, k[MAXN], c[MAXN], cnt[MAXK];
bool dp[MAXK];
double total = 0, target;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> k[i] >> c[i];
        total += k[i] * c[i];
    }
    target = total / 2;

    int ans = 0;
    dp[0] = true;
    for (int i = 0; i < N; i++){
        memset(cnt, 0, sizeof cnt);
        /*
            cnt[j] indicates the number of time that the current element
            has been used in the current iteration. When cnt[j] exceeds
            k[i], this item can no longer be used.

            Makes the time complexity of this algorithm from O(N*W*K) to
            O(N * W)
        */
        for (int j = c[i]; j <= target; j++){
            if (dp[j - c[i]] && cnt[j - c[i]] < k[i] && !dp[j]){
                dp[j] = true;
                ans = max(ans, j);
                cnt[j] = cnt[j - c[i]] + 1;
            }
        }
    }

    cout << total - ans * 2 << "\n";
}

