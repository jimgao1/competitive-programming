#include <bits/stdc++.h>

using namespace std;

int N;
double cur = 0;

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while(N--){
        double a;
        cin >> a;

        cur += a;
        cur = fmod(cur, 360);
    }

    cout << cur << "\n";
}
