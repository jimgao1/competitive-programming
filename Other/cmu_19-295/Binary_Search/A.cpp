#include <bits/stdc++.h> 

#define ld long double

#define MAXN 1001
#define EPS (ld)(1e-7)

using namespace std;

int N, S, p[MAXN];
ld x[MAXN], y[MAXN];

bool test(ld rr) {
	int total = S;
	for (int i = 0; i < N; i++) {
		if (sqrt(pow(x[i], 2) + pow(y[i], 2)) <= rr)
			total += p[i];
	}
	return total >= 1e6;
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; cin >> x[i] >> y[i] >> p[i++]);

	ld low = 0, high = 1e9;
	bool done = 0;

	while((high - low) >= EPS) {
		ld mid = (low + high) / 2.0;
		if (test(mid)) {
			high = mid;
			done = 1;
		} else {
			low = mid;
		}
	}

	if (done)
		cout << fixed << setprecision(7) << low << endl;
	else
		cout << "-1" << endl;
}
