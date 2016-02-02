/*
ID: jim_yub1
LANG: C++11
TASK: race3
*/

#include <bits/stdc++.h>

using namespace std;

int N, visited[51], hist[51];
vector<int> adjList[51], nodes1, nodes2;

bool dfs(int node, int target){
    //printf("current = %d, target = %d\n", node, target);

    if (node == target) return true;

    if (visited[node]) return false;
    visited[node] = 1;
    hist[node] = 1;

    bool ans = false;

    for (int cur : adjList[node]){
        ans = ans | dfs(cur, target);
    }

    visited[node] = 0;
    return ans;
}

bool dfs_fast(int node, int target){
    //printf("current = %d, target = %d\n", node, target);

    if (node == target) return true;

    if (visited[node]) return false;
    visited[node] = 1;

    bool ans = false;

    for (int cur : adjList[node]){
        if (dfs_fast(cur, target)) return true;
    }

    visited[node] = 0;
    return false;
}


int main(){
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1, temp; i < 51; i++){
        bool flag = false;

        while(true){
            scanf("%d", &temp);
            N = max(N, temp);

            if (temp == -2){
                break;
            } else if (temp == -1){
                flag = true;
                break;
            } else {
                adjList[i - 1].push_back(temp);
            }
        }

        if (flag) break;
        N = max(N, i);
    }

    for (int i = 1; i < N; i++){
        memset(visited, 0, sizeof visited);
        visited[i] = true;

        if (!dfs_fast(0, N - 1)){
            nodes1.push_back(i);
        }
    }

    for (int node : nodes1){
        vector<int> x;

        memset(visited, 0, sizeof visited);
        memset(hist, 0, sizeof hist);

        dfs(0, node);
        for (int j = 0; j < N; j++) if (hist[j]) x.push_back(j);

        memset(visited, 0, sizeof visited);
        memset(hist, 0, sizeof hist);
        dfs(node, N + 1);
        for (int j = 0; j < N; j++) if (hist[j]) x.push_back(j);

        if (x.size() == N) nodes2.push_back(node);
    }

    printf("%d", nodes1.size());
    for (int node : nodes1) printf(" %d", node);
    printf("\n%d", nodes2.size());
    for (int node : nodes2) printf(" %d", node);
    printf("\n");
}
