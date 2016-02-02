#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int dp[1100], coins[1100];
long long c, n;

long long int llmax(long long int a, long long int b){
	if (a > b) return a;
	return b;
}

int main(){
	cin >> c;

	for (int tc = 0; tc < c; tc++){
		cout << "Case " << (tc + 1) << ": ";
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> coins[i];

		dp[0] = coins[0];
		dp[1] = llmax(coins[0], coins[1]);

		for (int i = 2; i < n; i++)
			dp[i] = llmax(dp[i - 1], coins[i] + dp[i - 2]);

		cout << dp[n - 1] << endl;
	}

	return 0;
}
