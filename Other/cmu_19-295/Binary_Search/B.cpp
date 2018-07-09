#include <bits/stdc++.h> 

#define ld long double

#define MAXN 1030
#define EPS (ld)(1e-10)

using namespace std;

int N, L;
ld A[MAXN];

bool test(ld D) {
	for (int i = 1; i <= N; i++) 
		if (A[i] - A[i - 1] > D * 2)
			return false;

	return true;	
}

int main() {
	cin >> N >> L;
	for (int i = 1; i <= N; cin >> A[i++]);

	A[0] = 0, A[N + 1] = L;
	sort(A, A + N + 2);

	ld low = max(A[1] - A[0], A[N + 1] - A[N]), high = L;

	while((high - low) >= EPS) {
		ld mid = (low + high) / 2.0;

		if (test(mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}

	cout << fixed << setprecision(10) << low << endl;
}
