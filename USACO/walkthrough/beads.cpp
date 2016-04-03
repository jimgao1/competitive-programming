/*
ID: jim3
PROG: beads
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
string neckless = "";

int main(){
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    cin >> N;
    while(!cin.eof()){
        string temp;
        cin >> temp;

        for (char c : temp)
            if (c == 'r' || c == 'w' || c == 'b')
                neckless += c;
    }

    for (int i = 0; i < N; i++){
        /*
            Current location: i

            Segment 1:
                i ... inf
            Segment 2:
                i - 1 ... -inf
        */

        //if (neckless[i] == 'w') continue;

        int cnt1 = 0, cnt2 = 0;
        int pos1 = i, pos2 = (i - 1 + N) % N;

        char col1 = neckless[pos1], col2 = neckless[pos2];

        while(true){
            if (cnt1 > N) break;

            if (col1 == neckless[pos1] || neckless[pos1] == 'w'){
                cnt1 ++;
                pos1 = (pos1 + 1) % N;
            } else if (col1 == 'w'){
                col1 = neckless[pos1];
                cnt1 ++;
                pos1 = (pos1 + 1) % N;
            } else {
                break;
            }
        }

        while(true){
            if (cnt2 > N) break;

            if (cnt2 > N) break;

            if (col2 == neckless[pos2] || neckless[pos2] == 'w'){
                cnt2 ++;
                pos2 = (pos2 - 1 + N) % N;
            } else if (col2 == 'w'){
                col2 = neckless[pos2];
                cnt2 ++;
                pos2 = (pos2 - 1 + N) % N;
            } else {
                break;
            }
        }

        //printf("i = %d, cnt1 = %d, cnt2 = %d\n", i, cnt1, cnt2);

        ans = max(ans, cnt1 + cnt2);
    }

    cout << min(N, ans) << endl;
}

