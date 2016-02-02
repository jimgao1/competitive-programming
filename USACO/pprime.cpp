/*
ID: jim_yub1
LANG: C++11
TASK: pprime
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

#define USACO
#define FILEIN "pprime.in"
#define FILEOUT "pprime.out"

vector<int> palindroms;

bool primeNumber(int n){
    if (n == 9) return false;

	for (int i = 2; i < ceil(sqrt(n))* 1.5; i++)
		if (n % i == 0) return false;
	return true;
}

void generatePalindrom(){
	//1
	for (int i = 1; i < 10; i++)
		palindroms.push_back(i);


	//2
	for (int i = 1; i < 10; i += 2)
		palindroms.push_back(i * 11);

	//3
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; j++)
			palindroms.push_back(i * 101 + j * 10);

	//4
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; j++)
			palindroms.push_back(i * 1001 + j * 110);

	//5
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				palindroms.push_back(i * 10001 + j * 1010 + k * 100);

	//6
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 0; j++)
			for (int k = 0; k < 10; k++)
				palindroms.push_back(i * 100001 + j * 10010 + k * 1100);

	//7
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++)
					palindroms.push_back(i * 1000001 + j * 100010 + k * 10100 + l * 1000);


	//8
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++)
					palindroms.push_back(i * 10000001 + j * 1000010 + k * 100100 + l * 11000);


	//9
	for (int i = 1; i < 10; i += 2)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				for (int l = 0; l < 10; l++)
					for (int m = 0; m < 10; m++)
						palindroms.push_back(i * 100000001 + j * 10000010 + k * 1000100 + l * 101000 + m * 10000);

}

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif


	generatePalindrom();

	int a, b;
	cin >> a >> b;



	for (int n : palindroms){
		if (n > b) break;

		if (n >= a)
			if (primeNumber(n))
				cout << n << endl;
	}


}
