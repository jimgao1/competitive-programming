
#include <bits/stdc++.h>

using namespace std;

int x[26], y[26];

int main() {
    string A, B;
    while (getline(cin, A)) {
        getline(cin, B);
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        for (int i = 0; i < A.length(); i++) x[A[i] - 'a']++;
        for (int i = 0; i < B.length(); i++) y[B[i] - 'a']++;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < min(x[i], y[i]); j++)
                printf("%c", 'a' + i);
        }
        printf("\n");
    }
}
