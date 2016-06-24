
#include <bits/stdc++.h>

using namespace std;

int v[] = {1, 5, 10, 25, 50};
long long dp[30010][7];

long long f(int left, int id){
    if (id >= 5) return 0;
    if (left == 0) return 1;
    if (left < 0) return 0;

    if (dp[left][id] != -1) return dp[left][id];

    dp[left][id] = f(left, id + 1) + f(left - v[id], id);
    return dp[left][id];
}

int main(){

    for (int i = 0; i < 30010; i++)
        for (int j = 0; j < 7; j++)
            dp[i][j] = -1;

    int x;
    while(cin >> x){			//Can I please murder the problem writer?

        long long ans = f(x, 0);
        if (ans == 1){
            printf("There is only 1 way to produce %d cents change.\n", x);
        } else {
            printf("There are %lld ways to produce %d cents change.\n", ans, x);
        }
    }
}
