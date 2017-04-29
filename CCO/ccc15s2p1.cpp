
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
ll W;
vector<ll> temp;

ll findMax(bool left){
    ll last = W, ans = 0;
    deque<int> dq(temp.begin(), temp.end());

    while(!dq.empty()){
        if (left){
            ans += max(abs(last - dq.front()), abs(W - dq.front()));
            last = dq.front();
            dq.pop_front();
        } else {
            ans += max(abs(last - dq.back()), abs(W - dq.back()));
            last = dq.back();
            dq.pop_back();
        }

        left = !left;
    }

    return ans;
}

ll findMin(){
    int pos = lower_bound(temp.begin(), temp.end(), W) - temp.begin();

    ll last = W, ans = 0;
    for (int i = pos - 1; i >= 0; i--){
        ans += abs(temp[i] - last);
        last = temp[i];
    }

    last = W;
    for (int i = pos; i < N; i++){
        ans += abs(temp[i] - last);
        last = temp[i];
    }

    return ans;
}

int main(){
    cin >> N >> W;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        temp.push_back(x);
    }

    sort(temp.begin(), temp.end());

    printf("%lld %lld\n", findMin(), max(findMax(0), findMax(1)));
}
