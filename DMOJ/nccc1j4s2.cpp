#include <bits/stdc++.h>

#define MAXN 37
#define ll long long

using namespace std;

int N, A[MAXN][MAXN];
bool tmp[MAXN];

int parse(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

bool checkRow(int r) {
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < N; i++) {
        if (tmp[A[r][i]]) return false;
        tmp[A[r][i]] = 1;
    }
    return true;
}

bool checkCol(int r) {
    memset(tmp, 0, sizeof tmp);
    for (int i = 0; i < N; i++) {
        if (tmp[A[i][r]]) return false;
        tmp[A[i][r]] = 1;
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            A[i][j] = parse(str[j]);
        }
    }

    bool valid = true;
    for (int i = 0; i < N; valid &= checkRow(i) & checkCol(i++));

    if (valid) {
        bool v2 = true;
        for (int i = 0; i < N - 1; v2 &= A[0][i] < A[0][(i++) + 1]);
        for (int i = 0; i < N - 1; v2 &= A[i][0] < A[(i++) + 1][0]);

        if (v2) {
            cout << "Reduced" << endl;
        } else {
            cout << "Latin" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}
