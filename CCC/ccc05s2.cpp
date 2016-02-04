
#include <bits/stdc++.h>

using namespace std;

int W, H, curX = 0, curY = 0;

int main(){
    scanf("%d%d", &W, &H);
    while(true){
        int dx, dy;
        scanf("%d%d", &dx, &dy);

        if (dx == 0 && dy == 0) break;

        curX += dx, curY += dy;

        curX = max(curX, 0);
        curX = min(curX, W);
        curY = max(curY, 0);
        curY = min(curY, H);

        printf("%d %d\n", curX, curY);
    }
}
