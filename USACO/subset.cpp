/*
ID: jim.yub1
PROG: subset
LANG: C++11
*/

#include <iostream>
#include <vector>

#define USACO
#define FILEIN "subset.in"
#define FILEOUT "subset.out"

using namespace std;

int numberCount;
double halfSum;
int possibleCombinations;

unsigned long dp[40][800];

void generate(int currentIndex, int totalSum){
	if (currentIndex == numberCount){
		if (totalSum == halfSum) possibleCombinations += 1;

		return;
	}

	generate(currentIndex + 1, totalSum);
	generate(currentIndex + 1, totalSum + currentIndex + 1);
}

unsigned long newGenerate(int currentIndex, int totalSum){
	if (currentIndex == numberCount){
		if (totalSum == halfSum) return 1;
		return 0;
	}

	if (dp[currentIndex][totalSum] != -1) return dp[currentIndex][totalSum];

	unsigned long result = newGenerate(currentIndex + 1, totalSum) +
		newGenerate(currentIndex + 1, totalSum + currentIndex + 1);
	dp[currentIndex][totalSum] = result;

	return result;
}

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	for (int i = 0; i < 40; i++) for (int j = 0; j < 800; j++) dp[i][j] = -1;

	cin >> numberCount;

	halfSum = (1 + numberCount) * numberCount / 4;

	if (((1 + numberCount) * numberCount / 2) % 2 == 1){
		cout << "0" << endl;
		return 0;
	}

	cout << newGenerate(0, 0) / 2L << endl;

	return 0;
}
