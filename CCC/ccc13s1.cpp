
#include <bits/stdc++.h>

using namespace std;

bool v[11];

bool check(int n){
    memset(v, 0, sizeof v);
    while(n > 0){
        if (v[n % 10]) return false;
        v[n % 10] = true;
        n = n / 10;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    while(true){
        n++;
        if (check(n)){
            cout << n << endl;
            break;
        }
    }
}
