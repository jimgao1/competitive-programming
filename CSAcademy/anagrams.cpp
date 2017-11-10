
#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
unordered_map<string, int> mp;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        mp[str]++;
        ans = max(ans, mp[str]);
    }

    cout << ans << endl;
}
