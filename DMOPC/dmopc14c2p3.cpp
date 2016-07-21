
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> saw, logs;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        saw.push_back(x);
    }

    for (int i = 0, x; i < N; i++){
        cin >> x;
        logs.push_back(x);
    }

    sort(saw.begin(), saw.end());
    sort(logs.begin(), logs.end());

    long long ans = 0;

    for (int i = 0; i < N; i++){
        ans += saw[i] * logs[N - i - 1];
    }

    cout << ans << endl;
}
