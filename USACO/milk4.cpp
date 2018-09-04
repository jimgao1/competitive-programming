/*
ID: jim_yub1
LANG: C++11
TASK: milk4
*/

#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int Q, P, ans, A[MAXN];
bool used[MAXN], tmp[20004];

bool verify() {
    memset(tmp, 0, sizeof tmp);

    tmp[0] = true;
    for (int i = 0; i < P; i++) {
        if (used[i]) {
            for (int j = A[i]; j <= Q; j++) {
                tmp[j] |= tmp[j - A[i]];
            }
        }
    }

    return tmp[Q];
}

bool dfs(int id, int depth) {


    if (depth == 0) {
        if (verify()) {
            printf("%d", ans);
            for (int i = 0; i < P; i++)
                if (used[i])
                    printf(" %d", A[i]);
            printf("\n");

            return true;
        }

        return false;
    }

    if (id >= P) return false;

    used[id] = true;
    if (dfs(id + 1, depth - 1)) return true;
    used[id] = false;

    return dfs(id + 1, depth);
}

int main() {
    freopen("milk4.in", "r", stdin);
    freopen("milk4.out", "w", stdout);

    cin >> Q >> P;
    for (int i = 0; i < P; i++) cin >> A[i];

    sort(A, A + P);

    for (int depth = 1; depth <= P; depth++)
        if (dfs(0, ans = depth))
            break;
}
