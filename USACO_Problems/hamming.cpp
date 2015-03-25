/*
ID: jim_yub1
LANG: C++11
TASK: hamming
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define USACO
#define FILEIN "hamming.in"
#define FILEOUT "hamming.out"

using namespace std;

int reqLength, bits, minDistance;

char toLetter(int n){
	if (n < 10)
		return (char)(n + '0');

	return (char)(n - 10 + 'A');
}

string toBinary(unsigned int x)
{
	std::string s;
	do
	{
		s.push_back('0' + (x & 1));
	} while (x >>= 1);
	reverse(s.begin(), s.end());
	return s;

}

string generateZero(int n){
	string r = "";
	for (int i = 0; i < n; i++) r = r + "0";
	return r;
}

int diff(int num1, int num2){
	string s1 = toBinary(num1);
	string s2 = toBinary(num2);

	int maxLength = max(s1.length(), s2.length());

	if (s1.length() < s2.length()){
		s1 = generateZero(s2.length() - s1.length()) + s1;
	}
	else {
		s2 = generateZero(s1.length() - s2.length()) + s2;
	}

	int diff = 0;

	for (int i = 0; i < s1.length(); i++) if (s1[i] != s2[i]) diff += 1;

	return diff;
}

void generateSequence(vector<int> seq){

	if (seq.size() == reqLength){
		int counter = 0;

		for (int i = 0; i < seq.size(); i++){

			int n = seq[i];

			cout << n;
			counter++;

			if (counter == 10 && i != seq.size() - 1){
				cout << endl;
				counter = 0;
			}
			else {
				if (i != seq.size() - 1)
					cout << " ";
			}
		}
		cout << endl;

		exit(0);
	}

	sort(seq.begin(), seq.end());

	for (int i = seq[seq.size() - 1] + 1; i < pow(2, bits); i++){
		bool valid = true;

		for (int n : seq)
			if (diff(n, i) < minDistance){
				valid = false;
				break;
			}

		if (valid){
			vector<int> newSeq = seq;
			newSeq.push_back(i);

			generateSequence(newSeq);

			return;
		}
	}
}

int main()
{

    #ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	cin >> reqLength >> bits >> minDistance;

	for (int i = 0; i < pow(2, bits) + 1; i++){
		vector<int> newSeq;
		newSeq.push_back(i);


		generateSequence(newSeq);
	}


	return 0;
}

