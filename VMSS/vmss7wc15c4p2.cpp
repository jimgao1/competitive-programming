
#include <bits/stdc++.h>

using namespace std;

char shift(char c, int k){
    c -= k;
    while(c < 'A')
        c += 26;
    return c;
}

int K;
string str, result = "";

int main(){
    cin >> K >> str;

    for (int i = 0; i < str.size(); i++){
        result += shift(str[i], (i + 1) * 3 + K);
    }

    cout << result << endl;
}
