#include <bits/stdc++.h>

using namespace std;

int T;
unsigned long long x;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--){
        cin >> x;
        int ans = 0;

        while(x != 0){
            if (x & 1){
                if (x & 2 && x != 3){
                    x ++;
                } else {
                    x --;
                }
            } else {
                x = x >> 1;
            }
            ans++;
        }
        cout << ans << "\n";
    }
}
