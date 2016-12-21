#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, Q;
vector<int> nums;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    cin >> N >> Q;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());

    for (int i = 0, a, b; i < Q; i++){
        cin >> a >> b;
        vector<int>::iterator it1 = lower_bound(nums.begin(), nums.end(), a);
        vector<int>::iterator it2 = upper_bound(nums.begin(), nums.end(), b) - 1;
        cout << max((int)(it2 - it1) + 1, 0) << endl;
    }
}

