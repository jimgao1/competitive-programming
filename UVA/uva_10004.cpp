
#include <bits/stdc++.h>

#define MAXN 201

using namespace std;

int N, M;
bool visited[MAXN], colored[MAXN], red[MAXN];
vector<int> adjList[MAXN];
queue<int> q;

int main(){
    //freopen("input.txt", "r", stdin);

    while(true){
        memset(visited, 0, sizeof visited);
        memset(colored, 0, sizeof colored);
        memset(red, 0, sizeof red);

        for (int i = 0; i < MAXN; i++) adjList[i].clear();
        while(!q.empty()) q.pop();

        scanf("%d", &N);
        if (N == 0) break;

        scanf("%d", &M);
        for (int i = 0, x, y; i < M; i++){
            scanf("%d%d", &x, &y);
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        q.push(0);
        red[0] = true, colored[0] = true;
        bool flag = true;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            if (visited[cur]) continue;
            visited[cur] = true;

            for (int n : adjList[cur]){
                if (colored[n]){
                    if (red[n] == red[cur]){
                        flag = false;
                        break;
                    }
                } else {
                    colored[n] = true;
                    red[n] = !red[cur];
                }

                if (!visited[n]) q.push(n);
            }

            if (!flag) break;
        }

        cout << (flag ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }
}
