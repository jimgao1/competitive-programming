
#include <bits/stdc++.h>

#define MAXN 2001
#define MOD 1000000007
#define ll long long

using namespace std;

int T;
ll dp1[MAXN][MAXN], dp2[MAXN][MAXN];
string str;

//At any time, a must have more points than b
ll calc1(int a, int b){
    if (a < 0 || b < 0) return 0;
    if (a == 0 && b == 0) return 1;
    if (a <= b) return 0;

    if (dp1[a][b] != -1) return dp1[a][b];

    return dp1[a][b] = ((calc1(a - 1, b) % MOD) + (calc1(a, b - 1) % MOD)) % MOD;
}

//At any time, a cannot have more points than b
ll calc2(int a, int b){
    if (a < 0 || b < 0) return 0;
    if (a == 0 && b == 0) return 1;
    if (a > b) return 0;

    if (dp2[a][b] != -1) return dp2[a][b];

    return dp2[a][b] = ((calc2(a - 1, b) % MOD) + (calc2(a, b - 1) % MOD)) % MOD;
}

int main(){
    cin >> T;
    for (int i = 1; i <= T; i++){
        cin >> str;
        int idx = str.find("-");
        int a = atoi(str.substr(0, idx).c_str());
        int b = atoi(str.substr(idx + 1).c_str());

        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);

        printf("Case #%d: %lld %lld\n", i, calc1(a, b), calc2(min(a, b), b));
    }
}
