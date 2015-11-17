
#include <bits/stdc++.h>

using namespace std;

int N, dp[10001];
bool visited[10001];

vector<int> adjList[10001], parents[10001];

priority_queue<int, vector<int>, greater<int>> bfs;

int main(){
    scanf("%d", &N);

    while(true){
        int a, b;
        scanf("%d%d", &a, &b);

        if (a == 0 && b == 0) break;
        adjList[a - 1].push_back(b - 1);
        parents[b - 1].push_back(a - 1);
    }

    dp[0] = 1;
    bfs.push(0);

    while(!bfs.empty()){
        int cur = bfs.top();
        bfs.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        for (int i : parents[cur]) dp[cur] += dp[i];

        for (int i : adjList[cur]){
            if (!visited[i]) bfs.push(i);
        }
    }

    printf("%d\n", dp[N - 1]);
}
