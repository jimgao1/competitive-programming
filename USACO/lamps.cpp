/*
ID: jim_yub1
LANG: C++11
TASK: lamps
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define USACO
#define FILEIN "lamps.in"
#define FILEOUT "lamps.out"

using namespace std;

struct state{
	bool lampState[100];
	int moveCount;
};

int lampCount;
vector<string> generated;

void printState(state current){
	for (int i = 0; i < lampCount; i++)
		if (current.lampState[i])
			cout << "1";
		else
			cout << "0";
	cout << endl;
}

string state_toString(state s){
	string result = "";
	for (int i = 0; i < lampCount; i++)
		result += (s.lampState[i] ? "1" : "0");

	return result;
}

state generateState(state initial, bool p1, bool p2, bool p3, bool p4){
	state result = initial;

	if (p1)
		for (int i = 0; i < lampCount; i++)
			result.lampState[i] = !result.lampState[i];

	if (p2)
		for (int i = 0; i < lampCount; i++)
			if (i % 2 == 0)
				result.lampState[i] = !result.lampState[i];

	if (p3)
		for (int i = 0; i < lampCount; i++)
			if (i % 2 == 1)
				result.lampState[i] = !result.lampState[i];

	if (p4)
		for (int i = 0; i < lampCount; i++)
			if (i % 3 == 0)
				result.lampState[i] = !result.lampState[i];

	int moveCount = 0;

	if (p1) moveCount += 1;
	if (p2) moveCount += 1;
	if (p3) moveCount += 1;
	if (p4) moveCount += 1;

	result.moveCount = moveCount;

	return result;
}


state initial;

int main(){

#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
#endif

	for (int i = 0; i < 100; i++) initial.lampState[i] = true;

	cin >> lampCount;
	int c;
	cin >> c;

	vector<state> possibleStates;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					possibleStates.push_back(generateState(initial, i == 0, j == 0, k == 0, l == 0));

	int targetState[100];
	for (int i = 0; i < 100; i++) targetState[i] = 0;

	while (true){
		int n;
		cin >> n;

		if (n == -1) break;
		targetState[n - 1] = 1;
	}

	while (true){
		int n;
		cin >> n;

		if (n == -1) break;
		targetState[n - 1] = -1;
	}

	int satCount = 0;

	for (int i = 0; i < possibleStates.size(); i++){
		bool match = true;
		//printState(possibleStates[i]);

		for (int j = 0; j < lampCount; j++){
			if (possibleStates[i].lampState[j] && targetState[j] == -1){
				match = false;
				break;
			}
			else if (possibleStates[i].lampState[j] == false && targetState[j] == 1){
				match = false;
				break;
			}
		}

		if (possibleStates[i].moveCount > c) match = false;
		if ((c - possibleStates[i].moveCount % 2 == 1)) match = false;

		if (match){
			generated.push_back(state_toString(possibleStates[i]));
			satCount += 1;
		}
	}

	if (generated.size() != 0){
		sort(generated.begin(), generated.end());
		generated.erase(unique(generated.begin(), generated.end()), generated.end());

		for (int i = 0; i < generated.size(); i++)
			cout << generated[i].c_str() << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
