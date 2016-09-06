
#include <bits/stdc++.h>

#define MAXN 33

using namespace std;

int T;
unsigned long long dp[MAXN][MAXN];

int main(){
    for (int i = 0; i < MAXN; i++){
        dp[i][0] = dp[0][i] = 1;
    }

    for (int i = 1; i < MAXN; i++){
        for (int j = 1; j < MAXN; j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cin >> T;
    for (int c = 0, F, E; c < T; c++){
        cin >> F >> E;

        int low = 0, high = 32;
        while(low <= high){
            int mid = (low + high) / 2;
            if (dp[mid][E] >= F + 1){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (low > 32)
            cout << "Impossible" << endl;
        else
            cout << low << endl;
    }
}

