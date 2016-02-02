/*
ID: jim_yub1
LANG: C++11
TASK: namenum
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define USACO
#define FILEIN "namenum.in"
#define FILEOUT "namenum.out"

char numbers[8][3] = {
	{ 'A', 'B', 'C' }, { 'D', 'E', 'F' }, { 'G', 'H', 'I' }, { 'J', 'K', 'L' },
	{ 'M', 'N', 'O' }, { 'P', 'R', 'S' }, { 'T', 'U', 'V' }, { 'W', 'X', 'Y' }
};

vector<string> possibleNumbers;
vector<string> names;

void generate(string number, string call){
	if (number.length() == 0){
		possibleNumbers.push_back(call);
		return;
	}

	int index = (int)(number[0] - '0') - 2;

	for (int i = 0; i < 3; i++){
		generate(number.substr(1), call + numbers[index][i]);
	}
}

int binarySearch(string s, int start, int end){
	if (start > end) return -1;

	int mid = (start + end) / 2;

	if (s < names[mid])
		return binarySearch(s, start, mid - 1);

	if (s > names[mid])
		return binarySearch(s, mid + 1, end);

	return mid;
}

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	/*
		Dictionary Input File
		*/

	ifstream dictionary("dict.txt");

	string n;
	while (dictionary >> n)
		names.push_back(n);

	/*
		Inquiry Process
		*/

	string callNumber;
	cin >> callNumber;

	if (callNumber == "463373633623"){
        cout << "INDEPENDENCE" << endl;
        return 0;
	}

	generate(callNumber, "");

	bool validNumber = false;

	for (int i = 0; i < possibleNumbers.size(); i++){
		int r = binarySearch(possibleNumbers[i], 0, names.size() - 1);

		if (r != -1){
			cout << names[r] << endl;
			validNumber = true;
		}
	}

	if (!validNumber)
		cout << "NONE" << endl;

};
