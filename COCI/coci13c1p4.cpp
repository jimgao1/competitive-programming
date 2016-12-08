
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>

using namespace std;

int N, K;
vector<pii> items;
multiset<int> bags;

int main(){
    cin >> N >> K;
    for (int i = 0, a, b; i < N; i++){
        cin >> a >> b;
        items.push_back({b, a});
    }
    for (int i = 0, x; i < K; i++){
        cin >> x;
        bags.insert(x);
    }

    sort(items.begin(), items.end(), greater<pii>());

    ll ans = 0;
    for (pii i : items){
        set<int>::iterator it = bags.lower_bound(i.second);
        if (it != bags.end()){
            bags.erase(it);
            ans += i.first;
        }
    }

    cout << ans << endl;
}

