#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

string str;
int Q, sum[100001];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (int i = 0; i < str.size(); i++){
		if (str[i] == 'G') sum[i] ++;
		sum[i] += sum[i - 1];
	}

	cin >> Q;
	for (int i = 0, a, b; i < Q; i++){
		cin >> a >> b;
		
		if (a == 0)
			cout << sum[b] << endl;
		else
			cout << sum[b] - sum[a - 1] << endl;
	}	
}
