/*
ID: jim_yub1
LANG: C++11
TASK: milk3
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define FILEIN "milk3.in"
#define FILEOUT "milk3.out"

using namespace std;

struct state{
	int amount[3];
	bool init;
	int steps;
};

int size[3];
bool visited[21][21][21];



void search(int a, int b, int c){

	if (a == 0){
		possible.push_back(c);
	}

	if (visited[a][b][c]) return;
	visited[a][b][c] = true;

	search(a + min(c, size[0] - a), b, c - min(c, size[0] - a));
	search(a - min(size[2] - c, a), b, c + min(size[2] - c, a));

	search(a+min(b,size[0]-a),b-min(b,size[0]-a),c);
	search(a-min(size[1]-b,a),b+min(size[1]-b,a),c);

	search(a, b + min(c, size[1] - b), c - min(c, size[1] - b));
	search(a, b - min(size[2] - c, b), c + min(size[2] - c, b));
}

int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	cin >> size[0] >> size[1] >> size[2];

	int a = 0, b = 0, c = size[2];

	search(a + min(c, size[0] - a), b, c - min(c, size[0] - a));
	search(a, b + min(c, size[1] - b), c - min(c, size[1] - b));


	sort(possible.begin(), possible.end());
	possible.erase(unique(possible.begin(), possible.end()), possible.end());

	for (int i = 0; i < possible.size(); i++)
		if (i == possible.size() - 1)
			cout << possible[i];
		else
			cout << possible[i] << " ";

	cout << endl;

	system("pause");

	return 0;

}  
