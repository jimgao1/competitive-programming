
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll s, g;

int main() {
    cin >> s >> g;
    if ((s % g != 0 && g != 1) || s - g < g) {
        cout << -1 << endl;
    } else {
        cout << g << " " << s - g << endl;
    }
}
