/*
    USER: jim.yub1
    TASK: runround
    LANG: C++11
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>

#define USACO

using namespace std;

int correct_index(int size, int index){
	if (index >= size) return correct_index(size, index - size);
	if (index < 0) return correct_index(size, index + size);
	return index;
}

bool distinct_digits(string n){
	bool c[10];
	for (int i = 0; i < 10; i++) c[i] = false;

	for (int i = 0; i < n.length(); i++){
		int curr = n[i] - '0';

		if (c[curr]) return false;
		c[curr] = true;
	}

	return true;
}

bool runaround_number(int n){
	string number = to_string(n);

	if (!distinct_digits(number)) return false;

	bool digit_visited[100];
	for (int i = 0; i < 100; i++) digit_visited[i] = false;

	int currentDigit = number[0] - '0';
	int initialDigit = currentDigit;
	int currentIndex = 0;

	int steps = 0;

	while (true){
		if (steps != 0 && currentDigit == initialDigit){
			for (int i = 0; i<number.length(); i++)
				if (!digit_visited[i]) return false;

			return true;
		}

		if (steps > (int)(number.length() + 2)) return false;

		digit_visited[currentIndex] = true;

		currentIndex += currentDigit;
		currentIndex = correct_index(number.length(), currentIndex);

		currentDigit = number[currentIndex] - '0';
		steps += 1;
	}
}

int main(){
#ifdef USACO
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
#endif

	int n;
	cin >> n;

	n += 1;

	while (true){
		if (runaround_number(n)){
			cout << n << endl;
			return 0;
		}

		n += 1;
	}
	
	return 0;
}
