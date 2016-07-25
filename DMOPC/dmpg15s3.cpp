
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, M, value[MAXN];
vector<pair<int, int>> disturb;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> value[i];

    cin >> M;
    for (int i = 0, a, d; i < M; i++){
        cin >> a >> d;
        disturb.push_back({a - 1, d});
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans += value[i];
    for (pair<int, int> d : disturb) ans -= d.second;

    for (pair<int, int> d : disturb){
        if (d.second > value[d.first] || d.second > value[d.first + 1]){
            ans = ans + d.second - min(value[d.first], value[d.first + 1]);
        }
    }

    cout << ans << endl;
}
