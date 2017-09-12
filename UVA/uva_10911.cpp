
#include <bits/stdc++.h>

#define MAXN 17

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }

int N;
double X[MAXN], Y[MAXN];
unordered_map<int, double> mp;

double dist(int a, int b){
	return sqrt(pow(X[a] - X[b], 2) + pow(Y[a] - Y[b], 2));
}

double calc(int st){
	bool done = true;
	for (int i = 0; i < 2 * N; i++){
		if (!getBit(st, i)){
			done = false;
			break;
		}
	}
	if (done) return 0;

	if (mp.count(st)) return mp[st];

	double ans = 1e9;
	for (int i = 0; i < 2 * N; i++){
		if (getBit(st, i)) continue;
		for (int j = i + 1; j < 2 * N; j++){
			if (getBit(st, j)) continue;
			ans = min(ans, dist(i, j) + calc(setBit(setBit(st, i), j)));
		}
	}

	return mp[st] = ans;
}

double solve(){	
	mp.clear();

	string tmp;
	for (int i = 0; i < 2 * N; i++) cin >> tmp >> X[i] >> Y[i];
	return calc(0);
}

int main(){
	for (int i = 1; ; i++){
		cin >> N;
		if (N == 0) break;
		printf("Case %d: %.2f\n", i, solve());
	}
}
