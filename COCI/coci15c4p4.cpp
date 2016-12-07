#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll N, K, Q;
vector<ll> levels;

void gen(){
    ll total = 1, cur = 1;
    while(true){
        levels.push_back(total);
        if (total > N) break;
        cur *= K;
        total += cur;
    }
}

int calcLevel(ll id){
    vector<ll>::iterator it = lower_bound(levels.begin(), levels.end(), id) - 1;
    return (int)(it - levels.begin()) + 1;
}

ll parent(ll id){
    return ceil((id - 1) / (double)(K));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K >> Q;
    gen();

    while(Q--) {
        ll a, b;
        cin >> a >> b;
        int la = calcLevel(a), lb = calcLevel(b);

        if (la > lb) {
            swap(la, lb);
            swap(a, b);
        }

        ll ans = lb - la;
        for (int i = 0; i < lb - la; i++){
            b = parent(b);
        }

        while(a != b){
            a = parent(a);
            b = parent(b);
            ans += 2;
        }

        cout << ans << "\n";
    }
}
