
#include <bits/stdc++.h>

#define MAXN 300001
#define ll long long
#define pii pair<int, int>

using namespace std;

struct plane{
	ll t, c;
	plane(int _, int __){
		t = _, c = __;
	}
	bool operator < (const plane& a) const {
		if (c == a.c) return t < a.t;
		return c < a.c;
	}
};

int N, K, C[MAXN], order[MAXN];
priority_queue<plane> pq;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < K; i++) pq.push(plane(i, C[i]));

	ll ans = 0;
	for (int i = K; i < K + N; i++){
		if (i < N) pq.push(plane(i, C[i]));
		plane cur = pq.top(); pq.pop();
		ans += (i - cur.t) * cur.c;
		order[cur.t] = i;
	}

    printf("%lld\n", ans);
	for (int i = 0; i < N; i++){
		if (i > 0) printf(" ");
		printf("%d", order[i] + 1);
	}
	printf("\n");
}
