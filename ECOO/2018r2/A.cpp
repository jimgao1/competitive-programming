
#include <bits/stdc++.h>

using namespace std;

int C, O, W, S;
int lc, lo, lw, ls;
int fc, fo, fw, fs;

int dfs(int c, int o, int w, int s) {
    int ans = o;
    if (c >= lc && w >= lw) ans = max(ans, dfs(c - lc, o + lo, w - lw, s + ls));
    if (s >= fs && o >= fo) ans = max(ans, dfs(c + fc, o - fo, w + fw, s - fs));

    return ans;
}

void solve() {
    cin >> C >> O >> W >> S;
    cin >> lc >> lw >> ls >> lo;
    cin >> fs >> fo >> fc >> fw;

//    int ans = 0;
//
//    for (int i = 0; i < 10000; i++) {
//        for (int j = 0; j < 10000; j++) {
//            int nc = C - lc * i + fc * j;
//            int no = O + lo * i - fo * j;
//            int nw = W - lw * i + fw * j;
//            int ns = S + ls * i - fs * j;
//
//            if (nc >= 0 && no >= 0 && nw >= 0 && ns >= 0) {
//                ans = max(ans, no);
//            }
//        }
//    }

    cout << dfs(C, O, W, S) << endl;
}

int main() {
    freopen("/home/jim/ecoo/DATA12.txt", "r", stdin);

    int T = 10;
    while (T--) {
//        init();
        solve();
    }
}
