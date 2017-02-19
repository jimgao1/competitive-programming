#include <bits/stdc++.h>

#define MAXN 100020
#define ll long long

using namespace std;

int N, F;
ll f[MAXN], e[MAXN], p[MAXN];
vector<ll> fail;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> f[i] >> e[i] >> p[i];
    }
    cin >> F;
    for (int i = 0; i < F; i++){
        ll x;
        cin >> x;
        fail.push_back(x);
    }

    sort(fail.begin(), fail.end());

    ll ans = 0;
    for (int i = 0; i < N; i++){
        int idx1 = lower_bound(fail.begin(), fail.end(), f[i]) - fail.begin();
        int idx2 = upper_bound(fail.begin(), fail.end(), e[i]) - fail.begin() - 1;

        if (idx2 < idx1){
            ans += p[i];
        }
    }

    cout << ans << endl;
}
