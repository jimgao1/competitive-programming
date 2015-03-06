/*
ID: jim_yub1
LANG: C++11
TASK: test
*/

#include <iostream>

using namespace std;

#define USACO
#define FILEIN "test.in"
#define FILEOUT "test.out"

int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int a, b;
	cin >> a >> b;

	cout << a + b << endl;

	return 0;

}
