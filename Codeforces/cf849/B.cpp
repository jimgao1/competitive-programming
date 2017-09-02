#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N;
double Y[MAXN];
bool done[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> Y[i];

    // Connect point 0 with i
    for (int i = 1; i < N; i++) {
        memset(done, 0, sizeof done);
        double m = (Y[i] - Y[0]) / (i);

        for (int j = 1; j < N; j++) {
            if (Y[0] + j * m == Y[j]) {
                done[j] = true;
            }
        }

        // Find first unmatched point
        int x = -1;
        for (int j = 1; j < N; j++) {
            if (!done[j]) {
                x = j;
                break;
            }
        }

        if (x == -1) {
            continue;
        }

        for (int j = 1; j < N; j++) {
            if (!done[j] && Y[x] + (j - x) * m == Y[j]) {
                done[j] = true;
            }
        }

        bool tmp = true;
        for (int j = 1; j < N; j++) {
            if (!done[j]) tmp = false;
        }

        if (tmp) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    // Leave the first point
    memset(done, 0, sizeof done);
    bool tmp = true;
    double m = Y[2] - Y[1];
    for (int i = 2; i < N; i++) {
        if (Y[1] + m * (i - 1) != Y[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    // Node 0 cannot fall on that line
    if (Y[0] + m == Y[1]){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

}
