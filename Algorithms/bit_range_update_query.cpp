#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
typedef long long ll;

ll B1[MAXN], B2[MAXN];

ll pQuery(ll* B, int i){
    ll sum = 0;
    while(i > 0){
        sum += B[i];
        i -= (i & -i);
    }
    return sum;
}

//Returns BIT{1..r}
ll query(int r){
    return pQuery(B1, r) * r - pQuery(B2, r);
}

ll rangeQuery(int i, int j){
    return query(j) - query(i - 1);
}

void pUpdate(ll* B, int i, ll v){
    while(i <= MAXN){
        B[i] += v;
        i += (i & -i);
    }
}

void rangeUpdate(int l, int r, ll v){
    pUpdate(B1, l, v);
    pUpdate(B1, r+1, -v);
    pUpdate(B2, l, v * (l - 1));
    pUpdate(B2, r + 1, -v * r);
}

int main(){}
