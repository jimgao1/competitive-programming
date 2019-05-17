#include<bits/stdc++.h>
#define ll long long


using namespace std;
#define MAXN 250001

ll N, M, Q;
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

int main(){

    scanf("%lld%lld%lld", &M, &N, &Q);
    for (int i = 0; i < N; i++){
        ll x;
        scanf("%lld", &x);
        rangeUpdate(i + 1, i + 1, x);
    }

    for (int i = 0, a, l, r; i < Q; i++){
        scanf("%d", &a);
        ll x;

        if (a == 1){
            scanf("%d%d%d", &l, &r, &x);
            rangeUpdate(l, r, x);
        } else {
            scanf("%d%d", &l, &r);

            printf("%lld\n", rangeQuery(l, r) % M);
        }
    }
}
