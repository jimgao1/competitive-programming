#include <bits/stdc++.h>

using namespace std;

int main(){
    string text;
    getline(cin, text);

    int lower = 0, upper = 0;
    for (int i = 0; i < text.size(); i++){
        if (text[i] >= 'a' && text[i] <= 'z') lower++;
        if (text[i] >= 'A' && text[i] <= 'Z') upper++;
    }

    if (lower < upper){
        for (int i = 0; i < text.size(); i++){
            text[i] = toupper(text[i]);
        }
    } else if (lower > upper){
        for (int i = 0; i < text.size(); i++){
            text[i] = tolower(text[i]);
        }
    }

    cout << text << endl;
}
