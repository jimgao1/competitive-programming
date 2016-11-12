
#include <bits/stdc++.h>

using namespace std;

int N, M, pre[MAXN];
bool visited[MAXN];
vector<int> adjList[MAXN];

bool hungary(int cur){
    for (int i : adjList[cur]){
        if (visited[i]) continue;
        visited[i] = true;

        if (!pre[i] || hungary(pre[i])){
            pre[i] = cur;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++){
        memset(visited, 0, sizeof visited);
        if (hungary(i)) cnt++;
    }

    cout << cnt << endl;
}

