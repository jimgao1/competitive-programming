#include <bits/stdc++.h>
#define MAXN 2001

using namespace std;

struct edge{
    int a, b, w;
};

int N, M, A, dist[MAXN];
vector<edge> e;

// Returns true if no negative-weight cycle
// exists
bool bellman_ford(int src){
    memset(dist, 0x3f, sizeof dist);
    dist[src] = 0;

    for (int i = 0; i < N - 1; i++){
        for (edge c : e){
            if (dist[c.a] + c.w < dist[c.b]){
                dist[c.b] = dist[c.a] + c.w;
            }
        }
    }

    for (edge c : e){
        if (dist[c.a] + c.w < dist[c.b]){
            return 0;
        }
    }

    return 1;
}

int main(){
    cin >> N >> M >> A;
    for (int i = 0, a, b, w; i < M; i++){
        cin >> a >> b >> w;
        e.push_back({a, b, w});
        e.push_back({b, a, w});
    }

    if (bellman_ford(A)){
        for (int i = 0; i < N; i++){
            printf("dist[%d] = %d\n", i, dist[i]);
        }
    } else {
        printf("Negative-weight cycle\n");
    }
}

