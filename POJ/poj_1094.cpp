
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

bool matrix[26][26];
int nodes, edges;

string solution = "";

bool solution_found, invalid_relation;
int first_node_id;

/*
	Topological Sorting Function:

		1 - The graph is invalid (contains circles)
		2 - The graph is valid, but sequence cannot be determined
		3 - The graph is valid, and the sequence can be determined
*/
int topological_sort(){
	bool current[26][26];
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			current[i][j] = matrix[i][j];

	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			for (int k = 0; k < 26; k++)
				if (current[i][j] && current[j][k])
					current[i][k] = true;

	bool multiple_ans = false;

	bool visited[26];
	for (int i = 0; i < 26; i++)
		visited[i] = false;
	
	solution = "";

	while (true){
		bool allVisited = true;
		
		for (int i = 0; i < nodes; i++)
			if (!visited[i]) allVisited = false;

		if (allVisited){
			return (multiple_ans ? 2 : 3);
		}

		vector<int> available_nodes;
		
		for (int i = 0; i < nodes; i++){
			int indeg = 0;
			for (int j = 0; j < nodes; j++)
				if (current[j][i] && !visited[i] && !visited[j]) indeg++;

			if (indeg == 0 && !visited[i]){
				available_nodes.push_back(i);
			}
		}

		//The graph contains cycles
		if (available_nodes.size() == 0)
			return 1;

		if (available_nodes.size() > 1)
			multiple_ans = true;

		for (int i = 0; i < available_nodes.size(); i++){
			int node = available_nodes[i];

			for (int i = 0; i < nodes; i++){
				current[node][i] = false;
				current[i][node] = false;
			}

			visited[node] = true;
			solution += (char)(node + 'A');
		}
	}
}

int main(){
	while (true){
		cin >> nodes >> edges;

		if (nodes == 0 && edges == 0) break;

		if (nodes == 1){
			for (int i = 0; i < edges; i++){
				string s;
				cin >> s;
			}

			cout << "Sorted sequence determined after 0 relations: A." << endl;
			continue;
		}

		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				matrix[i][j] = false;

		solution_found = false, invalid_relation = false;

		string final_solution;

		for (int i = 0; i < edges; i++){
			string input;
			cin >> input;

			int nodeA = input[0] - 'A', nodeB = input[2] - 'A';
			matrix[nodeA][nodeB] = true;

			if (!solution_found && !invalid_relation){
				int result = topological_sort();

				if (result == 1){
					invalid_relation = true;
					first_node_id = i + 1;
				}
				else if (result == 3){
					solution_found = true;
					final_solution = solution;
					first_node_id = i + 1;
				}
			}
		}

		if (solution_found){
			printf("Sorted sequence determined after %d relations: %s.\r\n", first_node_id, final_solution.c_str());
		}
		else if (invalid_relation){
			printf("Inconsistency found after %d relations.\r\n", first_node_id);
		}
		else {
			printf("Sorted sequence cannot be determined.\r\n");
		}
	}

	return 0;
}
