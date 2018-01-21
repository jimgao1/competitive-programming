#include <bits/stdc++.h>

#define MAXN 21
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
	int a, b, w;
	edge(int aa, int bb, int ww){
		a = aa, b = bb, w = ww;
	}
};

int N, M, K, S, C[1 << MAXN], dist[MAXN], matrix[MAXN][MAXN], dp[1 << MAXN];
bool visited[MAXN];
vector<int> cost[MAXN];

inline int firstBit(int n) {
    return 31 - __builtin_clz(n);
}

inline int getBit(int n, int idx) {
    return n & (1 << idx);
}

void print_bin(int n) {
    for (int i = N; i >= 0; i--) {
        printf("%d", (n & (1 << i)) ? 1 : 0);
    }
    printf("\n");
}

void prims(int mask) {
	for (int i = 0; i < N; i++){
		visited[i] = false;
		dist[i] = INF;
	}

    int begin = firstBit(mask), total = 0;
    dist[begin] = 0;

    for (int i = 0; i < N; i++) {
        if (!getBit(mask, i)) continue;

        int u = -1;
        for (int j = 0; j < N; j++) {
            if (getBit(mask, j) && !visited[j] && (u == -1 || dist[u] > dist[j])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;

        total += dist[u];
        visited[u] = true;

        for (int j = 0; j < N; j++) {
            if (getBit(mask, j) && !visited[j] && dist[j] > matrix[j][u]) {
                dist[j] = matrix[j][u];
            }
        }
    }

    bool f = true;
    for (int i = 0; i < N; i++)
        if (getBit(mask, i) && !visited[i]) f = false;

    if (f) {
        cost[firstBit(mask)].emplace_back(mask);
		C[mask] = total;
    }
}

int popcount(int n) {
    int a = 0;
    for (int i = 0; i < N; i++)
        if (getBit(n, i)) a++;
    return a;
}

inline int calc(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != -1) return dp[mask];
	if (popcount(mask) < S) return INF;
	if (popcount(mask) == S) return C[mask];

    int ans = 1e9;
    int x = firstBit(mask);
	int idx = upper_bound(cost[x].begin(), cost[x].end(), mask) - cost[x].begin();
	for (int i = 0; i < idx; i++){
		if ((cost[x][i] & mask) == cost[x][i])
			ans = min(ans, C[cost[x][i]] + calc(mask & (~(cost[x][i]))));
	}
	
    return dp[mask] = ans;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
	if (N % K != 0){
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			matrix[i][j] = INF;

	for (int i = 0; i < (1 << N); i++) dp[i] = -1, C[i] = INF;

    for (int i = 0, a, b, w; i < M; i++) {
        scanf("%d%d%d", &a, &b, &w);
        a--, b--;
        matrix[a][b] = matrix[b][a] = w;
    }

    S = N / K;

    for (int i = 0; i < (1 << N); i++) {
        if (popcount(i) == S) {
            prims(i);
        }
    }
    int ans = calc((1 << N) - 1);

    if (ans >= 1e9)
        printf("-1\n");
    else
        printf("%d\n", ans);
}
