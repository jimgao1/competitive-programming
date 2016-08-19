
#include <bits/stdc++.h>

using namespace std;

int T, C;
vector<int> ch;

int main(){
	cin >> T >> C;
	for (int i = 0, x; i < C; i++){
		cin >> x;
		ch.push_back(x);
	}

	sort(ch.begin(), ch.end());
	int cnt = 0;

	for (int x : ch){
		if (T >= x){
			T -= x;
			cnt++;
		} else {
			break;
		}
	}

	cout << cnt << endl;
}
