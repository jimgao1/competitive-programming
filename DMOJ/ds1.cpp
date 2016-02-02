#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

long long numbers, query, num[100001], sum1[100001], sum2[100001];

void add(long long* bit, int i, int val){
    while(i <= 100001){
        bit[i] += val;
        i += (-i & i);
    }
}

long long sum(long long* bit, int i){
    long long sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }

    return sum;
}

int main(){
    //freopen("output.txt", "w", stdout);

    cin.sync_with_stdio(false);
    cin.tie(false);

    cin >> numbers >> query;

    for (int i = 1; i <= numbers; i++){
        cin >> num[i];
        add(sum1, i, num[i]);
        add(sum2, num[i], 1);
    }

    for (int i = 0; i < query; i++){
        char cmd;
        cin >> cmd;

        int a, b;

        if (cmd == 'C'){
            cin >> a >> b;
            long long diff = b - num[a];

            add(sum1, a, diff);
            add(sum2, b, 1);
            add(sum2, num[a], -1);
            num[a] = b;
        } else if (cmd == 'S'){
            cin >> a >> b;
            cout << sum(sum1, b) - sum(sum1, a - 1) << endl;
        } else if (cmd == 'Q'){
            cin >> a;

            cout << sum(sum2, a) << endl;
        }
    }

    //system("notepad output.txt");

    return 0;
}
