#include <bits/stdc++.h>

using namespace std;

int h, r, sec;

int main(){
    cin >> h >> r >> sec;

    int t = h * 60 + r + sec;
    t = t % 1440;

    printf("%d %d\n", t / 60, t % 60);
}
