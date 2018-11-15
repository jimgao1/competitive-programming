
#include <bits/stdc++.h>

using namespace std;

int B[12];

struct state {
    int A[12];

    // Move [pos1, pos1+len) to [pos2, pos2+len)
    void move(int pos1, int pos2, int len) {
        memcpy(B, A, sizeof A);
        int a = min(pos1, pos2), b = max(pos1, pos2);
        for (int i = pos2; i < pos2 + len; i++) A[i] = B[pos1 - pos2 + i];
        for (int i = 0; i < b - a; i++) A[a + i] = B[a + len + i];
    }
};

int N, maxDep;

int calcH(state& s) {
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (s.A[i + 1] != s.A[i] + 1)
            cnt++;
    }
    return cnt;
}

bool calc(state s, int dep) {
    if (dep == maxDep) return calcH(s) == 0;

    int H = calcH(s);
    if (3 * dep + H > 3 * maxDep) return false;

    for (int i = 0; i < N; i++) {
        for (int len = 0; i + len <= N; len++) {
            for (int j = 0; j + len <= N; j++) {
                state n;
                for (int k = 0; k < N; k++) n.A[k] = s.A[k];
                n.move(i, j, len);

                if (calc(n, dep + 1)) return true;
            }
        }
    }

    return false;
}

void solve() {
    state init;

    for (int i = 0; i < N; i++) cin >> init.A[i];

    for (maxDep = 0; maxDep <= 4; maxDep++) {
        if (calc(init, 0)) {
            printf("%d\n", maxDep);
            return;
        }
    }

    // I know this is sketchy, but oh well :/
    printf("%d\n", 5);
}

int main() {
    for (int i = 1; ; i++){
        cin >> N;
        if (N == 0) break;

        printf("Case %d: ", i);
        solve();
    }
}
