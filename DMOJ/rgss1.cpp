
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int A, B, C;
bool dp[MAXN];

int main(){
    cin >> A >> B >> C;
    dp[0] = 1;

    for (int i = 0; i <= C; i++){
        if (dp[i]){
            if (i + A <= C)
                dp[i + A] = 1;
            if (i + B <= C)
                dp[i + B] = 1;
        }
    }

    for (int i = C; i >= 0; i--){
        if (dp[i]){
            cout << i << endl;
            return 0;
        }
    }
}

