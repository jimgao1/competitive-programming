
#include <bits/stdc++.h>

#define MAXN 500001
#define ull unsigned long long

using namespace std;

int N, budget[MAXN];
ull ans = 0;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> budget[i];
    }

    sort(budget, budget + N);

    for (int i = 0; i < N; i++){
        ans = max(ans, (ull) budget[i] * (N - i));
    }

    cout << ans << endl;
}

