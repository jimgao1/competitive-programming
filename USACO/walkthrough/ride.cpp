/*
ID: jim3
PROG: ride
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int calc(string s){
    int ans = 1;
    for (char c : s){
        ans = (ans * (c - 'A' + 1)) % 47;
    }
    return ans;
}

int main(){
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    string sa, sb;
    cin >> sa >> sb;

    //printf("a = %d, b = %d\n", calc(sa), calc(sb));

    if (calc(sa) != calc(sb)){
        cout << "STAY" << endl;
    } else {
        cout << "GO" << endl;
    }
}

