

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define MAXN 300000

using namespace std;

int value[MAXN];

int main(){
	
	int hotelCount, totalMoney;
	cin >> hotelCount >> totalMoney;

	for (int i = 0; i < hotelCount; i++)
		cin >> value[i];

	int startIndex = 0;
	int endIndex = 0;
	int totalSum = value[0];

	int maxSum = 0;

	while (true){
		//cout << startIndex << "\t" << endIndex << "\t" << totalSum << endl;

		if (startIndex >= hotelCount || endIndex >= hotelCount) break;
		if (startIndex < 0 || endIndex < 0) break;

		if (totalSum + value[endIndex + 1] <= totalMoney){
			endIndex += 1;
			totalSum += value[endIndex];
		}
		else {
			startIndex += 1;
			totalSum -= value[startIndex - 1];
		}

		maxSum = max(maxSum, totalSum);
	}

ret:
	cout << maxSum << endl;

	system("pause");
	return 0;
}

