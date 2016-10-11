
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MAXN 50010

using namespace std;

int N;
bool v[MAXN * 2];
vector<int> cards, hand;

int main(){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        v[x] = true;
        cards.push_back(x);
    }

    for (int i = 1; i <= N * 2; i++){
        if (!v[i]) hand.push_back(i);
    }

    sort(hand.begin(), hand.end());

    int ans = 0;
    for (int cur : cards){
        auto it = upper_bound(hand.begin(), hand.end(), cur);
        if (it == hand.end()) continue;
        hand.erase(it);
        ans++;
    }

    cout << ans << endl;
}
