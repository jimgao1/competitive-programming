
#include <bits/stdc++.h>

using namespace std;

int bit[10001], T, N, U, Q;

void update(int i, int val){
    while(i <= N){
        bit[i] += val;
        i += (i & -i);
    }
}

int query(int i){
    int sum = 0;

    while (i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

int main(){
    scanf("%d", &T);

    while(T--){
        memset(bit, 0, sizeof bit);

        scanf("%d %d", &N, &U);

        for (int i = 0, a, b, c; i < U; i++){
            scanf("%d %d %d", &a, &b, &c);

            update(a + 1, c);
            update(b + 2, -1 * c);
        }

        scanf("%d", &Q);

        while(Q--){
            int x;
            scanf("%d", &x);

            printf("%d\n", query(x + 1));
        }
    }
}
