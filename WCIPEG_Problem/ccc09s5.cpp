
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int R, C, K, shops[30001][1001];

int main(){

    scanf("%d%d%d", &R, &C, &K);
    for (int i = 0; i < K; i++){
        //printf("reading new data\n");

        int cr, cc, r, b;
        scanf("%d%d%d%d", &cc, &cr, &r, &b);

        cr -= 1, cc -= 1;

        for (int j = -r; j <= r; j++){
            //printf("asd\n");
            int loc = cr + j;
            if (loc < 0 || loc >= R) continue;

            double val = sqrt(r * r - j * j);
            int x1 = (int)(ceil(cc - val));
            int x2 = (int)(floor(cc + val));

            if (x1 < 0) x1 = 0;
            if (x2 >= C) x2 = C - 1;

            //printf("x1 = %d, x2 = %d\n", x1, x2);

            //printf("loc = %d, x1 = %d, x2 = %d\n", loc, x1, x2);

            shops[loc][x1] += b;
            shops[loc][x2 + 1] -= b;
        }
    }

    int mBit = 0, mCnt = 0;

    for (int i = 0; i < R; i++){
        int temp = 0;
        for (int j = 0; j <= C; j++){
            temp += shops[i][j];

            if (temp > mBit){
                mBit = temp;
                mCnt = 1;
            } else if (temp == mBit){
                mCnt ++;
            }
        }
    }

    printf("%d\n%d\n", mBit, mCnt);

}
