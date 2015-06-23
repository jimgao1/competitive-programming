#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, A, S, B, itemCount[1002], dp[1001][1001 * 100];

int main(){
	cin >> T >> A >> S >> B;

	for (int i = 0, c; i < A; i++){
		cin >> c;
		itemCount[c] ++;
	}

	dp[0][0] = 1;

	int maxAnts = 0;
	for (int i = 1; i <= T; i++){
		maxAnts += itemCount[i];
		for (int j = 0; j <= itemCount[i]; j++){
			for (int k = maxAnts; k >= j; k--){
				dp[i][k] += dp[i - 1][k - j];
				dp[i][k] %= 1000000;
			}

		}
	}

	int sum = 0;
	for (int i = S; i <= B; i++){
		sum = (sum + dp[T][i]) % 1000000;
	}

	cout << sum << endl;

	return 0;
}
