
#include <bits/stdc++.h>

#define MAXN 10

using namespace std;

struct team{
    string name;
    int p = 0, f = 0, g = 0;
};

bool cmp(team a, team b){
    int sa = a.p + a.f + a.g;
    int sb = b.p + b.f + b.g;
    if (sa != sb) return sa > sb;
    if (a.g != b.g) return a.g > b.g;
    if (a.f != b.f) return a.f > b.f;
    return a.p > b.p;
}

bool eq(team a, team b){
    if (a.f != b.f) return false;
    if (a.p != b.p) return false;
    if (a.g != b.g) return false;
    return true;
}

int N;
vector<team> teams;

void doit(){
    teams.clear();

    cin >> N;
    string curTeam;
    cin >> curTeam;

    for (int i = 0; i < N; i++){
        team t;
        t.name = curTeam;
        while(true){
            string j; int a, b, c;
            cin >> j;

            if (j == "*") break;
            if (j == "J"){
                cin >> a >> b >> c;
                t.p += a;
                t.f += b;
                t.g += c;
            } else {
                curTeam = j;
                break;
            }
        }
        teams.push_back(t);
    }

    sort(teams.begin(), teams.end(), cmp);

    for (int i = 0; i < N; i++){
        if (!eq(teams[i], teams[0])) break;
        if (i != 0) cout << ",";
        cout << teams[i].name;
    }
    cout << endl;
}

int main(){
    int T = 10;
    while(T--) doit();
}

