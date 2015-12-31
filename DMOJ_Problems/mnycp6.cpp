#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int mass(string str){
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
        ans += (str[i] - 'a' + 1);
    return ans;
}

int C, cnt = 1, bit[10010];
set<string> exists;
unordered_map<string, int> location;

void add(int i, int val){
    //cout << "add " << i << " " << val << endl;

    while(i <= 10010){
        bit[i] += val;
        i += (-i & i);
    }
}

int query(int i){
    //cout << "query " << i << endl;

    int sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }

    return sum;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> C;
    while(C--){
        char cmd;
        string a, b;
        cin >> cmd;

        if (cmd == 'A'){
            cin >> a;

            if (location[a] != 0){
                cout << "Can't add " << a << endl;
            } else {
                location[a] = cnt;
                add(location[a], mass(a));
    
                cnt++;
            }
        } else if (cmd == 'S'){
            cin >> a >> b;

            int diff = mass(b) - mass(a);
            add(location[a], diff);
            add(location[b], -diff);

            int temp = location[a];
            location[a] = location[b];
            location[b] = temp;
        } else if (cmd == 'M'){
            cin >> a >> b;

            int na = location[a], nb = location[b];
            if (nb < na) swap(na, nb);

            if (na == 1)
                cout << query(nb) << endl;
            else
                cout << query(nb) - query(na - 1) << endl;
        } else if (cmd == 'R'){
            cin >> a >> b;

            int diff = mass(b) - mass(a);
            add(location[a], diff);

            location[b] = location[a];
            location[a] = 0;
            
        } else if (cmd == 'N'){
            cout << cnt - 1 << endl;
        }
    }
}
