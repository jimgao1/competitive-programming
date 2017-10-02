
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int T, N, M, dset[MAXN];
double K, D;
bool A[MAXN];
vector<pair<int, int>> doctors, branch[MAXN];

double calcDist(pair<int, int> a, pair<int, int> b) {
    double dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

void uinit() {
    for (int i = 0; i < MAXN; i++) dset[i] = i;
}

int ufind(int n) {
    while (n != dset[n]) n = dset[n];
    return n;
}

void umerge(int a, int b) {
    dset[ufind(a)] = ufind(b);
}

void init() {
    uinit();
    memset(A, 0, sizeof A);
    doctors.clear();
    for (int i = 0; i < MAXN; i++) branch[i].clear();
}

void solve() {
    cin >> N >> M >> K >> D;
    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y;
        doctors.push_back(make_pair(x, y));
    }
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        for (int j = 0, a, b; j < x; j++) {
            cin >> a >> b;
            branch[i].push_back(make_pair(a, b));
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < branch[i].size(); j++) {
            for (pair<int, int> k : doctors) {
                if (calcDist(k, branch[i][j]) <= D) {
                    A[i] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            bool s = false;
            for (pair<int, int> a : branch[i]) {
                for (pair<int, int> b : branch[j]) {
                    if (calcDist(a, b) <= K) {
                        umerge(i, j);
                        s = true;
                        break;
                    }
                }
                if (s) break;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (A[i] && ufind(i) == ufind(0)){
            printf("Tree can be saved :)\n");
            return;
        }
    }

    if (A[0]){
        printf("Tree can be saved :)\n");
        return;
    }

    printf("Tree can't be saved :(\n");
}

int main() {
    cin >> T;
    while (T--) {
        init();
        solve();
    }
}
