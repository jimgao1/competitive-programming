/*
ID: jim_yub1
LANG: C++11
TASK: palsquare
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define USACO
#define FILEIN "palsquare.in"
#define FILEOUT "palsquare.out"

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

	int base;
	cin >> base;

	for (int i = 1; i <= 300; i++){
		int sq = i * i;

		if (palindrom(toBaseT(sq, base)))
			cout << toBaseT(i, base) << " " << toBaseT(sq, base) << endl;
	}

};
