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

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	/*
		Dictionary Input File
		*/

	ifstream dictionary("dict.txt");
	vector<string> names;

	string n;
	while (dictionary >> n)
		names.push_back(n);

	/*
		Inquiry Process
		*/

	string callNumber;
	cin >> callNumber;

	generate(callNumber, "");

	for (int i = 0; i < possibleNumbers.size(); i++){
		//cout << possibleNumbers[i] << endl;
		for (int j = 0; j < names.size(); j++)
			if (possibleNumbers[i] == names[j])
		cout << names[j] << endl;
	}

    return 0;
};
