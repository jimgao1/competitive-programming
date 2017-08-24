
#include <bits/stdc++.h>

using namespace std;

string str; int K;
set<char> s;

int main(){
	cin >> str >> K;
	for (char c : str)
		s.insert(c);

	if (str.size() < K){
		cout << "impossible" << endl;
		return 0;
	}

	if (s.size() >= K){
		cout << 0 << endl;
	} else {
		cout << K - s.size() << endl;
	}
}
