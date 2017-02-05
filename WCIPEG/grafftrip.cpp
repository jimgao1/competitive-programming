
[3;2~
#include <bits/stdc++.h>

#define INF 1e18
#define MAXN 10010
#define ll long long
#define state pair<ll, pair<ll, int>>

using namespace std;

ll N, M, X, Y, S;
bool worship[MAXN];
ll L, dist[MAXN], before[MAXN];

vector<pair<int, ll>> adjList[MAXN];
priority_queue<state, vector<state>, greater<state>> pq;

void dijkstra(ll limit){
    for (int i = 0; i < N + 1; i++){
        dist[i] = INF;
        before[i] = INF;
    }

    pq.push(make_pair(0, make_pair(0, X)));
    while(!pq.empty()){
        state cur = pq.top(); pq.pop();

        int node = cur.second.second;
        ll stch = cur.second.first, d = cur.first;

        if (stch > limit) continue;
        if (d > dist[node] && stch > before[node]) continue;

        dist[node] = min(dist[node], d);
        before[node] = min(before[node], stch);

        ll add = (worship[node] ? 0 : before[node]);

        for (pair<int, ll> i : adjList[node]){
            state nxt;
            nxt.second.second = i.first;
            nxt.first = d + i.second, nxt.second.first = add + i.second;

            if (dist[i.first] > nxt.first || before[i.first] > nxt.second.first)
                pq.push(nxt);
        }
    }
}

int main(){
    //freopen("fuckhenry.txt", "r", stdin);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X >> Y >> L;
    for (int i = 0, a, b; i < M; i++){
        ll w;
        cin >> a >> b >> w;
        adjList[a].push_back(make_pair(b, w));
    }
    cin >> S;
    for (int i = 0, x; i < S; i++){
        cin >> x;
        worship[x] = true;
    }

    ll low = 0, high = L, ans = -1;
    while(low <= high){
        ll mid = 1LL * (high + low) >> 1;
        dijkstra(mid);

        if (dist[Y] <= L){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}

