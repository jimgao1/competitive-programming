
#include <bits/stdc++.h>

#define MAXN 11

using namespace std;

string name;
bool S[MAXN][MAXN], C[MAXN][MAXN];

void press(int r, int c) {
    C[r][c] = !C[r][c];
    if (r - 1 >= 0) C[r - 1][c] = !C[r - 1][c];
    if (r + 1 < 10) C[r + 1][c] = !C[r + 1][c];
    if (c - 1 >= 0) C[r][c - 1] = !C[r][c - 1];
    if (c + 1 < 10) C[r][c + 1] = !C[r][c + 1];
}

void solve() {
    memset(S, 0, sizeof S);
    for (int i = 0; i < 10; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 10; j++) {
            if (str[j] == 'O') S[i][j] = 1;
        }
    }

    int ans = 1e9;

    for (int i = 0; i < (1 << 10); i++) {
        memcpy(C, S, sizeof S);

        int clicks = 0;

        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                clicks++;
                press(0, j);
            }
        }

        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 10; k++) {
                if (C[j][k]) {
                    press(j + 1, k);
                    clicks++;
                }
            }
        }

        bool valid = true;
        for (int j = 0; j < 10; j++) {
            if (C[9][j]) {
                valid = false;
                break;
            }
        }

        if (valid) ans = min(ans, clicks);
    }

    cout << name << " " << ans << endl;
}

int main() {
    while (true) {
        cin >> name;
        if (name == "end") break;
        solve();
    }
}

