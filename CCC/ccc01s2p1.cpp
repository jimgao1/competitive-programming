
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

map<int, int> path;
unsigned long int cycle;

unsigned long int gcd(unsigned long int m, unsigned long int n)
{
	int tmp;
	while (m) { tmp = m; m = n % m; n = tmp; }
	return n;
}

unsigned long int lcm(unsigned long int m, unsigned long int n)
{
	return m / gcd(m, n) * n;
}

unsigned long int getCycleLength(int source){
	int current = path[source];
	int steps = 1;

	while (true){
		//cout << "source = " << source << ", current = " << current << ", steps = " << steps << endl;

		if (source == current) return steps;

		current = path[current];
		steps += 1;
	}

	return -1;
}

int main(){

	while (true){
		int nodeCount;
		cin >> nodeCount;

		if (nodeCount == 0) break;

		cycle = 1;

		vector<int> nodes;

		for (int i = 0; i<nodeCount; i++){
			int a, b;
			cin >> a >> b;

			path[a] = b;

			if (!binary_search(nodes.begin(), nodes.end(), a))
				nodes.push_back(a);

			if (!binary_search(nodes.begin(), nodes.end(), b))
				nodes.push_back(b);
		}

		for (int n : nodes){
			//cout << "computing node " << n << endl;
			cycle = lcm(cycle, getCycleLength(n));
			//cout << "done..." << endl;
		}

		cout << cycle << endl;
	}

}
