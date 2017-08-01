#include <bits/stdc++.h>

#define ll long long

using namespace std;

int S, v1, v2, t1, t2;

int main() {
    cin >> S >> v1 >> v2 >> t1 >> t2;

    ll a = v1 * S + t1 * 2;
    ll b = v2 * S + t2 * 2;

    if (a < b)
        cout << "First" << endl;
    else if (a > b)
        cout << "Second" << endl;
    else
        cout << "Friendship" << endl;
}
