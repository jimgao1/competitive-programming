
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct edge {
	int src, tar, type;
	edge(int a, int b, int c) { src = a, tar = b, type = c; }
};

struct disjoint_set {
	int nodes, dset[2001], dsize[2001];

	disjoint_set(int n) {
		for (int i = 0; i < n; i++)
			dset[i] = i, dsize[i] = 1;
	}

	int ufind(int n) {
		int root = n;

		while (root != dset[root])
			root = dset[root];

		while (root != n) {
			int temp = dset[n];
			dset[n] = root;
			n = temp;
		}

		return root;
	}

	void umerge(int a, int b) {
		int ra = ufind(a), rb = ufind(b);
		if (ra == rb) return;

		if (dsize[ra] > dsize[rb]) {
			dset[rb] = ra;
			dsize[ra] += dsize[rb];
		}
		else {
			dset[ra] = rb;
			dsize[rb] += dsize[ra];
		}
	}
};

bool comp(edge a, edge b) {
	return a.type > b.type;
}

int N, M, tcnt = 0, medges = 0, fedges = 0;

vector<edge> e;
disjoint_set male(2001);
disjoint_set female(2001);

int main() {

	scanf("%d%d", &N, &M);

	for (int i = 0, a, b, c; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		e.push_back(edge(a - 1, b - 1, c));
	}

	sort(e.begin(), e.end(), comp);

	for (int i = 0; i < e.size(); i++) {
		bool used = false;

		if (e[i].type == 3) {            //both male and female
			if (male.ufind(e[i].src) != male.ufind(e[i].tar)) {
				used = true;
				male.umerge(e[i].src, e[i].tar);
				medges++;
				tcnt++;
			}

			if (female.ufind(e[i].src) != female.ufind(e[i].tar)) {
				female.umerge(e[i].src, e[i].tar);

				fedges++;
				if (!used) tcnt++;
			}
		}
		else if (e[i].type == 2) {     //only female
			if (female.ufind(e[i].src) != female.ufind(e[i].tar)) {
				female.umerge(e[i].src, e[i].tar);
				fedges++;
				tcnt++;
			}
		}
		else if (e[i].type == 1) {     //only male
			if (male.ufind(e[i].src) != male.ufind(e[i].tar)) {
				male.umerge(e[i].src, e[i].tar);
				medges++;
				tcnt++;
			}
		}
	}

	if (medges < N - 1 || fedges < N - 1) { printf("-1\n"); return 0; }
	printf("%d\n", M - tcnt);
}
