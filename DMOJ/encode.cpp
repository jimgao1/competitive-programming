
#include <bits/stdc++.h>

using namespace std;

char shift(char c, int k){
    if (islower(c)){
        c += k;
        if (c < 'a') c += 26;
    } else if (isupper(c)){
        c += k;
        if (c < 'A') c += 26;
    }
    return c;
}

int main(){
    string kk, str;
    getline(cin, kk);
    getline(cin, str);
    int k = atoi(kk.c_str());
    while(k < 0) k += 26;
    k = k % 26;
    for (char c : str){
        cout << shift(c, -k);
    }
    cout << endl;
}

