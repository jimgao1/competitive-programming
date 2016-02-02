#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

using namespace std;

int N, X, Q, src;
ll dist[6001];
bool visited[6001];
vector<pair<ll, ll>> loc;
vector<ll> fuk;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

void dijkstra(int src){
    memset(dist, 0x3f, sizeof dist);
    dist[src] = 0;

    q.push({0, src});
    while(true){
        int cur = -1;
        ll minDist = LINF;

        for (int i = 0; i < N; i++){
            if (!visited[i] && dist[i] < minDist){
                minDist = dist[i], cur = i;
            }
        }

        if (cur == -1) break;

        visited[cur] = true;

        for (int i = 0; i < N; i++){
            if (i != cur){
                ll w = pow(loc[cur].first - loc[i].first, 2) + pow(loc[cur].second - loc[i].second, 2);

                if (dist[i] > dist[cur] + w){
                    dist[i] = dist[cur] + w;
                }
            }
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        loc.push_back({x, y});
    }

    scanf("%d", &X);
    dijkstra(X - 1);

    for (int i = 0; i < N; i++) fuk.push_back(dist[i]);

    sort(fuk.begin(), fuk.end());

    scanf("%d", &Q);
    while(Q--){
        ll query;
        scanf("%lld", &query);

        printf("%d\n", upper_bound(fuk.begin(), fuk.end(), query) - fuk.begin());
    }
}
