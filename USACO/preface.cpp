/*
ID: jim.yub1
PROG: preface
LANG: C++11
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

#define USACO
#define FILEIN "preface.in"
#define FILEOUT "preface.out"

using namespace std;

string dec_to_numeral(int x) {
	int dec[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string num[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	string numeral;

	for (int i = 0; i < 13; i++) {
		while (x >= dec[i]) {
			x -= dec[i];
			numeral.append(num[i]);
		}
	}

	return numeral;
}

int main(){

#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
#endif

	int n;
	cin >> n;

	map<char, int> freq;

	freq['I'] = 0;
	freq['V'] = 0;
	freq['X'] = 0;
	freq['L'] = 0;
	freq['C'] = 0;
	freq['D'] = 0;
	freq['M'] = 0;

	for (int i = 1; i < n + 1; i++){
		string result = dec_to_numeral(i);

		for (int j = 0; j < result.length(); j++){
			freq[result[j]]++;
		}
	}

	if (freq['I'] != 0) cout << "I " << freq['I'] << endl;
	if (freq['V'] != 0) cout << "V " << freq['V'] << endl;
	if (freq['X'] != 0) cout << "X " << freq['X'] << endl;
	if (freq['L'] != 0) cout << "L " << freq['L'] << endl;
	if (freq['C'] != 0) cout << "C " << freq['C'] << endl;
	if (freq['D'] != 0) cout << "D " << freq['D'] << endl;
	if (freq['M'] != 0) cout << "M " << freq['M'] << endl;


	return 0;
}
