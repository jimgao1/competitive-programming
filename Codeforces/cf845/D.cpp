#include <bits/stdc++.h>

using namespace std;

int N, ans = 0, overtake = 0, pspeed, plimit = 1000;
stack<int> signs;

int main() {
    cin >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            pspeed = b;
            while (!signs.empty()) {
                if (signs.top() < b) {
                    //printf("ignoring %d\n", signs.top());
                    ans++;
                    signs.pop();
                } else {
                    break;
                }
            }
        } else if (a == 2) {
            if (overtake > 0) {
                ans += overtake;
                overtake = 0;
            }
        } else if (a == 3) {
            cin >> b;
            signs.push(b);

            while (!signs.empty()) {
                if (signs.top() < pspeed) {
                    ans++;
                    signs.pop();
                } else {
                    break;
                }
            }
        } else if (a == 4) {
            overtake = 0;
        } else if (a == 5) {
            while (!signs.empty())
                signs.pop();
        } else {
            overtake++;
        }
    }

    cout << ans << endl;
}
