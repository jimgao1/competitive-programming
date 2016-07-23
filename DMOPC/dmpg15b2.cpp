
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a, b;
    for (int i = 0, x; i < 3; i++) { cin >> x; a.push_back(x); }
    for (int i = 0, x; i < 3; i++) { cin >> x; b.push_back(x); }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool flag = true;
    for (int i = 0; i < 3; i++){
        if (a[i] > b[i]) flag = false;
    }

    cout << (flag ? "Y" : "N") << endl;
}
