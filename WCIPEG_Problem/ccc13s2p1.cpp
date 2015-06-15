/*
	This code does NOT work for all the cases. Will update later.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int x;

bool palindrom(vector<int> num){
	for (int i = 0; i < ceil(num.size() / 2.0); i++){
		if (num[i] != num[num.size() - i - 1])
			return false;
	}
	return true;
}

vector<int> base_convert(vector<int> orig, int src, int tar){
	long sum = 0;
	for (int i = 0; i < orig.size(); i++)
		sum += orig[i] * pow(src, i);

	vector<int> result;

	while (sum > 0){
		int res = sum % tar;
		sum = sum / tar;
		result.push_back(res);
	}

	reverse(result.begin(), result.end());

	return result;
}

vector<int> defaultToBase(long n){
	vector<int> number;

	while (n > 0){
		number.push_back(n % 10);
		n = n / 10;
	}

	//reverse(number.begin(), number.end());

	return number;
}

void print_number(vector<int> number){
	for (int n : number)
		cout << n << " ";
	cout << endl;
}

int main(){
	
	long num;
	cin >> num;

	for (int i = 2; i < num+1; i++){
		if (i > ceil(sqrt(num))){
			double v = num / (double)(i);
			if (v == (int)(v)){
				printf("%d\n", i);
			}
		}
		else {
			if (palindrom(base_convert(defaultToBase(num), 10, i))){
				printf("%d\n", i);
			}
		}
	}


	return 0;
}
