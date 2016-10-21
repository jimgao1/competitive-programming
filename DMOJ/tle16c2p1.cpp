
#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    int a = 0, b = 0;
    cin >> N;

    int cur = 0;
    for (int i = 0; i < N; i++){
        string cmd;
        int val;

        cin >> cmd >> val;

        if (cmd == "borrow"){
            cur -= val;
        } else {
            cur += val;
        }

        if (-cur > a){
            a = -cur;
            b = i + 1;
        }
    }

    cout << b << endl;
}

