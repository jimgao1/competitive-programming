
#include <bits/stdc++.h>

#define MAXN 10
#define ll long long
#define MOD 1299827LL
#define OFFSET (1LL << 31)

using namespace std;

int N, M, mid, K[MAXN], P[MAXN];
ll ans = 0;
unordered_map<ll, int> mp;

void calc(int cur, ll sum) {
    if (cur == mid) {
        mp[sum]++;
        return;
    }
    for (int i = 1; i <= M; i++) {
        calc(cur + 1, sum + K[cur] * pow(i, P[cur]));
    }
}

void calc2(int cur, ll sum) {
    if (mid + cur == N) {
        if (mp.count(-sum)) ans += mp[-sum];
        return;
    }
    for (int i = 1; i <= M; i++) {
        calc2(cur + 1, sum + K[cur + mid] * pow(i, P[cur + mid]));
    }
}

int main() {
    mp.reserve(1000000);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> K[i] >> P[i];

    mid = N / 2;
    calc(0, 0);
    calc2(0, 0);

    cout << ans << endl;
}
