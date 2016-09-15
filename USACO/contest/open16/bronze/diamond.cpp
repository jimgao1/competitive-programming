
#include <bits/stdc++.h>

#define MAXN 10001

using namespace std;

int N, K, ans = 0, d[MAXN];
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> d[i];

    sort(d, d + N);
    pq.push(d[0]);
    int idx = 1;
    while(true){
        ans = max(ans, (int)(pq.size()));
        //printf("size = %d\n", pq.size());

        if (idx == N) break;
        while (!pq.empty() && abs(d[idx] - pq.top()) > K){
            //printf("a = %d, top = %d\n", d[idx], pq.top());
            pq.pop();
        }
        pq.push(d[idx++]);
    }

    cout << ans << endl;
}


