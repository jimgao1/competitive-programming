
#include <bits/stdc++.h>

#define MAXN 40001

using namespace std;

int N, M, dp[MAXN];
bool visited[MAXN];
vector<int> adjList[MAXN];

void dfs(int cur){
    visited[cur] = true;
    dp[cur] ++;

    for (int i : adjList[cur]){
        if (!visited[i]){
            if (dp[i] < 2){
                dfs(i);
            }
        }
    }

    visited[cur] = false;
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(0);

    if (dp[N - 1] >= 2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
