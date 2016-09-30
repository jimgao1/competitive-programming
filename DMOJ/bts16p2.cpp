#include <bits/stdc++.h>

using namespace std;

int N;
bool t, f;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        int c;
        string b;
        cin >> c;

        if (c == 1){
            cin >> b;
            if (b == "true"){
                if (!t){
                    t = true;
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            } else {
                if (!f){
                    f = true;
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            }
        } else if (c == 2){
            cin >> b;
            if (b == "true"){
                if (t){
                    t = false;
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            } else {
                if (f){
                    f = false;
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
            }
        } else if (c == 3){
            cin >> b;
            if (b == "true"){
                if (t){
                    if (f) {
                        cout << "1" << endl;
                    } else {
                        cout << "0" << endl;
                    }
                } else {
                    cout << "-1" << endl;
                }
            } else {
                if (f){
                    cout << "0"  << endl;
                } else {
                    cout << "-1" << endl;
                }
            }
        } else if (c == 4){
            if (f) cout << "false";
            if (f && t) cout << " ";
            if (t) cout << "true";
            cout << endl;
        }
    }
}
