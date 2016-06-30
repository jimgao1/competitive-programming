
#include <bits/stdc++.h>

#define MAXN 10001

using namespace std;

int N, M, A, B;
vector<int> adjList[MAXN];
bool visited[MAXN];

void dfs(int cur, int pre){
    if (visited[cur]) return;
    visited[cur] = true;

    for (int i : adjList[cur]){
        if (i != pre)
            dfs(i, cur);
    }
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    cin >> A >> B;

    dfs(A, -1);

    cout << (visited[B] ? 1 : 0) << endl;
}

