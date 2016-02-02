/*
ID: jim_yub1
LANG: C++11
TASK: gift1
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

#define USACO
#define FILEIN "gift1.in"
#define FILEOUT "gift1.out"

#define MAXN 10

string names[MAXN];
int account[MAXN];
int peopleCount;

map<string, int> dictionary;

int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	cin >> peopleCount;

	for (int i = 0; i < peopleCount; i++){
		string name;
		cin >> name;

		names[i] = name;

		dictionary[name] = i;
		account[i] = 0;
	}

	while (true){
		string subject;
		if (!(cin >> subject)) break;

		int tMoney, tPeople;
		cin >> tMoney >> tPeople;

		if (tPeople == 0) continue;

		/*
			Calculate PerPerson, and TotalSpent
		*/
		int tPerson = tMoney / tPeople;
		int total = tPerson * tPeople;

		account[dictionary[subject]] -= total;

		for (int i = 0; i < tPeople; i++){
			string target;
			cin >> target;

			account[dictionary[target]] += tPerson;
		}
	}

	for (int i = 0; i < peopleCount; i++){
		cout << names[i] << " " << account[i] << endl;
	}


	return 0;

}
