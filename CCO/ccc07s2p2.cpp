
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N, len[6], cnt = 0;
set<string> str;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        int idx = -1, max = -1;
        for (int j = 0; j < 6; j++) {
            cin >> len[j];
            if (len[j] > max){
                max = len[j];
                idx = j;
            }
        }

        string str1 = "", str2 = "";

        for (int j = 0; j < 6; j++)
            str1 += to_string(len[(idx + j) % 6]);

        for (int j = 0; j < 6; j++)
            str2 += to_string(len[(idx - j + 6) % 6]);

        if (len[(idx + 1) % 6] >= len[(idx + 5) % 6])
            str.insert(str1);
        else
            str.insert(str2);
    }

    if (str.size() == N)
        cout << "No two snowflakes are alike." << endl;
    else
        cout << "Twin snowflakes found." << endl;
}
