
/*
ID: jim_yub1
LANG: C++11
TASK: rockers
*/

#include <bits/stdc++.h>

using namespace std;

int N, T, M, len[21], ans = 0;

inline int cntBit(int n){
    int cnt = 0;
    while(n > 0){
        cnt += n & 1;
        n = n >> 1;
    }

    return cnt;
}

inline bool getBit(int n, int bit){
    return n & (1 << bit);
}

int main(){
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);

    scanf("%d%d%d", &N, &T, &M);
    for (int i = 0; i < N; i++) scanf("%d", &len[i]);

    for (int i = 0; i < (1 << N); i++){
        int curDisk = 0, curLocation = 0, cnt = 0;
        bool valid = true;

        for (int j = 0; j < N; j++){
            if (getBit(i, j)){
                if (len[j] > T){
                    valid = false;
                    break;
                }

                if (curLocation + len[j] <= T){
                    curLocation += len[j];
                } else {
                    curDisk += 1;
                    curLocation = len[j];
                }
            }
        }

        if (curDisk > M) valid = false;
        if (curDisk == M && curLocation > 0) valid = false;

        if (valid) ans = max(ans, cntBit(i));
    }

    printf("%d\n", ans);
}
