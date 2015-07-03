
#include <bits/stdc++.h>

using namespace std;

int T, N;

set<string> names;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--){
        cin >> N;
        //FUCK THIS SHIT I FORGOT TO RESET
        names.clear();

        for (int i = 0; i < N; i++){
            string cur;
            cin >> cur;

            if (names.find(cur) == names.end()){
                names.insert(cur);
            }
        }

        for (set<string>::iterator i = names.begin(); i != names.end(); i++)
            cout << *i << "\n";
    }
}
