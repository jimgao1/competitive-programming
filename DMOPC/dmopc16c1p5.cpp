
#include <bits/stdc++.h>

#define MAXN 500001

using namespace std;

int N, bit[MAXN], freq[MAXN];
long long ans = 0;
vector<int> nums;
map<int, int> dict;

void update(int i, int val){
    while(i < MAXN){
        bit[i] += val;
        i += (i & -i);
    }
}

int query(int i){
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

int main(){
    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        nums.push_back(x);
    }

    vector<int> keys(nums.begin(), nums.end());
    sort(keys.begin(), keys.end());
    keys.erase(unique(keys.begin(), keys.end()), keys.end());

    for (int i = 0; i < keys.size(); i++){
        dict[keys[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++){
        nums[i] = dict[nums[i]];
    }

    for (int i = 0; i < nums.size(); i++){
        int n = nums[i];
        int idx = query(n + 1) - freq[n];
        ans += min(idx, i - idx - freq[n]);

        update(n + 1, 1);
        freq[n] ++;
    }

    cout << ans << endl;
}

