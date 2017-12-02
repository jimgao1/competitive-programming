
#include <bits/stdc++.h>

#define MAXN 2000006
#define ll long long

using namespace std;

int N;
ll A[10], a[MAXN], total = 1, adj = 1, cur_dim = 1, num[MAXN], num2[MAXN];

void calc() {
    memset(num2, 0, sizeof num2);
    for (int i = 0; i < total; i++) {
        num2[i] = num[i];
        if (i - adj >= 0 && (i - adj) / cur_dim == i / cur_dim) {
            num2[i] += num[i - adj];
        }

        if (i + adj < total && (i + adj) / cur_dim == i / cur_dim) {
            num2[i] += num[i + adj];
        }
    }

    for (int i = 0; i < total; i++) num[i] = num2[i];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total *= A[i];
    }

    for (int i = 0; i < total; i++) {
        cin >> num[i];
        a[i] = num[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        cur_dim *= A[i];
        calc();
        adj *= A[i];
    }

    for (int i = 0; i < total; i++) {
        cout << num[i] - a[i] << "\n";
    }
}
