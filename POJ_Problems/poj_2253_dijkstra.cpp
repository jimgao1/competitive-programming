
/*
    Dijkstra Implementation
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

#define INF 0x3f3f3f3f

using namespace std;

struct point{
    int x, y;

    point(int a, int b){
        x = a, y = b;
    }
};

double s(double c){
    return c * c;
}

double point_dist(point a, point b){
    return sqrt(s(a.y - b.y) + s(a.x - b.x));
}

double dmax(double a, double b){
    return (a > b ? a : b);
}

int nodeCount, cCount = 1;
double dist[201];
bool visited[201];
vector<point> p;
queue<int> bfs;

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> nodeCount;

        if (nodeCount == 0) break;

        while(!p.empty()) p.erase(p.begin());
        while(!bfs.empty()) bfs.pop();

        for (int i = 0, x, y; i < nodeCount; i++){
            cin >> x >> y;
            p.push_back(point(x, y));
        }

        for (int i = 0; i < nodeCount; i++){
            dist[i] = INF;
            visited[i] = false;
        }

        dist[0] = 0;
        bfs.push(0);

        while(!bfs.empty()){
            int current = bfs.front();
            bfs.pop();

            if (visited[current]) continue;

            visited[current] = true;

            for (int i = 0; i < nodeCount; i++){
                double tgt = dmax(dist[current], point_dist(p[current], p[i]));

                if (dist[i] > tgt){
                    dist[i] = tgt;
                    bfs.push(i);
                }
            }
        }

        printf("Scenario #%d\n", cCount);
        printf("Frog Distance = %.3f\n\n", dist[1]);
        cCount++;

    }

    return 0;
}
