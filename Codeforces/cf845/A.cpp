#include <bits/stdc++.h>

#define MAXN 201

using namespace std;

int N;
vector<int> A;

int main() {
    cin >> N;
    for (int i = 0, x; i < 2 * N; i++) {
        cin >> x;
        A.push_back(x);
    }

    sort(A.begin(), A.end());

    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (A[N - i - 1] >= A[N + i])
            tmp++;
    }

    if (tmp == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
