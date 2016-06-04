
#include <bits/stdc++.h>

#define MAXN 100001
#define ll long long

using namespace std;

ll N, K, num[MAXN * 2], psum[MAXN * 2];
deque<pair<int, ll>> d;

int main(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> num[i];
    for (int i = N + 1; i <= N + K; i++)
        num[i] = num[i - N];

    ll ans = 0;
    d.push_back({0, 0});
    for (int i = 1; i <= N + K; i++){
        int idx = i;

        psum[i] = psum[i - 1] + num[i];
        ans = max(ans, num[idx]);

        if (psum[idx] <= 0){
            d.push_back({idx, psum[idx]});
        }

        while(true){
            if (d.empty()) break;
            if (abs(idx - (d.front().first)) > K) {
                d.pop_front();
                continue;
            }
            break;
        }

        if (psum[idx] - d.front().second > ans){
            ans = psum[idx] - d.front().second;
        }

        while(true){
            if (d.empty()) break;
            if (d.back().second >= psum[idx]){
                d.pop_back();
            } else {
                break;
            }
        }

        q.push_back({idx, psum[idx});
    }

    cout << ans << endl;
}
