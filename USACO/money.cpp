/*
ID: jim_yub1
LANG: C++11
TASK: money
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int coins, total;

int value[30];
unsigned long long dp[11000] = { 0 };

int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

	cin >> coins >> total;
	for (int i = 0; i < coins; i++) cin >> value[i];

	dp[0] = 1;

	for (int i = 0; i < coins; i++){
		for (int j = 0; j < total + 1; j++){
			if (j - value[i] >= 0)
				dp[j] += dp[j - value[i]];
		}
	}

	cout << dp[total] << endl;

	return 0;
}
