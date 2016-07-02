
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, M;
bool flag = false, visited[MAXN];
vector<int> adjList[MAXN];

void dfs(int cur, int start){
    if (visited[cur]) return;
    if (cur == start){
        flag = true;
        return;
    }

    visited[cur] = true;

    for (int i : adjList[cur]){
        dfs(i, start);
    }
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < N; i++){
        sort(adjList[i].begin(), adjList[i].end());
        adjList[i].erase(unique(adjList[i].begin(), adjList[i].end()), adjList[i].end());
    }

    for (int i = 0; i < N; i++){
        memset(visited, 0, sizeof visited);
        flag = false;
        for (int x : adjList[i])
            dfs(x, i);
        if (flag) break;
    }

    cout << (flag ? "N" : "Y") << endl;
}
