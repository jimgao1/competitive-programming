
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, D, R;
vector<int> a, b;

bool solve(){
	a.clear(); b.clear();

	cin >> N >> D >> R;
	if (N == 0 && D == 0 && R == 0) return 0;

	for (int i = 0, x; i < N; i++) {
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0, x; i < N; i++) {
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());

	int ans = 0;
	for (int i = 0; i < N; i++){
		ans += max(0, a[i] + b[i] - D) * R;
	}

	cout << ans << endl;
	return 1;
}

int main(){
	while(solve());
}
