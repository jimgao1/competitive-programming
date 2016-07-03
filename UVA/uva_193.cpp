
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int T, N, M, ans = 0;
bool visited[MAXN], color[MAXN];
vector<int> blacks, adjList[MAXN];

void search(int cur){

    visited[cur] = true;

    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (color[i]) cnt++;

    if (cnt > ans){
        blacks.clear();
        for (int i = 0; i < N; i++)
            if (color[i])
                blacks.push_back(i);
        ans = cnt;
    }

    if (cur >= N) return;


    bool black = true;
    for (int i : adjList[cur])
        if (visited[i] && color[i])
            black = false;

    if (black){
        color[cur] = true;
        search(cur + 1);
        color[cur] = false;
    }

    search(cur + 1);

    visited[cur] = false;
}

int main(){
    scanf("%d", &T);
    while(T--) {
        for (int i = 0; i < MAXN; i++) adjList[i].clear();
        ans = 0;
        memset(visited, 0, sizeof visited);
        memset(color, 0, sizeof color);
        blacks.clear();


        scanf("%d%d", &N, &M);
        for (int i = 0, a, b; i < M; i++) {
            scanf("%d%d", &a, &b);
            adjList[a - 1].push_back(b - 1);
            adjList[b - 1].push_back(a - 1);
        }

        search(0);

        printf("%d\n", ans);
        for (int i = 0; i < blacks.size(); i++){
            if (i != 0) printf(" ");
            printf("%d", blacks[i] + 1);
        }
        printf("\n");
    }
}
