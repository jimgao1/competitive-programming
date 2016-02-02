#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int numbers[110000] = { 0 };
int stations, min_t, oper;

int main(){
	cin >> stations >> min_t >> oper;

	for (int i = 0; i < oper; i++){
		int s, e, n;
		cin >> s >> e >> n;

		s--; e--;

		numbers[s] += n;
		numbers[e + 1] -= n;
	}

	int c = 0;

	if (numbers[0] < min_t) c++;

	for (int i = 1; i < stations; i++){
		numbers[i] += numbers[i - 1];
		if (numbers[i] < min_t) c++;
	}

	cout << c << endl;

	//system("pause");
	return 0;
}
