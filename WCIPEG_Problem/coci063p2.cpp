
#include <bits/stdc++.h>

using namespace std;

int main(){
    string input;

    for (int i=0; i<4; i++){
        string s;
        cin >> s;

        input += s;
    }

    int diff = 0;

    for (int i=0; i<16; i++){
        if (input[i] == '.') continue;

        int num = input[i] - 'A';

        int sX = num / 4, sY = num % 4;
        int aX = i / 4, aY = i % 4;

        diff += abs(aX - sX) + abs(aY - sY);
    }

    cout << diff << endl;

    system("pause");
    return 0;
}
