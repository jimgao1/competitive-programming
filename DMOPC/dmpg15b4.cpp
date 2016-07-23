

//im stupid
//   ^ not actually

#include <bits/stdc++.h>

using namespace std;

int N, prod = 1, m = -0x3f3f3f3f, zero = 0;
vector<int> neg, pos;

int main(){
    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        if (x > 0){
            pos.push_back(x);
            prod *= x;
        } else if (x < 0) {
            neg.push_back(x);
        } else {
            zero++;
        }

        m = max(m, x);
    }

    if (zero == N){
        cout << 0 << endl;
    } else {
        sort(neg.begin(), neg.end());
        if (neg.size() % 2 == 0){
            for (int n : neg) prod *= n;
        } else {
            neg.erase(neg.end() - 1);
            for (int n : neg) prod *= n;
        }

        if (prod == 1)
            cout << m << endl;
        else
            cout << prod << endl;
    }

}
