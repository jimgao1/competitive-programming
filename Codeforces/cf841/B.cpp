#include <bits/stdc++.h>

using namespace std;
int N;
int main() {
    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        if (x % 2 == 1){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
}
