#include <bits/stdc++.h>

using namespace std;

int N;
bool good[256];
string tmp, pattern, str;

bool test(int sidx, int pidx) {
    //printf("sidx = %d, pidx = %d\n", sidx, pidx);

    while (pattern[pidx] == str[sidx] && pidx < pattern.length() && sidx < str.length()) {
        pidx++;
        sidx++;
    }

    if (pidx == pattern.length() || sidx == str.length()){
        if (pidx == pattern.length() && sidx == str.length()) return true;
        return false;
    }

    if (islower(pattern[pidx])) return false;

    if (pattern[pidx] == '*') {
        for (int i = sidx; i < str.size(); i++) {
            if (!good[str[i]]) {
                if (test(i + 1, pidx + 1)) return true;
            } else {
                break;
            }
        }

        if (test(sidx, pidx + 1)) return true;
    } else {
        return good[str[sidx]] && test(sidx + 1, pidx + 1);
    }

    return false;
}

int main() {
    cin >> tmp;
    for (char c : tmp) good[c] = 1;

    cin >> pattern;
    cin >> N;

    pattern = pattern + "$";

    while (N--) {
        cin >> str;
        str = str + "$";
        cout << (test(0, 0) ? "YES" : "NO") << endl;
    }
}
