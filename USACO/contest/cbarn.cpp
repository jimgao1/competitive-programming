
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, ans = 0x3f3f3f3f, num[MAXN];

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];

    for (int i = 0; i < N; i++){
        int cur = 0;
        for (int j = 0; j < N; j++){
            cur += num[j] * ((j - i + N) % N);
        }

        ans = min(ans, cur);
    }

    cout << ans << endl;
}

