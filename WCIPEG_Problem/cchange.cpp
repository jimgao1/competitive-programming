#include <bits/stdc++.h>

using namespace std;

int x, n;
int c[10001], dp[10001];

int main(){
	for (int i=0; i<10001; i++) dp[i] = 10000001;
	
	cin >> x >> n;
	
	for (int i=0; i<n; i++){
		cin >> c[i];
		dp[c[i]] = 1;
	}
	
	for (int i=1; i<=x; i++){
		for (int j=0; j<n; j++)
			if (i - c[j] >= 0)
			    dp[i] = min(dp[i], dp[i - c[j]] + 1);
	}
	
	cout << dp[x] << endl;
	
	return 0;
}
