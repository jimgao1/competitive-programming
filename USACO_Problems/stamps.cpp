/*
ID: jim.yub1
LANG: C++11
TASK: stamps
*/

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

#define FILEIN "stamps.in"
#define FILEOUT "stamps.out"

using namespace std;

int N, K, counter = 1, dp[2000010], v[101];

int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);

    cin >> K >> N;
    for (int i = 0; i < N; i++) cin >> v[i];

    dp[0] = 0;

    while(true){
        dp[counter] = INF;

        for (int i = 0; i < N; i++)
            if (counter - v[i] >= 0)
                dp[counter] = min(dp[counter], dp[counter - v[i]] + 1);

        if (dp[counter] > K){
            cout << counter - 1 << endl;
            return 0;
        }

        counter++;
    }

    return 0;
}
