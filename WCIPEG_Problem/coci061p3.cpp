
#include <bits/stdc++.h>

using namespace std;

string text;

int main(){
    cin >> text;

    cout << ".";
    for (int i = 0; i < text.length(); i++){
        if ((i + 1) % 3 != 0)
            cout << ".#..";
        else
            cout << ".*..";
    }
    cout << endl;

    cout << ".";
    for (int i = 0; i < text.length(); i++){
        if ((i + 1) % 3 != 0)
            cout << "#.#.";
        else
            cout << "*.*.";
    }
    cout << endl;


    for (int i = 0; i < text.length(); i++){
        if ((i + 1) % 3 != 0)
            if (i % 3 == 0 && i >= 3)
                cout << "*." << text[i] << ".";
            else
                cout << "#." << text[i] << ".";
        else
            cout << "*." << text[i] << ".";
    }
    cout << (text.size() % 3 == 0 ? "*" : "#") << endl;

    cout << ".";
    for (int i = 0; i < text.length(); i++){
        if ((i + 1) % 3 != 0)
            cout << "#.#.";
        else
            cout << "*.*.";
    }
    cout << endl;

    cout << ".";
    for (int i = 0; i < text.length(); i++){
        if ((i + 1) % 3 != 0)
            cout << ".#..";
        else
            cout << ".*..";
    }
    cout << endl;
}
