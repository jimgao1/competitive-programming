#include <bits/stdc++.h>

using namespace std;

long long K;
int ans = 0;
string N;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    cin >> K >> N;

    for (char c : N) {
        pq.push(c - '0');
        K -= (c - '0');
    }

    while(!pq.empty() && K > 0){
        int cur = pq.top();
        pq.pop();

        K -= (9 - cur);
        ans++;
    }

    cout << ans << endl;
}
