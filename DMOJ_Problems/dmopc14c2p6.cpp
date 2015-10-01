
#include <bits/stdc++.h>

using namespace std;

struct query{
    int a, b, q, i;
    query(int na, int nb, int nq, int ni){
        a = na, b = nb, q = nq, i = ni;
    }
};

bool comp(query a, query b) { return a.q > b.q; }

int N, Q, ans[200010], bit[100001];
vector<pair<int, int>> trees;
vector<query> q;

void update(int idx, int val){
    while(idx <= N){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int squery(int idx){
    int ans = 0;

    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & -idx);
    }

    return ans;
}

int main(){
    scanf("%d", &N);
    for (int i = 0, height; i < N; i++){
        scanf("%d", &height);
        trees.push_back({height, i + 1});
    }

    sort(trees.begin(), trees.end());
    reverse(trees.begin(), trees.end());

    scanf("%d", &Q);

    for (int i = 0, a, b, c; i < Q; i++){
        scanf("%d%d%d", &a, &b, &c);
        q.push_back(query(a + 1, b + 1, c, i));
    }

    sort(q.begin(), q.end(), comp);

    int pindex = 0;

    for (int i = 0; i < Q; i++){
        for (int j = pindex; j < N; j++){
            if (q[i].q <= trees[j].first){
                pindex ++;
                update(trees[j].second, trees[j].first);
            } else {
                break;
            }
        }

        ans[q[i].i] = squery(q[i].b) - squery(q[i].a - 1);
    }

    for (int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);
}
