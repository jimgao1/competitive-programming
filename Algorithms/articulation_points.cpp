
#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

int N, M;
vector<int> adjList[MAXN];

int idx = 0, parent[MAXN], low[MAXN], order[MAXN];
bool ap[MAXN], visited[MAXN];

/*
 *  Source: http://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
 *
 *  A DFS method is used to find all articulation points on a graph
 *
 *  A node u is an articulation point if:
 *
 *      a) u is the root of the DFS tree, and has 2 or more children
 *      b) u is NOT the root, and the low value of one of its children is larger than
 *             the discovery value (order) of u
 *
 *  This algorithm runs in O(V+E) time.
 */

void dfs(int cur){
    visited[cur] = 1;

    int child = 0;
    order[cur] = low[cur] = ++idx;

    for (int i : adjList[cur]){
        if (!visited[i]){
            child++;
            parent[i] = cur;

            dfs(i);
            low[cur] = min(low[cur], low[i]);

            if (parent[cur] == -1){
                //Case 1: If the current node is the root
                if (child >= 2) ap[cur] = 1;
            } else {
                //Case 2: Low[Child] > Order[Cur]
                if (low[i] >= order[cur]) ap[cur] = 1;
            }
        } else if (i != parent[cur]){
            low[cur] = min(low[cur], order[i]);
        }
    }
}

void findAP(){
    memset(parent, -1, sizeof parent);

    for (int i = 0; i < N; i++){
        if (!visited[i])
            dfs(i);
    }
}

int main(){
}
