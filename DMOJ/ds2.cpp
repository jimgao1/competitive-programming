#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge{
	int src, tar, weight;

	edge(int a, int b, int c){
		src = a, tar = b, weight = c;
	}
};

bool comp(edge a, edge b){
	return a.weight < b.weight;
}

int nodeCount, edgeCount, dset[1000001], size[1000001];
vector<edge> e;
vector<int> edges;

//Initialization
void build(){
	for (int i = 0; i < nodeCount; i++){
		dset[i] = i, size[i]= 1;
	}
}

//Union Find
int ufind(int n){
	int root = n;

	//Finding the index of element 'n'
	while(root != dset[root])
		root = dset[root];

	//Optimization
	while(root != n){
		int temp = dset[n];	//Next element from n
		dset[n] = root;		//Assigning to root
		n = temp;		//Update pointer to next
	}

	return root;
}

//Union Merge
void umerge(int a, int b){
	//Finding root of the 2 elements
	int ra = ufind(a), rb = ufind(b);

	//Exit if they are on the same set (merge with self)
	if (ra == rb) return;

	//Merging smaller one into bigger one
	if (size[ra] > size[rb]){
		dset[rb] = ra;
		size[ra] += size[rb];
	} else {
		dset[ra] = rb;
		size[rb] += size[ra];
	}
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(false);

	int c = 1;

	while(c-- != 0){
		int maxEdge = -1, eCount = 0;
		e.clear();

		cin >> nodeCount >> edgeCount;

        for (int i = 0, a, b; i < edgeCount; i++){
            cin >> a >> b;

            e.push_back(edge(a - 1, b - 1, i + 1));
        }

		build();

		sort(e.begin(), e.end(), comp);

		for (int i = 0; i < e.size(); i++){
            if (eCount == nodeCount) break;

			int src = e[i].src;
			int tar = e[i].tar;
			int weight = e[i].weight;

			if (ufind(src) != ufind(tar)){
                edges.push_back(weight);
				umerge(src, tar);
				eCount++;
			}
		}

		bool flag = false;

        for (int i = 0; i < nodeCount; i++)
            if (dset[i] == i){
                if (flag){
                    cout << "Disconnected Graph" << endl;
                    return 0;
                }
                flag = true;
            }

        for (int x : edges)
            cout << x << endl;

	}

	return 0;
}
