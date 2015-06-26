
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int src, tar, weight;
    edge(int a, int b, int c){
        src = a, tar = b, weight = c;
    }
};

int c, nodeCount, edgeCount, holeCount, dist[501];
vector<edge> e;

bool bellman_ford(int source){

    //Initialization
    for (int i = 0; i < nodeCount; i++)
        if (i == source)
            dist[i] = 0;
        else
            dist[i] = INF;

    //Relaxation
    for (int i = 0; i < nodeCount; i++){
        for (int j = 0; j < e.size(); j++){
            if (dist[e[j].src] + e[j].weight < dist[e[j].tar])
                dist[e[j].tar] = dist[e[j].src] + e[j].weight;
        }
    }

    //Negative Cycles
    for (int i = 0; i < e.size(); i++){
        if (dist[e[i].src] + e[i].weight < dist[e[i].tar])
            return true;
    }

    return false;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(false);

    cin >> c;
    while(c-- != 0){
        e.clear();

        cin >> nodeCount >> edgeCount >> holeCount;

        for (int i = 0; i < edgeCount; i++){
            int src, tar, weight;
            cin >> src >> tar >> weight;

            e.push_back(edge(src, tar, weight));
            e.push_back(edge(tar, src, weight));
        }

        for (int i = 0; i < holeCount; i++){
            int src, tar, weight;
            cin >> src >> tar >> weight;

            e.push_back(edge(src, tar, -1 * weight));
        }

        bool result = bellman_ford(0);

        cout << (result ? "YES" : "NO") << "\n";
    }
}
