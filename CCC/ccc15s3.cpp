
#include <bits/stdc++.h>
using namespace std;

int cnt = 0, gates, planes;
set<int> g;

int main(){
    cin >> gates >> planes;

    for (int i=1; i<=gates; i++)
        g.insert(i);

    for (int i=0, x; i<planes; i++){
        cin >> x;

        auto it = g.upper_bound(x);

        if (g.upper_bound(x) == g.begin()){
            cout << i << endl;
            return 0;
        }

        g.erase(--it);
    }

    cout << planes << endl;
    return 0;
}
