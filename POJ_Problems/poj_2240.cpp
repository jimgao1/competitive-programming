
#include <iostream>
#include <vector>
#include <map>
#include <string>

#define INF 0x3f3f3f3f
#define endl "\n"

using namespace std;

struct edge{
    int src, tar;
    double dist;

    edge(int a, int b, double c){
        src = a, tar = b, dist = c;
    }
};

map<string, int> dict;
vector<edge> e;
int nodeCount, edgeCount, caseCount = 0;
double dist[50];

bool bellman_ford(){

    //Distance Initialization
    for (int i = 0; i < nodeCount; i++)
        dist[i] = 1;

    //Relaxation of Distances
    for (int i = 0; i < nodeCount; i++){
        for (int j = 0; j < e.size(); j++){
            int src = e[j].src, tar = e[j].tar;
            double weight = e[j].dist;

            if (dist[src] * weight > dist[tar])
                dist[tar] = dist[src] * weight;
        }
    }

    //Checking for Negative Weight Cycles
    for (int i = 0; i < e.size(); i++){
        int src = e[i].src, tar = e[i].tar;
        double weight = e[i].dist;

        if (dist[src] * weight > dist[tar])
            return true;
    }

    return false;
}

int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0);

    while(true){
        cin >> nodeCount;

        if (nodeCount == 0) break;
        e.clear();

        for (int i = 0; i < nodeCount; i++){
            string name;
            cin >> name;

            dict[name] = i;
        }

        cin >> edgeCount;

        for (int i = 0; i < edgeCount; i++){
            string nodeA, nodeB;
            double rate;

            cin >> nodeA >> rate >> nodeB;

            int ra = dict[nodeA], rb = dict[nodeB];
            e.push_back(edge(ra, rb, rate));
            //e.push_back(edge(rb, ra, 1.0 / rate));
        }

        caseCount++;

        cout << "Case " << caseCount << ": ";
        if (bellman_ford())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
