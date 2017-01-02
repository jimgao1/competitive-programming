#include <bits/stdc++.h>

using namespace std;

int N;
map<int, int> dict;
vector<pair<int, int>> nums;

int main(){
    cin >> N;
    int s = 0, e = 1;

    for (int i = 0; i < N; i++){
        char c; int x;
        cin >> c >> x;
        if (c == 'F'){
            dict[x] = s;
            s--;
        } else if (c == 'E'){
            dict[x] = e;
            e++;
        } else {
            dict[x] = -1e9;
        }
    }

    for (pair<int, int> i : dict){
        if (i.second != -1e9){
            nums.push_back({i.second, i.first});
        }
    }

    sort(nums.begin(), nums.end());
    for (pair<int, int> i : nums){
        cout << i.second << endl;
    }
}
