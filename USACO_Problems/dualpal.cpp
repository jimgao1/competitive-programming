/*
ID: jim_yub1
LANG: C++11
TASK: dualpal
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define USACO
#define FILEIN "dualpal.in"
#define FILEOUT "dualpal.out"

char toLetter(int n){
	if (n < 10)
		return (char)(n + '0');

	return (char)(n - 10 + 'A');
}

string toBaseT(int num, int t){
	if (num == 1) return "1";

	int digits = ceil(log(num) / log(t));
	string result = "";

	for (int i = digits - 1; i >= 0; i--){
		int d = num / pow(t, i);
		num = num - d * pow(t, i);

		result += toLetter(d);
	}

	return result;
}

bool palindrom(string s){
	string r = s;
	reverse(r.begin(), r.end());

	return (r == s);
}

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int printCount, greater;
	cin >> printCount >> greater;

	int curCount = greater + 1;

	while (printCount > 0){
		int palCount = 0;
		for (int i = 2; i <= 10; i++)
			if (palindrom(toBaseT(curCount, i))) {
				palCount += 1;
			}

		if (palCount >= 2){
			cout << curCount << endl;
			printCount -= 1;
		}

		curCount += 1;

	}
};
