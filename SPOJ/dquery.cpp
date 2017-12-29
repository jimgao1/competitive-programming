
#include <bits/stdc++.h>

#define MAXN 30004

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

char _;

struct query{
    int l, r, id;
    query(int a, int b, int c){
        id = a, l = b, r = c;
    }
};

int N, K, S, A[MAXN], ans[200005], mp[1000006];
vector<query> queries;

int curLeft, curRight, curAns;

void update(int l, int r) {
    while (l < curLeft) {
        curLeft--;
        if (mp[A[curLeft]] == 0) curAns++;
        mp[A[curLeft]]++;
    }

    while (r > curRight) {
        curRight++;
        if (mp[A[curRight]] == 0) curAns++;
        mp[A[curRight]]++;
    }

    while (l > curLeft) {
        if (mp[A[curLeft]] == 1) curAns--;
        mp[A[curLeft]]--;
        curLeft++;
    }

    while (r < curRight) {
        if (mp[A[curRight]] == 1) curAns--;
        mp[A[curRight]]--;
        curRight--;
    }
}

int main() {
    scan(N);
    for (int i = 0; i < N; i++) scan(A[i]);
    S = sqrt(N);

    scan(K);
    for (int i = 0, a, b; i < K; i++) {
        scan(a);
        scan(b);
        a--, b--;
        queries.push_back(query(i, a, b));
    }

    sort(queries.begin(), queries.end(), [](query a, query b) {
        if (a.l / S != b.l / S) return (a.l / S) < (b.l / S);
        return a.r > b.r;
    });

    curLeft = 0, curRight = 1;
    curAns = (A[0] == A[1]) ? 1 : 2;

    mp[A[0]]++;
    mp[A[1]]++;

    for (query curQuery : queries) {
        if (curQuery.l == curQuery.r){
            ans[curQuery.id] = 1;
        } else {
            update(curQuery.l, curQuery.r);
            ans[curQuery.id] = curAns;
        }

    }

    for (int i = 0; i < K; i++)
        printf("%d\n", ans[i]);
}

