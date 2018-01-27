#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, T;
vector<int> a, b;

int main(){
    cin >> N >> T;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        if (x < 0)
            a.push_back(-x);
        else
            b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 1e9;
    if (b.size() >= T) ans = b[T - 1];
    for (int i = 0; i < a.size(); i++){
        if (T - i - 1 <= b.size()){
            int j = T - i - 2;
            ans = min(ans, 2 * (a[i] + b[j]) - max(a[i], b[j]));
        }
    }

    cout << ans << endl;
}
