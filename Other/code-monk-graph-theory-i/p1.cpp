
#include <bits/stdc++.h>

using namespace std;

int N, M, dset[100001];
unsigned long long dsize[100001], ans[100001], maxPoints = 0;
vector<pair<int, int> > edges;

unsigned long long umax(unsigned long long a, unsigned long long b){
	return (a > b ? a : b);
}

void build(){
    for(int i = 0; i < 100001; i++)
        dset[i] = i, dsize[i] = 1;
}

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

void umerge(int a, int b){
	//Finding root of the 2 elements
	int ra = ufind(a), rb = ufind(b);

	//Exit if they are on the same set (merge with self)
	if (ra == rb) return;

	//Merging smaller one into bigger one
	if (dsize[ra] > dsize[rb]){
		dset[rb] = ra;
		dsize[ra] += dsize[rb];
	} else {
		dset[ra] = rb;
		dsize[rb] += dsize[ra];
	}
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int cCount;
    cin >> cCount;

    while(cCount-- != 0){
        maxPoints = 0;
        edges.clear();

        cin >> N >> M;

        build();

        for (int i = 0, x, y; i < M; i++){
            cin >> x >> y;
            umerge(x - 1, y - 1);
        }

        for (int i = 0; i < N; i++) ans[i] = 0;

        for (int i = 0, a; i < N; i++){
            cin >> a;
            ans[ufind(i)] += a;
        }

        for (int i = 0; i < N; i++)
            maxPoints = umax(maxPoints, ans[i]);

        cout << maxPoints << endl;
    }

    return 0;
}
