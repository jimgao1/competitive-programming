
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, K;
bool covered[MAXN];
vector<int> houses;

bool test(int gap){
    int first = houses[0] + gap, last = houses[0] + gap, cnt = 1;
    for (int i = 1; i < houses.size(); i++){
        if (abs(houses[i] - last) > gap && abs(houses[i] - first) > gap){
            cnt++;
            last = houses[i] + gap;
        }
    }

    return cnt <= K;
}

int main(){
    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        houses.push_back(x);
    }
    cin >> K;

    sort(houses.begin(), houses.end());

    int low = 0, high = 1e6, ans = 1e6;
    while(low <= high){
        int mid = (low + high) / 2;
        if (test(mid)){
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}
