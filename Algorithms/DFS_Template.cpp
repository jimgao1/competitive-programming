/*
		[DFS_Template.cpp]

		Sample DFS Problem:
			Find a n-digit number with the digit sum k that is a prime
*/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int n = 4;
int k = 10;

bool prime(int n){
	for (int i = 2; i < n; i++)
		if (n % i == 0) return false;
	return true;
}

void findNumber(string current){
	if (current.length() == n){
		int digitSum = 0;
		for (int i = 0; i < current.length(); i++){
			digitSum += (int)(current[i] - '0');
		}

		if (digitSum == k && prime(atoi(current.c_str()))){
			cout << "Result Found: " << current << endl;
		} else {
			return;
		}
	}
	else {
		if (current.length() == 0){
			for (int i = 1; i <= 10; i++)
				findNumber(current + (char)(i + '0'));
		}
		else {
			for (int i = 0; i <= 10; i++)
				findNumber(current + (char)(i + '0'));
		}

	}

}

int _tmain(int argc, _TCHAR* argv[])
{

	findNumber("");

	system("pause");

	return 0;
}

