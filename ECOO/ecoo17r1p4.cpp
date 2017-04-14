
#include <bits/stdc++.h>

#define MAXN 2001

using namespace std;

int N, idx[MAXN];
vector<string> names;
unordered_map<string, int> srank;
priority_queue<int, vector<int>, greater<int>> pq;

void calcRank(){
    vector<string> fucks;
    for (string str : names) fucks.push_back(str);
    sort(fucks.begin(), fucks.end());
    for (int i = 0; i < fucks.size(); i++){
        srank[fucks[i]] = i;
    }
}

int calc(int exclude){
    vector<int> m;
    for (int i = 0; i < N; i++){
        if (i != exclude){
            m.push_back(srank[names[i]]);
        }
    }

    for (int i = 0; i < m.size(); i++){
        idx[m[i]] = i;
        pq.push(m[i]);
    }
    int cnt = 0;
    for (int i = 0; i < m.size() - 1; i++){
        if (pq.top() == m[i]) {
            pq.pop();
        } else {
            m[idx[pq.top()]] = m[i];
            idx[m[i]] = idx[pq.top()];
            pq.pop();
            cnt++;
        }
    }

    return cnt;
}

void doit(){
    names.clear();
    srank.clear();
    while(!pq.empty()) pq.pop();

    cin >> N;
    for (int i = 0; i < N; i++){
        string str; cin >> str;
        names.push_back(str);
    }

    calcRank();

    int ans = N;
    for (int i = 0; i < N; i++){
        ans = min(ans, calc(i));
    }

    cout << ans << endl;
}

int main(){
    int T = 10;
    while(T--) doit();
}

