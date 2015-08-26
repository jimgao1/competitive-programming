
/*
	ID: jim.yub1
	LANG: C++11
	TASK: ratios
*/

/*
  _____ _              _____ _               _     _
 |_   _( )            / ____| |             (_)   | |
   | | |/ _ __ ___   | (___ | |_ _   _ _ __  _  __| |
   | |   | '_ ` _ \   \___ \| __| | | | '_ \| |/ _` |
  _| |_  | | | | | |  ____) | |_| |_| | |_) | | (_| |_
 |_____| |_| |_| |_| |_____/ \__|\__,_| .__/|_|\__,_(_)
                                      | |
                                      |_|
*/

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define FUCK_OFF -1

using namespace std;

int t[3], mix[3][3];

double checkTarget(int ra, int rb, int rc){
    double sa = mix[0][0] * ra + mix[1][0] * rb + mix[2][0] * rc;
    double sb = mix[0][1] * ra + mix[1][1] * rb + mix[2][1] * rc;
    double sc = mix[0][2] * ra + mix[1][2] * rb + mix[2][2] * rc;

    if ((sa == 0) != (t[0] == 0)) return -1;
    if ((sb == 0) != (t[1] == 0)) return -1;
    if ((sc == 0) != (t[2] == 0)) return -1;

    if (sa == 0){
        if (sb / t[1] == sc / t[2]) return sb / t[1];
        return FUCK_OFF;
    } else if (sb == 0){
        if (sa / t[0] == sc / t[2]) return sa / t[0];
        return FUCK_OFF;
    } else if (sc == 0){
        if (sa / t[0] == sb / t[1]) return sa / t[0];
        return FUCK_OFF;
    } else {
        if (sa / t[0] == sb / t[1] && sb / t[1] == sc / t[2])
            return sa / t[0];
        return FUCK_OFF;
    }

    return FUCK_OFF;

}

int main(){
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);


    for (int i = 0; i < 3; i++) scanf("%d", &t[i]);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) scanf("%d", &mix[i][j]);

    //cout << checkTarget(0, 38, 7) << endl;

    for (int c1 = 0; c1 <= 100; c1++){
        for (int c2 = 0; c2 <= 100; c2++){
            for (int c3 = 0; c3 <= 100; c3++){
                if (c1 == 0 && c2 == 0 && c3 == 0) continue;
                int zcnt = 0;
                if (c1 == 0) zcnt++;
                if (c2 == 0) zcnt++;
                if (c3 == 0) zcnt++;

                if (zcnt > 1) continue;
                double k = checkTarget(c1, c2, c3);
                if (k < 1) continue;

                printf("%d %d %d %d\n", c1, c2, c3, (int)k);
                return 0;

            }
        }
    }

    printf("NONE\n");
    return 0;


}
