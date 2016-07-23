
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N;
unordered_map<string, int> mem;
string str;

string h(int idx, int ca, int cb, int cc){
    stringstream ss;
    ss << idx << ca << cb << cc;
    return ss.str();
}

int f(int idx, int ca, int cb, int cc){
    if (mem.find(h(idx, ca, cb, cc)) != mem.end())
        return mem[h(idx, ca, cb, cc)];

    int res = 0;
    if (idx == N){
        int m = min(ca, min(cb, cc));
        if (ca == m) res = res | 1;
        if (cb == m) res = res | 2;
        if (cc == m) res = res | 4;

    } else {
        if (str[idx] == '~'){
            int m = min(ca, min(cb, cc));

            if (ca == m) res |= f(idx + 1, ca + 1, cb, cc);
            if (cb == m) res |= f(idx + 1, ca, cb + 1, cc);
            if (cc == m) res |= f(idx + 1, ca, cb, cc + 1);

        } else {
            if (str[idx] == '1')
                res |= f(idx + 1, ca + 1, cb, cc);
            else if (str[idx] == '2')
                res |= f(idx + 1, ca, cb + 1, cc);
            else if (str[idx] == '3')
                res |= f(idx + 1, ca, cb, cc + 1);
        }
    }

    mem[h(idx, ca, cb, cc)] = res;
    return res;
}

int main(){
    cin >> N >> str;

    int ans = f(0, 0, 0, 0);

    if (ans & 1) cout << 1 << endl;
    if (ans & 2) cout << 2 << endl;
    if (ans & 4) cout << 3 << endl;
}
