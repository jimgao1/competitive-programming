#include <bits/stdc++.h>

#define MAXN 1000006

using namespace std;

int N, sum[MAXN];
vector<int> t;
unordered_map<int, int> dict;
vector<pair<int, int>> S;

int main() {
    cin >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        t.push_back(a);
        t.push_back(b);
        S.push_back(make_pair(a, b));
    }

    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    for (int i = 0; i < t.size(); i++) {
        dict[t[i]] = i + 1;
    }

    for (int i = 0; i < S.size(); i++) {
        sum[dict[S[i].first]] ++;
        sum[dict[S[i].second] + 1] --;
    }

    for (int i = 1; i <= t.size(); i++){
        sum[i] += sum[i - 1];
        if (sum[i] > 2){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
