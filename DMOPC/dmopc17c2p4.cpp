#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MAXN 100005
#define MOD 100000000007ULL
#define EXP 31ULL

using namespace std;

string str;

bool palindrome(int idx) {
    for (int i = 0; i < idx; i++) {
        if (str[i] != str[idx - i - 1])
            return false;
    }
    return true;
}

bool check_occur(int idx) {
    ull curHash = 0;
    for (int i = 0; i < idx; i++) {
        curHash = (curHash * EXP) % MOD;
        curHash = (curHash + str[i] - 'a' + 1) % MOD;
    }
    ull initHash = curHash;

    ull fuck = 1;
    for (int i = 0; i < idx - 1; i++) fuck = (fuck * EXP) % MOD;

    for (int i = 1; i + idx <= str.length(); i++) {
        curHash = (curHash - (fuck * (str[i - 1] - 'a' + 1)) % MOD + MOD) % MOD;
        curHash = (curHash * EXP) % MOD;
        curHash = (curHash + str[i + idx - 1] - 'a' + 1) % MOD;
        if (curHash == initHash) return true;
    }

    return false;
}

int main() {
    cin >> str;

    for (int i = str.length() - 1; i >= 1; i--) {
        if (palindrome(i) && check_occur(i)){
            cout << i << endl;
            return 0;
        }
    }

    cout << "0" << endl;
}
