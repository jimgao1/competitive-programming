/*
ID: jim_yub1
LANG: C++11
TASK: zerosum
*/

/*
	USACO Problem - Zero Sum
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

vector<string> expressions;
int expLength;


long evaluate(string s){
	long currentNumber = 0;
	long currentSum = 0;
	char currentSign = '+';

	for (int i = 0; i < s.length(); i++){
		if (s[i] == '+' || s[i] == '-'){
			if (currentSign == '+'){
				currentSum += currentNumber;
				currentNumber = 0;
			}
			else{
				currentSum -= currentNumber;
				currentNumber = 0;
			}

			currentSign = s[i];
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			currentNumber = currentNumber * 10 + (int)(s[i] - '0');
		}
	}

	if (currentSign == '+')
		currentSum += currentNumber;
	else
		currentSum -= currentNumber;

	return currentSum;
}

void generate(string s){
	int firstIndex = -1;

	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'x'){
			firstIndex = i;
			break;
		}

	if (firstIndex == -1){
		if (evaluate(s) == 0)
			expressions.push_back(s);
		return;
	}

	string pA = s;
	string pB = s;
	string pC = s;

	pA[firstIndex] = '+';
	generate(pA);

	pB[firstIndex] = '-';
	generate(pB);

	pC[firstIndex] = ' ';
	generate(pC);
}

int main(){
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

	cin >> expLength;

	string base = "";
	for (int i = 0; i < expLength - 1; i++)
		base += to_string(i + 1) + "x";
	base += to_string(expLength);

	//cout << "base = " << base << endl;

	generate(base);
	sort(expressions.begin(), expressions.end());

	for (string curr : expressions)
		cout << curr << endl;

	//system("pause");
	return 0;
}
