/*
ID: jim_yub1
LANG: C++11
TASK: numtri
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define USACO
#define FILEIN "numtri.in"
#define FILEOUT "numtri.out"

using namespace std;

unsigned int triangle[1001][1001];
unsigned int dp[1001][1001];

int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int rowCount;
	cin >> rowCount;

	for (int i = 0; i < rowCount + 1; i++)
		for (int j = 0; j < i; j++)
			cin >> triangle[j][i];

	for (int i = rowCount; i >= 0; i--){
		for (int j = 0; j < i; j++){
			if (i == rowCount)
				dp[j][i] = triangle[j][i];
			else
				dp[j][i] = max(dp[j][i + 1], dp[j + 1][i + 1]) + triangle[j][i];

		}
	}

	cout << dp[0][1] << endl;


	return 0;

}
