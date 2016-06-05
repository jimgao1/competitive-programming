
#include <bits/stdc++.h>

using namespace std;

int T, N;
deque<int> dq, dq2;

bool test(bool b){
    dq = dq2;
    int A = 0, B = 0;
    if (b){
        A = B = dq.front();
        dq.pop_front();
    } else {
        A = B = dq.back();
        dq.pop_back();
    }

    while(!dq.empty()){
        if (A - 1 == dq.front()){
            A -= 1;
            dq.pop_front();
        } else if (A - 1 == dq.back()){
            A -= 1;
            dq.pop_back();
        } else if (B + 1 == dq.front()){
            B += 1;
            dq.pop_front();
        } else if (B + 1 == dq.back()){
            B += 1;
            dq.pop_back();
        } else {
            return false;
        }
    }

    return A == 1 && B == N;
}

int main(){
    freopen("lazy.in", "r", stdin);

    cin >> T;
    for (int i = 0; i < T; i++){
        dq.clear();
        dq2.clear();

        cin >> N;
        for (int j = 0, x; j < N; j++){
            cin >> x;
            dq.push_back(x);
            dq2.push_back(x);
        }

        cout << "Case #" << (i + 1) << ": " << ((test(true) || test(false)) ? "yes" : "no") << endl;
    }
}
