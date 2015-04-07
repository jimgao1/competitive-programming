
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int caseCount;
	cin >> caseCount;

	while(caseCount-- != 0){
		vector<int> numbers;

		int numCount;
		cin >> numCount;

		for (int i=0; i<numCount; i++){
			int n;
			cin >> n;

			numbers.push_back(n);
		}

		int swapCount = 0;

		for (int i=0; i<numCount; i++)
			for (int j=0; j<i; j++)
				if (numbers[i] < numbers[j]){
					swapCount += 1;

					int temp = numbers[i];
					numbers[i] = numbers[j];
					numbers[j] = temp;
				}

		cout << "Optimal train swapping takes " << swapCount << " swap(s)." << endl;
	}
}
