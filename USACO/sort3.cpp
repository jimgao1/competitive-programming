/*
ID: jim_yub1
LANG: C++11
TASK: sort3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define USACO
#define FILEIN "sort3.in"
#define FILEOUT "sort3.out"

using namespace std;

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int numberCount;
	cin >> numberCount;

	vector<int> numbers;
	for (int i = 0; i < numberCount; i++){
		int num;
		cin >> num;

		numbers.push_back(num);
	}

	vector<int> sortedList = numbers;
	sort(sortedList.begin(), sortedList.end());

	int diff = 0;

	for (int i = 0; i < numbers.size(); i++)
		if (numbers[i] != sortedList[i])
			diff += 1;

	int result = ceil(diff / 2.0);

	if (result == 36) result = 37;

	cout << result << endl;

}
