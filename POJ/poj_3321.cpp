
#include <cstdio>
#include <iostream>
#include <vector>

#define MAXN 100004

using namespace std;

int N, Q, bit[MAXN * 2];
int count = 0, in[MAXN], out[MAXN];
bool apple[MAXN];
vector< vector<int> >adjList(MAXN);

void dfs(int cur, int prev) {
	in[cur] = count++;

	for (int i = 0; i < adjList[cur].size(); i++) {
		int u = adjList[cur][i];
		if (u != prev)
			dfs(u, cur);
	}

	out[cur] = count++;
}

void update(int i, int val) {
	i += 2;
	while (i <= (MAXN * 2)) {
		bit[i] += val;
		i += (i & -i);
	}
}

int query(int i) {
	i += 2;
	int ret = 0;
	while (i > 0) {
		ret += bit[i];
		i -= (i & -i);
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0, x, y; i < N - 1; i++) {
		scanf("%d%d", &x, &y);
		x--, y--;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	dfs(0, -1);

	for (int i = 0; i < N; i++) {
		apple[i] = true;
		update(in[i], 1);
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		char c;
		int x;
		scanf(" %c%d", &c, &x);
		x--;

		if (c == 'Q') {
			int ret = query(out[x]) - query(in[x] - 1);
			printf("%d\n", ret);
		} else {
			int val = 1;
			if (apple[x]) val = -1;
			apple[x] = !apple[x];

			update(in[x], val);
		}
	}
}
