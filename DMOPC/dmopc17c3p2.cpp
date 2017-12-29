
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int N, A[MAXN], B[MAXN];
vector<int> op;

void toggle(int idx) {
    B[idx] = 1 - B[idx];
    B[idx + 1] = 1 - B[idx + 1];
    B[idx + 2] = 1 - B[idx + 2];
}

bool calc() {
    for (int i = 0; i < N - 1; i++) {
        if (B[i]) {
            toggle(i);
            op.push_back(i + 1);
        }
    }

    return !B[N - 1];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    memcpy(B, A, sizeof A);
    op.push_back(0);
    B[0] = 1 - B[0];
    B[1] = 1 - B[1];

    if (!calc()) {
        memcpy(B, A, sizeof A);
        op.clear();
        calc();
    }

    cout << op.size() << endl;
    for (int i : op) printf("%d\n", i + 1);
}
