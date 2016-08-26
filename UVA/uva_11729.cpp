
#include <bits/stdc++.h>

using namespace std;

int cc = 0, N;
vector<pair<int, int>> s;

int main(){
    while(true){
        cin >> N;
        if (N == 0) break;
        s.clear();
        for (int i = 0, a, b; i < N; i++){
            cin >> a >> b;
            s.push_back({b, a});
        }

        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());

        int cur = 0, ans = 0;
        for (int i = 0; i < N; i++){
            ans = max(ans, cur + s[i].first + s[i].second);
            cur += s[i].second;
        }

        cout << "Case " << ++cc << ": " << ans << endl;
    }
}

