#include <bits/stdc++.h>

using namespace std;

int N;
bool matrix[10][10];
vector<int> perm;
vector<pair<int, int>> pp;

int main(){
    pp.push_back({1, 2});
    pp.push_back({1, 3});
    pp.push_back({1, 5});
    pp.push_back({2, 4});
    pp.push_back({2, 6});
    pp.push_back({3, 4});
    pp.push_back({3, 7});
    pp.push_back({4, 8});
    pp.push_back({5, 6});
    pp.push_back({5, 7});
    pp.push_back({6, 8});
    pp.push_back({7, 8});

    cin >> N;
    for (int i = 1; i <= 8; i++) perm.push_back(i);
    for (int i = 0, a, b; i < N; i++){
        cin >> a >> b;
        matrix[a][b] = matrix[b][a] = true;
    }
    sort(perm.begin(), perm.end());

    do{
        bool valid = true;
        for (pair<int, int> ii : pp){
            int a = perm[ii.first - 1], b = perm[ii.second - 1];
            if (!matrix[a][b]) valid = false;
        }
        if (valid){
            cout << "Ja" << endl;
            return 0;
        }
    } while(next_permutation(perm.begin(), perm.end()));

    cout << "Nej" << endl;

}
