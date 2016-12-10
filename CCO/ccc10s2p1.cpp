
#include <bits/stdc++.h>

#define MAXN 1001
#define pii pair<int, int>

using namespace std;

int N, M, T, w[MAXN], cnt[MAXN], last[MAXN];
vector<int> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> w[i];
    cin >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
    }
    cin >> T;

    for (int i = 0; i < N; i++) last[i] = -10000;

    pq.push({0, 0});
    while(!pq.empty()){
        int ctime = pq.top().first, cur = pq.top().second;
        pq.pop();

        if (ctime <= last[cur] + w[cur]) continue;
        if (ctime > T) continue;

        last[cur] = ctime;
        cnt[cur] ++;

        for (int i : adjList[cur]){
            pq.push({ctime + w[i], i});
        }
    }

    for (int i = 0; i < N; i++){
        cout << cnt[i] << endl;
    }
}
