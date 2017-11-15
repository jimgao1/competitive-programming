#include <bits/stdc++.h>

using namespace std;

double D;
pair<double, double> A, B, S;

double dist(pair<double, double> a, pair<double, double> b) {
    double dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> S.first >> S.second;
    cin >> D;

    if (hypot(A.first - S.first, A.second - S.second) <= D ||
            hypot(B.first - S.first, B.second - S.second) <= D) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
