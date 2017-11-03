
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> c;

int main(){
	cin >> N >> K;
	double t = 0;
	for (int i = 0; i < N; i++){
		int x;
		cin >> x;
		c.push_back(x);
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < K; i++) t += c[k];
	cout << ceil(t / 100) << endl;
}
