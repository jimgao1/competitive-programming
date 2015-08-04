
#include <bits/stdc++.h>

using namespace std;

int X, Y;
int nblack[3001][3001], nwhite[3001][3001];
int sblack[3001][3001], swhite[3001][3001];

inline bool isBlack(int x, int y){
    return (x % 2 == y % 2);
}

int main(){
    memset(nblack, 0, sizeof nblack);
    memset(nwhite, 0, sizeof nwhite);
    memset(sblack, 0, sizeof sblack);
    memset(swhite, 0, sizeof swhite);

    cin >> Y >> X;
    while(true){
        int cx, cy, cnum;
        cin >> cy >> cx >> cnum;

        if (cx == 0 && cy == 0 && cnum == 0) break;

        if (isBlack(cx, cy))
            nblack[cx][cy] = cnum;
        else
            nwhite[cx][cy] = cnum;
    }

    for (int i = 1; i <= X; i++){
        for (int j = 1; j <= Y; j++){
            if (isBlack(i, j)){
                sblack[i][j] = sblack[i - 1][j] + sblack[i][j - 1] - sblack[i - 1][j - 1] + nblack[i][j];
                swhite[i][j] = swhite[i - 1][j] + swhite[i][j - 1] - swhite[i - 1][j - 1];
            } else {
                swhite[i][j] = swhite[i - 1][j] + swhite[i][j - 1] - swhite[i - 1][j - 1] + nwhite[i][j];
                sblack[i][j] = sblack[i - 1][j] + sblack[i][j - 1] - sblack[i - 1][j - 1];
            }
        }
    }



    while(true){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) break;

        int sumBlack = sblack[x2][y2] + sblack[x1 - 1][y1 - 1] - sblack[x2][y1 - 1] - sblack[x1 - 1][y2];
        int sumWhite = swhite[x2][y2] + swhite[x1 - 1][y1 - 1] - swhite[x2][y1 - 1] - swhite[x1 - 1][y2];

        if (isBlack(x1, y1))
            cout << sumBlack - sumWhite << endl;
        else
            cout << sumWhite - sumBlack << endl;
    }

    return 0;
}
