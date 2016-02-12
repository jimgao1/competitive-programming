
#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;

    int cnt = 0;

    for (int i = -x; i <= x; i++){
        double y = sqrt(x * x - i * i);
        cnt += (floor(y) - ceil(-y) + 1);
    }

    cout << cnt << endl;

}
