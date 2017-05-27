
#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

int N, A[MAXN];
bool dp[MAXN][5001];
unordered_set<int> e;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A + N);
    reverse(A, A + N);

    //e.insert(A[0]);
    dp[0][0] = 1;
    for (int i = 1; i < N; i++){
        for (int j = 0; j <= 5000; j++){
            if (dp[i - 1][j]) dp[i][j] = 1;
            for (int k : e){
                int w = k - A[i];
                if (j - w >= 0 && dp[i - 1][j - w])
                    dp[i][j] = 1;
            }
        }
        e.insert(A[i]);
    }

    for (int i = 0; i <= 5000; i++){
        if (dp[N - 1][i])
            printf("%d ", i);
    }
    printf("\n");
}
