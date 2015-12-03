
#include <bits/stdc++.h>

using namespace std;

int N, cnt = 0, parent[10];
vector<int> adjList[10];

inline bool getBit(int n, int idx) { return n & (1 << idx); }

bool check(int p, int c){
    while(true){
        if (p == c) return false;
        if (c == N - 1) return true;

        c = parent[c];
    }
}

int main(){
    scanf("%d", &N);

    for (int i = 0, x; i < N - 1; i++){
        scanf("%d", &x);

        parent[i] = x - 1;
    }

    for (int i = 0; i < (1 << N); i++){
        bool flag = true;

        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                if (j != k && getBit(i, j) && getBit(i, k)){
                    if (!check(j, k)) flag = false;
                }
            }
        }

        if (flag) cnt++;
    }

    printf("%d\n", cnt - 1);
}
