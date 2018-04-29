
#include <bits/stdc++.h>

#define pii pair<int, long double>


using namespace std;

int N;
vector<pii > A;
priority_queue<long double, vector<long double>, greater<long double>> q;

void init() {
    A.clear();
    while (!q.empty()) q.pop();
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int day;
        long double weight;
        cin >> day >> weight;
        A.push_back(make_pair(day, weight));
    }

    sort(A.begin(), A.end(), [](pii a, pii b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    int curDay = 0;
    long double total = 0, t2 = 0;

    for (pii cur : A) {
//        printf("due = %d, weight = %.2f\n", cur.first, cur.second);

        if (cur.first <= curDay) {
            if (!q.empty() && cur.second > q.top()) {
//                printf("popping min: %.2f\n", q.top());
                total = total - q.top() + cur.second;
                q.pop();
                q.push(cur.second);

//                curDay++;
            }
        } else {
//            printf("pushing\n");
            q.push(cur.second);
            total += cur.second;
            curDay++;
        }

        t2 += cur.second;
    }

//    printf("%.4lf\n", total);
//    cout << "fuck" << t2 << endl;
    cout << fixed << setprecision(4) << total << endl;
}

int main() {

    int T = 10;
    while (T--) {
        init();
        solve();
    }
}
