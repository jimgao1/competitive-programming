#include <bits/stdc++.h>

using namespace std;

int sa = 0, sb = 0;
string str;
vector<int> A, B, S;

int main() {
    cin >> str;
    for (int i = 0; i < 3; i++) {
        A.push_back(str[i] - '0');
        sa += str[i] - '0';
    }
    for (int i = 3; i < 6; i++) {
        B.push_back(str[i] - '0');
        sb += str[i] - '0';
    }

    if (sa > sb) {
        swap(A, B);
        swap(sa, sb);
    }

    for (int i : A) S.push_back(9 - i);
    for (int i : B) S.push_back(i);
    sort(S.begin(), S.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < S.size() && sa < sb; i++) {
        ans++;
        sa += S[i];
    }

    cout << ans << endl;
}
