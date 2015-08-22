
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

vector<int> adjList[10001];
int T, N, na, nb, parent[10001];

vector<int> path(int n){
    vector<int> result;
    while(n != INF){
        result.push_back(n);
        n = parent[n];
    }

    return result;
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(parent, 0x3f, sizeof parent);

        scanf("%d", &N);
        for (int i = 0, a, b; i < N - 1; i++){
            scanf("%d%d", &a, &b);

            adjList[a - 1].push_back(b - 1);
            parent[b - 1] = a - 1;
        }

        scanf("%d%d", &na, &nb);

        vector<int> x = path(na - 1);
        vector<int> y = path(nb - 1);

        int minDist = INF, id;

        for (int i = 0; i < x.size(); i++){
            for (int j = 0; j < y.size(); j++){
                if (x[i] == y[j]){
                    if (i + j < minDist){
                        minDist = i + j;
                        id = x[i];
                    }
                }
            }
        }

        printf("%d\n", id + 1);
    }
}
