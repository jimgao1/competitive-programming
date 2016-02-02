
#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int cmd, S, X, Y, A, L, B, R, T;
int bit[1025][1025];

void update(int x, int y, int val){
    int y1;
    while(x <= S){
        y1 = y;
        while(y1 <= S){
            bit[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int query(int x, int y){
    int sum = 0;
    while(x > 0){
        int y1 = y;
        while(y1 > 0){
            sum += bit[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }

    return sum;
}

int query(int x1, int y1, int x2, int y2){
    return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

int main(){
    //freopen("output.txt", "w", stdout);

    while(true){
        scanf("%d", &cmd);

        if (cmd == 0){
            scanf("%d", &S);
        } else if (cmd == 1){
            scanf("%d%d%d", &X, &Y, &A);
            update(X + 1, Y + 1, A);
        } else if (cmd == 2){
            scanf("%d%d%d%d", &L, &B, &R, &T);
            printf("%d\n", query(L + 1, B + 1, R + 1, T + 1));
        } else {
            break;
        }
    }
}
