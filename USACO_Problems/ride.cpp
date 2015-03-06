/*
ID: jim_yub1
LANG: C++11
TASK: ride
*/

#include <iostream>
#include <string>

using namespace std;

#define USACO
#define FILEIN "ride.in"
#define FILEOUT "ride.out"

int strHash(string s){
	unsigned long long hash = 1;

	for (int i = 0; i < s.length(); i++)
		hash = hash * (int)(s[i] - 'A' + 1);

	return hash % 47;
}

int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	string s1, s2;
	cin >> s1 >> s2;

	if (strHash(s1) == strHash(s2))
		cout << "GO" << endl;
	else
		cout << "STAY" << endl;

	return 0;

}
