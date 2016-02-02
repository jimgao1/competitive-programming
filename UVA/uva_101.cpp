
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> block_world;
vector<int> location;

void print_world(){
	for (int i = 0; i < location.size(); i++){
		cout << i << ":";
		for (int j = 0; j < block_world[i].size(); j++)
			cout << " " << block_world[i][j];

		cout << endl;
	}
}

void print_location(){
	for (int i = 0; i < location.size(); i++)
		cout << "location of " << i << " is " << location[i] << endl;
	cout << endl;
}

void update_location(){
	for (int i = 0; i < block_world.size(); i++)
		for (int j = 0; j < block_world[i].size(); j++)
			location[block_world[i][j]] = i;

}

int find_index(int blockID){
	for (int i = 0; i < block_world[location[blockID]].size(); i++)
		if (block_world[location[blockID]][i] == blockID) return i;

	return -1;
}

void move_onto(int a, int b){
	int indexA = find_index(a);
	int indexB = find_index(b);

	//cout << "indexA = " << indexA << ", indexB = " << indexB << endl;

	if (indexA == -1 || indexB == -1) return;
	if (a == b) return;
	if (location[a] == location[b]) return;
	
	for (int i = block_world[location[a]].size() - 1; i > indexA; i--){
		int currentElement = block_world[location[a]][i];
		//cout << "re-indexing block " << currentElement << endl;

		location[currentElement] = currentElement;
		block_world[currentElement].push_back(currentElement);
		block_world[location[a]].erase(block_world[location[a]].begin() + i);
	}

	for (int i = block_world[location[b]].size() - 1; i > indexB; i--){
		int currentElement = block_world[location[b]][i];
		//cout << "re-indexing block " << currentElement << endl;

		location[currentElement] = currentElement;
		block_world[currentElement].push_back(currentElement);
		block_world[location[b]].erase(block_world[location[b]].begin() + i);
	}

	int oldLocation = location[a];

	block_world[location[b]].push_back(block_world[location[a]][indexA]);
	location[block_world[location[a]][indexA]] = location[b];
	block_world[oldLocation].erase(block_world[oldLocation].begin() + indexA);

}

void move_over(int a, int b){
	int indexA = find_index(a);
	int indexB = find_index(b);

	if (indexA == -1 || indexB == -1) return;
	if (a == b) return;
	if (location[a] == location[b]) return;

	for (int i = block_world[location[a]].size() - 1; i > indexA; i--){
		int currentElement = block_world[location[a]][i];

		block_world[currentElement].push_back(currentElement);
		block_world[location[a]].erase(block_world[location[a]].begin() + i);
	}

	int oldLocation = location[a];

	block_world[location[b]].push_back(block_world[location[a]][indexA]);
	location[block_world[location[a]][indexA]] = location[b];
	block_world[oldLocation].erase(block_world[oldLocation].begin() + indexA);
}

void pile_onto(int a, int b){
	int indexA = find_index(a);
	int indexB = find_index(b);

	//cout << "indexA = " << indexA << ", indexB = " << indexB << endl;

	if (block_world[location[a]].empty()) return;
	if (indexA == -1 || indexB == -1) return;
	if (a == b) return;
	if (location[a] == location[b]) return;

	for (int i = block_world[location[b]].size() - 1; i > indexB; i--){
		int currentElement = block_world[location[b]][i];
		//cout << "delete_ current = " << currentElement << endl;

		int oldLocation = location[b];

		block_world[currentElement].push_back(currentElement);
		location[currentElement] = currentElement;
		block_world[oldLocation].erase(block_world[oldLocation].begin() + i);
	}

	vector<int> move_pending;

	for (int i = block_world[location[a]].size() - 1; i >= indexA; i--){
		int currentElement = block_world[location[a]][i];
		//cout << "currentElement = " << currentElement << endl;

		int oldLocation = location[a];

		location[currentElement] = location[b];
		move_pending.push_back(currentElement);

		block_world[oldLocation].erase(block_world[oldLocation].begin() + i);
	}

	reverse(move_pending.begin(), move_pending.end());

	for (int i = 0; i < move_pending.size(); i++)
		block_world[location[b]].push_back(move_pending[i]);
}

void pile_over(int a, int b){
	int indexA = find_index(a);
	int indexB = find_index(b);

	//cout << "indexA = " << indexA << ", indexB = " << indexB << endl;
	//cout << "locationA = " << location[a] << ", locationB = " << location[b] << endl;

	if (indexA == -1 || indexB == -1) return;
	if (a == b) return;
	if (location[a] == location[b]) return;

	vector<int> move_pending;

	for (int i = block_world[location[a]].size() - 1; i >= indexA; i--){
		int currentElement = block_world[location[a]][i];
		//cout << "current = " << currentElement << endl;

		int oldLocation = location[a];

		location[currentElement] = location[b];
		move_pending.push_back(currentElement);

		block_world[oldLocation].erase(block_world[oldLocation].begin() + i);
	}

	
	reverse(move_pending.begin(), move_pending.end());

	for (int i = 0; i < move_pending.size(); i++)
		block_world[location[b]].push_back(move_pending[i]);
}

int main(){
	int blockCount;
	cin >> blockCount;

	for (int i = 0; i < blockCount; i++){
		location.push_back(i);
		
		vector<int> pile;
		pile.push_back(i);
		block_world.push_back(pile);
	}

	while (true){
		
		update_location();

		string command;
		cin >> command;

		if (command == "move"){
			int indexA, indexB;
			cin >> indexA;

			string secondary;
			cin >> secondary;

			cin >> indexB;

			if (secondary == "over"){
				move_over(indexA, indexB);
			}
			else if (secondary == "onto"){
				move_onto(indexA, indexB);
			}
		}
		else if (command == "pile"){
			int indexA, indexB;
			cin >> indexA;

			string secondary;
			cin >> secondary;

			cin >> indexB;

			if (secondary == "over"){
				pile_over(indexA, indexB);
			}
			else if (secondary == "onto"){
				pile_onto(indexA, indexB);
			}
		}
		else if (command == "quit"){
			break;
		}

		//print_world();
		//print_location();
	}

	print_world();
	
	return 0;
} 
