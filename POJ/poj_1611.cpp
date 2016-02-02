
#include <iostream>
#include <cstdio>

#define INF 0x3f3f3f3f

using namespace std;

int dset[30001], dsize[30001], stuCount, groupCount;

void build(){
    for (int i = 0; i < 30001; i++)
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
    cin.sync_with_stdio(false);
    cin.tie(false);

    while(true){
        cin >> stuCount >> groupCount;
        if (stuCount == 0 && groupCount == 0) break;

        build();

        for (int i = 0, k, n; i < groupCount; i++){
            cin >> k >> n;
            for (int j = 1, x; j < k; j++){
                cin >> x;
                umerge(x, n);
                //printf("merging #%d with #%d\n", x, n);
            }
        }

        cout << dsize[ufind(0)] << endl;
    }

    return 0;
}
