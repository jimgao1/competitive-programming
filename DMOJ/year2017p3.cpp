#include <bits/stdc++.h>

#define MAXN 1000010
#define ll long long

using namespace std;

ll K, N, value[MAXN], dp[MAXN];

ll calc(int term){
    if (term < 0) return -1e9;
    return max(value[term], value[term - 1] + max(value[term - 2], calc(term - 2)));
}

int main(){
    cin >> K >> N;
    for (int i = 1; i <= N; i++) cin >> value[i];

    if (N < K - 1){
        cout << -1 << endl;
        return 0;
    }

    if (K == 1 || K == 2){
        cout << max(value[1], value[2]) << endl;
        return 0;
    }

    cout << calc(K) << endl;
}
