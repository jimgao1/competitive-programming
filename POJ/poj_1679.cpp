
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int src, tar, weight, mst;

    edge(int a, int b, int c){
        src = a, tar = b, weight = c;
        mst = 0;
    }
};

bool comp(edge a, edge b){
    if (a.weight != b.weight)
        return a.weight < b.weight;

    return a.mst < b.mst;
}

int nodeCount, edgeCount, dset[101], dsize[101];
vector<edge> e;

void build(){
    for (int i = 0; i < 101; i++)
        dset[i] = i, dsize[i] = 1;
}

int ufind(int n){
    int root = n;

    while(root != dset[root])
        root = dset[root];

    while(root != n){
        int temp = dset[n];
        dset[n] = root;
        n = temp;
    }

    return root;
}

void umerge(int a, int b){
    int ra = ufind(a), rb = ufind(b);
    if (ra == rb) return;

    if (dsize[ra] > dsize[rb]){
        dset[rb] = ra;
        dsize[ra] += dsize[rb];
    } else {
        dset[ra] = rb;
        dsize[rb] += dsize[ra];
    }
}

void printEdges(){
    cout << "---------------------------" << endl;
    for (int i = 0; i < e.size(); i++){
        printf("%d\t%d\t%d\t%d\t%d\n", i, e[i].src, e[i].tar, e[i].weight, e[i].mst);
    }
    cout << endl;
}

int main(){
    int c;
    cin >> c;

    while(c-- != 0){
        e.clear();
        build();

        cin >> nodeCount >> edgeCount;

        for (int i = 0; i < edgeCount; i++){
            int src, tar, weight;
            cin >> src >> tar >> weight;

            e.push_back(edge(src, tar, weight));
            //e.push_back(edge(tar, src, weight));
        }

        sort(e.begin(), e.end(), comp);
        //printEdges();

        int tempCount = 0, mstSum = 0, mstSum2 = 0;

        for (int i = 0; i < e.size(); i++){
            if (tempCount == nodeCount) break;

            int src = e[i].src, tar = e[i].tar, weight = e[i].weight;

            if (ufind(src) != ufind(tar)){
                mstSum += weight;
                umerge(src, tar);
                e[i].mst = 1;
                tempCount++;
            }
        }

        sort(e.begin(), e.end(), comp);
        //printEdges();
        build();
        tempCount = 0;

        for (int i = 0; i < e.size(); i++){
            if (tempCount == nodeCount) break;

            int src = e[i].src, tar = e[i].tar, weight = e[i].weight;

            if (ufind(src) != ufind(tar)){
                mstSum2 += weight;
                e[i].mst += 1;
                umerge(src, tar);
                tempCount++;
            }
        }

        //printEdges();

        if (mstSum == mstSum2){
            bool notUnique = false;

            for (int i = 0; i < e.size(); i++)
                if (e[i].mst == 1) notUnique = true;

            if (notUnique)
                cout << "Not Unique!" << endl;
            else
                cout << mstSum << endl;
        } else {
            cout << mstSum << endl;
        }
    }
}
