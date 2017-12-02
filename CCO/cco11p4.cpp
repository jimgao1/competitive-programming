
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, cnt[MAXN];
map<int, int> dict;
set<int> emp;

int main(){
    cin >> N;

    int tmp;
    cin >> tmp;
    emp.insert(tmp);
    dict[-tmp] = 0;
    cnt[dict[-tmp]] = 0;


    for (int i = 1, x; i < N; i++){
        cin >> x;

        while(true){
            set<int>::iterator it = emp.upper_bound(-x);
            if (it == emp.end()){
                cout << "NO" << endl;
                return 0;
            }

            if (cnt[dict[*it]] == 2){
                emp.erase(it);
            } else {
                cnt[dict[*it]] ++;
                break;
            }
        }

        emp.insert(-x);
        dict[-x] = i;
    }

    cout << "YES" << endl;
}

