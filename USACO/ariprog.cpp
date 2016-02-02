/*
ID: jim_yub1
LANG: C++11
TASK: ariprog
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

#define USACO
#define FILEIN "ariprog.in"
#define FILEOUT "ariprog.out"

using namespace std;

bool bisquare[350 * 350] = {false};

int sequenceLength, searchLimit;

void generateNumbers(){
	for (int i = 0; i < searchLimit + 1; i++)
		for (int j = 0; j < searchLimit + 1; j++)
			bisquare[i * i + j * j] = true;
}


bool validSequence(int start, int diff, int len){
	//cout << "start = " << start << ", diff = " << diff << ", len = " << len << endl;

	if (len == 0) return true;

	if (start <= 300 * 300 && bisquare[start])
		return validSequence(start + diff, diff, len - 1);

	return false;
}

int main(){


	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	cin >> sequenceLength >> searchLimit;

	generateNumbers();

    bool found = false;

	for (int i = 1; i < 5000; i++){
		for (int j = 0; j < 100000; j++)
			if (validSequence(j, i, sequenceLength)){
				cout << j << " " << i << endl;
				found = true;

			}
	}

    if (!found)
        cout << "NONE" << endl;

	return 0;

}

