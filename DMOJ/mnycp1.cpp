#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    
    while(a < b) a += b;
    cout << a % b << endl;
}
