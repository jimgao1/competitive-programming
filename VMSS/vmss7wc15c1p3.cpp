
#include <bits/stdc++.h>

#define MAXN 7001

using namespace std;

int N, K, dp[MAXN];
bool prime[MAXN];
vector<int> pp;

void sieve(){
    memset(prime, 0x1, sizeof prime);
    prime[1] = 0;
    for (int i = 2; i < MAXN; i++){
        if (prime[i]){
            for (int j = 2 * i; j < MAXN; j += i){
                prime[j] = 0;
            }
            pp.push_back(i);
        }
    }
}

int calc(int n){
    if (n < 0) return 1e9;
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = 1e9;
    for (int i : pp){
        if (i <= n){
            ans = min(ans, calc(n - i) + 1);
        }
    }

    return dp[n] = ans;
}

int main(){
    cin >> N >> K;
    sieve();

    memset(dp, -1, sizeof dp);
    int cnt = 0;
    for (int i = 1; i <= N; i++){
        if (calc(i) == K) cnt++;
    }

    cout << cnt << endl;
}

