
#include <bits/stdc++.h>

using namespace std;

string digit(char c){
    if (c == 'A' || c == 'B' || c == 'C') return "2";
    if (c == 'D' || c == 'E' || c == 'F') return "3";
    if (c == 'G' || c == 'H' || c == 'I') return "4";
    if (c == 'J' || c == 'K' || c == 'L') return "5";
    if (c == 'M' || c == 'N' || c == 'O') return "6";
    if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') return "7";
    if (c == 'T' || c == 'U' || c == 'V') return "8";
    if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z') return "9";
}

int N;

int main(){
    cin >> N;
    while(N--){
        string str;
        cin >> str;

        string result = "";
        for (int i = 0; i < str.size(); i++){
            if (result.size() == 10) break;

            if (str[i] >= 'A' && str[i] <= 'Z'){
                result += digit(str[i]);
            } else if (str[i] >= '0' && str[i] <= 'Z') {
                result += str[i];
            }
        }

        cout << result[0] << result[1] << result[2] << "-";
        cout << result[3] << result[4] << result[5] << "-";
        cout << result[6] << result[7] << result[8] << result[9] << endl;
    }
}
