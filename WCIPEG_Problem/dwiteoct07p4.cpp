
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int H, S, w[11], mblocks = INF;

inline bool getBit(int num, int b){
    return (num & (1 << b)) != 0;
}

int main(){
    cin >> H >> S;
    for (int i = 0; i < S; i++) cin >> w[i];

    for (int i = 0; i < (1 << S); i++){
        int t = 0, c = 0;

        for (int j = 0; j < S; j++) t += (getBit(i, j) ? w[j] : 0);
        for (int j = 0; j < S; j++) c += (getBit(i, j) ? 1 : 0);

        if (t == H) mblocks = min(mblocks, c);
    }

    cout << (mblocks == INF ? 0 : mblocks) << endl;
}
