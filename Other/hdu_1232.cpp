
#include <iostream>
#include <cstdio>

#define INF 0x3f3f3f3f

using namespace std;

int dset[1001], dsize[1001], nodeCount, edgeCount;

void build(){
    for (int i = 0; i < 1001; i++)
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

int main(){
    while(true){
        cin >> nodeCount;
        if (nodeCount == 0) break;

        cin >> edgeCount;

        build();

        for (int i = 0; i < edgeCount; i++){
            int ra, rb;
            cin >> ra >> rb;

            umerge(ra - 1, rb - 1);
        }

        int c = 0;
        for (int i = 0; i < nodeCount; i++){
            if (i == ufind(i)) c++;
        }

        cout << c - 1 << endl;
    }

    return 0;
}
