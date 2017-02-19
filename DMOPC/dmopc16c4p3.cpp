#include <bits/stdc++.h>

#define MAXN 100020
#define endl "\n"

using namespace std;

int N, S, Q, dist[MAXN];
set<int> avail[MAXN];
set<pair<int, int>> sell[200];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> dist[i];
    for (int i = 0, a, b; i < S; i++){
        cin >> a >> b;
        sell[b].insert(make_pair(dist[a], a));
        avail[a].insert(b);
    }
    cin >> Q;
    while(Q--){
        string cmd; int a, b;
        cin >> cmd;

        if (cmd == "A"){
            cin >> a >> b;

            avail[a].insert(b);
            sell[b].insert(make_pair(dist[a], a));
        } else if (cmd == "S"){
            cin >> a >> b;

            if (avail[a].count(b)){
                sell[b].erase(sell[b].lower_bound(make_pair(dist[a], a)));
                avail[a].erase(avail[a].find(b));
            }
        } else if (cmd == "E"){
            cin >> a >> b;

            for (int i : avail[a]){
                sell[i].erase(sell[i].lower_bound(make_pair(dist[a], a)));
            }
            dist[a] = b;
            avail[a].clear();
        } else {
            cin >> a;

            if (sell[a].empty()) {
                printf("-1\n");
            } else {
                set<pair<int, int>>::iterator it = sell[a].begin();
                printf("%d\n", it->second);
            }
        }

    }

}
