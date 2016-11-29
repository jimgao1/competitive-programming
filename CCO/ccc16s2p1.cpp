
#include <bits/stdc++.h>

#define MAXN 1000001

using namespace std;

int N, M, K, dset[MAXN], dsize[MAXN], cnt[MAXN];
vector<pair<int, int>> edges;

void uinit(){
    for (int i = 0; i < MAXN; i++)
        dset[i] = i, dsize[i] = 1;
}

int ufind(int n){
    while(n != dset[n])
        n = dset[n];
    return n;
}

void umerge(int a, int b){
    int ra = ufind(a), rb = ufind(b);
    if (ra == rb) return;
    if (dsize[ra] > dsize[rb]){
        dsize[ra] += dsize[rb];
        dset[rb] = ra;
    } else {
        dsize[rb] += dsize[ra];
        dset[ra] = rb;
    }
}

int main(){
    uinit();
    cin >> N >> M >> K;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        a--, b--;
        edges.push_back({a, b});
        umerge(a, b);
    }

    for (pair<int, int> pii : edges){
        cnt[ufind(pii.first)] ++;
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < N; i++){
        if (ufind(i) == i){
            if (dsize[i] < K){
            } else if (dsize[i] == K){
                ans1 += K;
            } else {
                int s = dsize[i] / K;
                ans1 += K * s;
                if (cnt[i] == dsize[i]){
                    ans2 += s;
                    if (dsize[i] % K != 0) ans2++;
                } else {
                    ans2 += s;
                    if (dsize[i] % K == 0) ans2--;
                }
            }
        }
    }

    printf("%d %d\n", ans1, ans2);
}
