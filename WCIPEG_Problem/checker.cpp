
#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int M, N;

inline bool isOdd(int x, int y) { return (x % 2 == y % 2); }

struct bit2d{
    ull bit[4000][4000];

    void init(){
        memset(bit, 0, sizeof bit);
    }

    //Update function for cell (x, y)
    void update(int x, int y, int val){
        int y1;
        while(x <= M){
            y1 = y;
            while(y1 <= N){
                bit[x][y1] += val;
                y1 += (y1 & -y1);
            }
            x += (x & -x);
        }
    }

    //Query cumulative frequency from (1, 1) to (x, y)
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

    //Overloaded function to query cumulative frequency from (x1, y1) to (x2, y2)
    int query(int x1, int y1, int x2, int y2){
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
};

bit2d odd, even;

int main(){
    odd.init();
    even.init();

    scanf("%d%d", &M, &N);
    while(true){
        int cmd, a, b, c, d;
        scanf("%d", &cmd);

        if (cmd == 1){
            scanf("%d%d%d", &a, &b, &c);

            if (isOdd(a, b)){
                int orig = odd.query(a, b, a, b);
                odd.update(a, b, c - orig);
            } else {
                int orig = even.query(a, b, a, b);
                even.update(a, b, c - orig);
            }
        } else if (cmd == 2){
            scanf("%d%d%d%d", &a, &b, &c, &d);

            int s1 = odd.query(a, b, c, d);
            int s2 = even.query(a, b, c, d);

            if (isOdd(a, b))
                printf("%d\n", s1 - s2);
            else
                printf("%d\n", s2 - s1);

        } else {
            break;
        }
    }
}
