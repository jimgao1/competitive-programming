#include <bits/stdc++.h>

#define MAXN 1000001
#define ll long long

using namespace std;

int N, Q, nums[MAXN];
ll ans[MAXN];
stack<pair<int, int>> st;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> nums[i];

    st.push(make_pair(-1, 0));
    for (int i = 1; i <= N; i++){
        while(st.top().first > nums[i]){
            int p0 = st.top().second, h0 = st.top().first;
            st.pop();

            int r = i - p0, l = p0 - st.top().second;
            ans[h0] += (ll)(r) * l;
        }
        st.push(make_pair(nums[i], i));
    }

    while(st.size() > 1){
        int p0 = st.top().second, h0 = st.top().first;
        st.pop();

        int r = N + 1 - p0, l = p0 - st.top().second;
        ans[h0] += (ll)(r) * l;
    }

    for (int i = 1; i < MAXN; i++)
        ans[i] += ans[i - 1];

    while(Q--){
        int a, b;
        cin >> a >> b;

        cout << ans[b] - ans[a - 1] << "\n";
    }
}
