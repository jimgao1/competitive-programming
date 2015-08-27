/*
ID: jim_yub1
LANG: C++11
TASK: butter
*/

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int tar, weight;
    edge(int a, int b) { tar = a, weight = b; }
};

int N, P, C, ans = INF;
int mdist[801][801], ext[801];

bool cont[801];

vector<edge> adjList[801];
queue<int> d;

void dijkstra(int source){
    memset(cont, false, sizeof cont);
    while(!d.empty()) d.pop();

    mdist[source][source] = 0;
    d.push(source);

    while(!d.empty()){
        int cur = d.front();
        d.pop();
        cont[cur] = false;

        for (edge i : adjList[cur]){
            int tar = i.tar, weight = i.weight;

            if (mdist[source][tar] > mdist[source][cur] + weight){
                mdist[source][tar] = mdist[source][cur] + weight;

                if (!cont[tar]){
                    cont[tar] = true;
                    d.push(tar);
                }
            }
        }
    }

}

int main(){
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);

    memset(mdist, 0x3f, sizeof mdist);

    scanf("%d%d%d", &N, &P, &C);
    for (int i = 0, n; i < N; i++){
        scanf("%d", &n);
        ext[n - 1] ++;
    }

    for (int i = 0, src, tar, weight; i < C; i++){
        scanf("%d%d%d", &src, &tar, &weight);
        adjList[src - 1].push_back(edge(tar - 1, weight));
        adjList[tar - 1].push_back(edge(src - 1, weight));
    }

    for (int i = 0; i < P; i++) dijkstra(i);

    for (int i = 0; i < P; i++){
        int sum = 0;
        for (int j = 0; j < P; j++){
            sum += ext[j] * mdist[i][j];
        }

        ans = min(ans, sum);
    }

    printf("%d\n", ans);
}
