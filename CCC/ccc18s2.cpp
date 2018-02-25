#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, A[MAXN][MAXN], tmp[MAXN][MAXN];

void rotate() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[N - j - 1][i] = A[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = tmp[i][j];
        }
    }
}

bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (A[i][j] >= A[i][j + 1])
                return false;
        }
    }

    for (int i = 0; i < N - 1; i++)
        if (A[i][0] >= A[i + 1][0])
            return false;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i][0] < A[j][0]) {
                for (int k = 0; k < N; k++) {
                    if (A[i][k] >= A[j][k])
                        return false;
                }
            }
        }
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    for (int k = 0; k < 4; k++) {
        if (check()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j > 0) printf(" ");
                    printf("%d", A[i][j]);
                }
                printf("\n");
            }
            break;
        }

        rotate();
    }
}
