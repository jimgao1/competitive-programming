
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, color[MAXN];
vector<int> adjList[MAXN];

void dfs(int cur, int c) {
    color[cur] = c;
    for (int i : adjList[cur]) {
        if (color[i] == 0) {
            dfs(i, 3 - c);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        while (true) {
            cin >> x;
            if (x == 0) break;
            adjList[i].push_back(x - 1);
        }
    }

    for (int i = 0; i < N; i++) {
        if (color[i] == 0) dfs(i, 1);
    }

    int cnt = 0;
    for (int i = 0; i < N; cnt += (color[i++] == 1));

    printf("%d\n", cnt);
    for (int i = 0; i < N; i++) {
        if (color[i] == 1)
            printf("%d ", i + 1);
    }
}
