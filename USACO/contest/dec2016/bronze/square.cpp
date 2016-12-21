
#include <bits/stdc++.h>

using namespace std;

int x[4], y[4];

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
    int ans = 0;
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 4; j++){
            ans = max(ans, abs(x[j] - x[i]));
            ans = max(ans, abs(y[j] - y[i]));
        }
    }

    cout << pow(ans, 2) << endl;
}
