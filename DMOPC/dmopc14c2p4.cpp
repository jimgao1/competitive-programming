
#include <bits/stdc++.h>

#define MAXN 1000001

using namespace std;

int N, Q, sum[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> sum[i];
    for (int i = 2; i <= N; i++) sum[i] += sum[i - 1];
    cin >> Q;
    for (int i = 0, a, b; i < Q; i++){
        cin >> a >> b;
        cout << sum[b + 1] - sum[a] << "\n";
    }
}
