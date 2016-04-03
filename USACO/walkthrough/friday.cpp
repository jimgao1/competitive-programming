/*
ID: jim3
PROG: friday
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int N, week[7], cur = 1;

int isLeap(int year){
    if (year % 100 == 0)
        return (year % 400) == 0;
    return year % 4 == 0;
}

int main(){
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    cin >> N;

    for (int year = 1900; year < 1900 + N; year++){
        for (int month = 0; month < 12; month++){
            int t = days[month];
            if (isLeap(year))
                t = leap[month];

            for (int d = 0; d < t; d++){
                if (d == 13){
                    week[cur] ++;
                }
                cur = (cur + 1) % 7;
            }
        }
    }

    for (int i = 0; i < 7; i++){
        printf("%d", week[i]);
        if (i != 6) printf(" ");
    }
    printf("\n");       //for fucks sake usaco
    
    //fuck you usaco
    
}

