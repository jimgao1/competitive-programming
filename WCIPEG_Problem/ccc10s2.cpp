
#include <bits/stdc++.h>

using namespace std;

int N;
string str;
map<string, char> huffman;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        char c;
        string code;
        cin >> c >> code;

        huffman[code] = c;
    }
    cin >> str;
    string tmp = "", result = "";

    for (int i = 0; i < str.size(); i++){
        tmp += str[i];
        if (huffman[tmp] != 0){
            result += huffman[tmp];
            tmp = "";
        }
    }

    if (tmp.size() > 0) result += huffman[tmp];

    cout << result << endl;
}
