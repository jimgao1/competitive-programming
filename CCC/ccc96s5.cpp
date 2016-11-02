

#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> a, b;

int main(){
    cin >> T;
    while(T--){
        a.clear();
        b.clear();
        cin >> N;
        for (int i = 0, x; i < N; i++){
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0, x; i < N; i++){
            cin >> x;
            b.push_back(x);
        }

        int ans = 0;
        for (int i = 0; i < N; i++){
            int low = i, high = N - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if (b[mid] < a[i]){
                    high = mid - 1;
                } else {
                    ans = max(ans, mid - i);
                    low = mid + 1;
                }
            }
        }

        printf("The maximum distance is %d\n", ans);
    }
}

