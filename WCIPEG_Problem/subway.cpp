
#include <bits/stdc++.h>

#define ll long long

using namespace std;

//the final diameter and the number of diameters
ll N, diameter = 0, ndiameter = 0;

//the height and number of height for nodes
ll height[400001], nheight[400001];

bool visited[400001];

vector<int> adjList[400001];

void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = true;

    height[cur] = 0, nheight[cur] = 1;

    for (int i = 0; i < adjList[cur].size(); i++){
        int e = adjList[cur][i];
        if (visited[e]) continue;

        dfs(e);

        //update the final answer
        if (height[cur] + height[e] + 1 > diameter){
            diameter = height[cur] + height[e] + 1;
            ndiameter = nheight[cur] * nheight[e];

        } else if (height[cur] + height[e] + 1 == diameter){
            ndiameter += nheight[cur] * nheight[e];
        }

        //update the parent (current) node
        if (height[e] + 1 > height[cur]){
            height[cur] = height[e] + 1;
            nheight[cur] = nheight[e];
        } else if (height[e] + 1 == height[cur]){
            nheight[cur] += nheight[e];
        }
    }
}

int main(){
    memset(visited, false, sizeof visited);

    scanf("%d", &N);
    for (int i = 0, x, y; i < N - 1; i++){
        scanf("%d%d", &x, &y);

        adjList[x - 1].push_back(y - 1);
        adjList[y - 1].push_back(x - 1);
    }

    dfs(0);

    printf("%lld\n", ndiameter);
}
