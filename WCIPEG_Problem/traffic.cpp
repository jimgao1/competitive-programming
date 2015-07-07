
#include <bits/stdc++.h>


#define INF 0x3f3f3f3f

using namespace std;

int N, K, mTime = INF;
int matrix[1001][1001], green[1001], red[1001], dist[1001];
bool contains[1001];

queue<int> q;

int waitTime(int node, int time){
    //printf("time = %d, node = %d\n", time, node);

    if (red[node] + green[node] == 0) return 0;
    time = time % (green[node] + red[node]);
    if (time < green[node]) {
        //printf("green = %d, time = %d\n", green[node], time);
        return 0;
    }
    //printf("returns %d\n", green[node] - time + red[node]);
    return green[node] - time + red[node];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            matrix[i][j] = INF;

    for (int i = 0; i < 1001; i++) dist[i] = INF;
    for (int i = 0; i < 1001; i++) contains[i] = false;

    for (int i = 0, src, tar, weight; i < N; i++){
        cin >> src >> tar >> weight;
        matrix[src - 1][tar - 1] = weight;
        matrix[tar - 1][src - 1] = weight;
    }

    for (int i = 0, r, g; i < K; i++){
        cin >> g >> r;
        red[i] = r, green[i] = g;
    }

    q.push(0);
    dist[0] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        //printf("current = %d\n", current);
        contains[current] = false;

        for (int i = 0; i < K; i++){
            //printf("i = %d\n", i);
            if (matrix[current][i] != INF && current != i){
                int newDist = dist[current] + matrix[current][i] + waitTime(i, dist[current] + matrix[current][i]);
                if (newDist < dist[i]){
                    dist[i] = newDist;
                    //printf("dist[%d] = %d\n", i, newDist);

                    if (!contains[i]){
                        //printf("pushing node #%d\n", i);
                        q.push(i);
                        contains[i] = true;
                    }
                }
            }
        }

        //getch();
    }

    cout << dist[K - 1] << endl;

}
