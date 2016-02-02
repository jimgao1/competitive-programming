
#include <bits/stdc++.h>

using namespace std;

int N, M, W, dist[101];
bool visited[101];
vector<int> adjList[101];

queue<pair<int, int>> q;

int main(){
    scanf("%d%d", &N, &M);
    for (int i = 0, a, b; i < M; i++){
        scanf("%d%d", &a, &b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    scanf("%d", &W);
    for (int i = 0, x; i < W; i++){
        scanf("%d", &x);
        q.push({x, 0});
    }

    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        dist[cur] = st;

        for (int n : adjList[cur]){
            if (!visited[n]){
                q.push({n, st + 1});
            }
        }
    }

    memset(visited, 0, sizeof visited);
    int ans = -1;

    q.push({1, 0});
    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (dist[cur] * 4 < st) continue;
        if (visited[cur]) continue;
        visited[cur] = true;

        if (cur == N){
            ans = st;
            break;
        }
        for (int n : adjList[cur]){
            q.push({n, st + 1});
        }
    }

    if (ans == -1)
        printf("sacrifice bobhob314\n");
    else
        printf("%d\n", ans);
}
