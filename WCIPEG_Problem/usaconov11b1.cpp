// Mar10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int d, h, m;
	cin >> d >> h >> m;

	unsigned long long int endMinutes = d * 24 * 60 + h * 60 + m;
	unsigned long long int startMiniutes = 11 * 24 * 60 + 11 * 60 + 11;

	if (endMinutes < startMiniutes)
		cout << "-1" << endl;
	else
		cout << endMinutes - startMiniutes << endl;

	return 0;
}

