
#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

using namespace std;

int L, N, a, b, pos[MAXN], val[MAXN];
bool valid[MAXN];

int main() {
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);

	cin >> L >> N >> a >> b;
	for (int i = 0; i < N; i++) cin >> pos[i] >> val[i];

	int tmp = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (val[i] > tmp) {
			valid[i] = true;
			tmp = val[i];
		}
	}

	ll ans = 0, pa = 0, pb = 0, pre = 0;
	for (int i = 0; i < N; i++) {
		if (valid[i]) {
			pa += a * (pos[i] - pre);
			pb += b * (pos[i] - pre);

			ans += val[i] * (pa - pb);
			pa = pb = max(pa, pb);

			pre = pos[i];
		}
	}

	cout << ans << endl;
}
