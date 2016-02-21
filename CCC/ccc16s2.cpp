#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> s1, s2;

int main(){
    cin >> T >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        s1.push_back(x);
    }

    for (int i = 0, x; i < N; i++){
        cin >> x;
        s2.push_back(x);
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (T == 2){
        reverse(s2.begin(), s2.end());
    }

    int ans = 0;

    for (int i = 0; i < N; i++){
        ans += max(s1[i], s2[i]);
    }

    cout << ans << endl;
}
