
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <string>
#include <functional>

using namespace std;

priority_queue < pair<int, vector<char> >, vector<pair<int, vector<char> > >, greater<pair<int, vector<char> > > > huffman;
int cdepth[27], ccount[27];

int main(){
	while (true){
		for (int i = 0; i < 27; i++){
			cdepth[i] = 0, ccount[i] = 0;
		}
		while (!huffman.empty()) huffman.pop();

		string orig;
		cin >> orig;

		if (orig == "END") break;

		for (int i = 0; i < orig.length(); i++){
			if (orig[i] == '_')
				ccount[26] ++;
			else
				ccount[orig[i] - 'A'] ++;
		}

		for (int i = 0; i < 27; i++){
			if (ccount[i] != 0){
				if (i == 26){
					vector<char> temp;
					temp.push_back('_');

					huffman.push({ ccount[i], temp });
				}
				else {
					vector<char> temp;
					temp.push_back((char)('A' + i));

					huffman.push({ ccount[i], temp });
				}
			}
		}

		while (huffman.size() > 1){
			pair<int, vector<char> > nodeA = huffman.top();
			huffman.pop();

			pair<int, vector<char> > nodeB = huffman.top();
			huffman.pop();

			vector<char> u;

			for (int i = 0; i < nodeA.second.size(); i++)
				u.push_back(nodeA.second[i]);

			for (int i = 0; i < nodeB.second.size(); i++)
				u.push_back(nodeB.second[i]);

			for (int i = 0; i < u.size(); i++){
				if (u[i] == '_'){
					cdepth[26] ++;
				}
				else {
					cdepth[u[i] - 'A'] ++;
				}
			}

			huffman.push({ nodeA.first + nodeB.first, u });

		}

		int sum = 0;

		for (int i = 0; i < 27; i++){
			sum += ccount[i] * cdepth[i];
		}

        sum = max(sum, (int)(orig.length()));

		double r = (orig.length() * 8.0) / sum;
		cout << orig.length() * 8 << " " << sum << " ";
		cout << fixed << setprecision(1) << r << endl;
	}

	return 0;
}
