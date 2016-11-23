
#include <bits/stdc++.h>

#define MAXN 100001
#define pii pair<int, int>
#define state pair<int, pii>

using namespace std;

int N, len[MAXN], dist[MAXN][80];

priority_queue<state, vector<state>, greater<state>> pq;

void dijkstra(int i, int j){
    memset(dist, 0x3f, sizeof dist);
    dist[i][j] = 0;
    pq.push({0, {i, j}});
    

    while(!pq.empty()){
        int cr = pq.top().second.first, cc = pq.top().second.second;
        pq.pop();

        int alt = dist[cr][cc] + 1;

        //Up
        if (cr > 0){
            int nc = cc;
            if (cc >= len[cr - 1]){
                nc = len[cr - 1] - 1;
            }
            if (dist[cr - 1][nc] > alt){
                dist[cr - 1][nc] = alt;
                pq.push({alt, {cr - 1, nc}});
            }
        }

        //Down
        if (cr < N - 1){
            int nc = cc;
            if (cc >= len[cr + 1]){
                nc = len[cr + 1] - 1;
            }
            if (dist[cr + 1][nc] > alt){
                dist[cr + 1][nc] = alt;
                pq.push({alt, {cr + 1, nc}});
            }
        }

        //Left
        if (cc > 0 || cr > 0){
            int nr = cr, nc = cc - 1;
            if (cc == 0){
                nr = cr - 1;
                nc = len[nr] - 1;
            }
            if (dist[nr][nc] > alt){
                dist[nr][nc] = alt;
                pq.push({alt, {nr, nc}});
            }
        }

        //Right
        if (cc == len[cr] - 1){
            if (cr < N - 1){
                if (dist[cr + 1][0] > alt){
                    dist[cr + 1][0] = alt;
                    pq.push({alt, {cr + 1, 0}});
                }
            }
        } else {
            if (dist[cr][cc + 1] > alt){
                dist[cr][cc + 1] = alt;
                pq.push({alt, {cr, cc + 1}});
            }
        }
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> len[i];

    int ar, ac, br, bc;
    cin >> ar >> ac >> br >> bc;
    dijkstra(ar - 1, ac - 1);
    cout << dist[br - 1][bc - 1] << endl;
}

