
#include <bits/stdc++.h>

#define MAXN 21

using namespace std;

int N, tmp[MAXN];
vector<int> A[2], aa, bb;
set<int> sum[2];
unordered_map<int, string> dist[2];

void calcSum(int id, int cur, int csum) {
    if (cur == A[id].size()) {
        sum[id].insert(csum);
        stringstream ss;
        for (int i = 0; i < A[id].size(); i++) {
            ss << tmp[i];
        }
        if (ss.str() != "") dist[id][csum] = ss.str();
        return;
    }

    tmp[cur] = 0;
    calcSum(id, cur + 1, csum);

    tmp[cur] = 1;
    calcSum(id, cur + 1, csum + A[id][cur]);

    tmp[cur] = 2;
    calcSum(id, cur + 1, csum - A[id][cur]);
}

bool check(string s) {
    for (int i = 0; i < s.size(); i++) if (s[i] != '0') return true;
    return false;
}

int main() {
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        A[i & 1].push_back(x);
    }

    calcSum(0, 0, 0);
    calcSum(1, 0, 0);

    int ans = 1e9;
    string s1, s2;

    for (int csum : sum[0]) {
        int tar = -csum;
        set<int>::iterator it = sum[1].lower_bound(tar);
        if (it != sum[1].end() && abs((*it) + csum) < ans) {
            if (check(dist[0][csum]) || check(dist[1][*it])) {
                ans = abs((*it) + csum);
                s1 = dist[0][csum];
                s2 = dist[1][*it];
            }
        }

        --it;
        if (abs((*it) + csum) < ans) {
            if (check(dist[0][csum]) || check(dist[1][*it])) {
                ans = abs((*it) + csum);
                s1 = dist[0][csum];
                s2 = dist[1][*it];
            }
        }
    }

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '1') {
            aa.push_back(i * 2 + 1);
        } else if (s1[i] == '2') {
            bb.push_back(i * 2 + 1);
        }
    }

    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '1') {
            aa.push_back(i * 2 + 2);
        } else if (s2[i] == '2') {
            bb.push_back(i * 2 + 2);
        }
    }

    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());

//    printf("ans = %d\n", ans);
//    printf("s1 = %s\n", s1.c_str());
//    printf("s2 = %s\n", s2.c_str());
//
//    for (int i : A[0]) printf("%d ", i);
//    printf("\n");
//
//    for (int i : A[1]) printf("%d ", i);
//    printf("\n");
//
//    printf("Final answer:\n");

    for (int i : aa) printf("%d ", i);
    printf("\n");

    for (int i : bb) printf("%d ", i);
    printf("\n");
}
