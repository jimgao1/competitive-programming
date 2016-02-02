#include <bits/stdc++.h>

using namespace std;

double C;

int main(){
    cin >> C;
    double r = ceil(log2(C / 2.0) * 2 * 365);
    //cout << r << endl;

    if (r == 0){
        cout << "Now!" << endl;
        return 0;
    }

    if ((int)(r / 365) != 0){
        printf("%dY", (int)(r / 365));
        r = r - 365 * (int)(r / 365);
    }

    if ((int)(r / 30) != 0){
        printf(" %dM", (int)(r / 30));
        r = r - 30 * (int)(r / 30);
    }

    if ((int)(r / 7) != 0){
        printf(" %dW", (int)(r / 7));
        r = r - 7 * (int)(r / 7);
    }

    if (r != 0){
        printf(" %dD", (int)(r));
    }

    printf("\n");
}
