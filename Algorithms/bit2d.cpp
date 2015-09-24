
#include <bits/stdc++.h>

using namespace std;

int bit[1025][1025];

//Update function for cell (x, y)
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
