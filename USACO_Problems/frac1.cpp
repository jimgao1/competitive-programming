/*
ID: jim_yub1
LANG: C++11
TASK: frac1
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

#define USACO
#define FILEIN "frac1.in"
#define FILEOUT "frac1.out"

using namespace std;

struct fraction{
	int numerator;
	int denominator;
};

vector<fraction> possible;

double evaluate(fraction f){
	return (double)(f.numerator) / f.denominator;
}

int gcd (int u, int v) {
	while (v != 0) {
		int r = u % v;
		u = v;
		v = r;
	}
	return u;
}

bool reduced(fraction f){
	if (gcd(f.numerator, f.denominator) == 1) return true;
	return false;
}

bool fractionComp(fraction a, fraction b){
	return evaluate(a) < evaluate(b);
}

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++){
		for (int j = 0; j < i + 1; j++){
			fraction newFraction;
			newFraction.numerator = j;
			newFraction.denominator = i;

			if (reduced(newFraction))
				possible.push_back(newFraction);
		}
	}

	sort(possible.begin(), possible.end(), fractionComp);

	for (fraction f : possible)
		cout << f.numerator << "/" << f.denominator << endl;

}
