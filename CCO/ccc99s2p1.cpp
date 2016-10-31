
#include <bits/stdc++.h>

using namespace std;

int T, R, C, ar, ac, br, bc;

int main(){
    cin >> T;
    while(T--){
        cin >> R >> C >> ar >> ac >> br >> bc;
        string direction;
        cin >> direction;

        R++, C++;
        ar = R - ar - 1, br = R - br - 1;

        int dr = (direction[0] == 'N' ? -1 : 1), dc = (direction[1] == 'W' ? -1 : 1);
        int steps = 0, cnt = 0;
        bool fuck = false;
        while(true){
            if (++cnt > 80000) break;

            int vert, hor;
            if (dr == -1){
                vert = ar;
            } else {
                vert = R - ar - 1;
            }

            if (dc == -1){
                hor = ac;
            } else {
                hor = C - ac - 1;
            }

            if ((ar - br) / dr == (ac - bc) / dc){
                printf("B can be reached from A after %d move(s).\n", steps + abs(ar - br));
                fuck = true;
                break;
            }

            if (vert < hor){
                ar += vert * dr, ac += vert * dc;
                steps += vert;

                dr = -dr;
            } else if (vert > hor){
                ar += hor * dr, ac += hor * dc;
                steps += hor;

                dc = -dc;
            } else {
                ar += hor * dr, ac += hor * dc;
                steps += hor;

                dr = -dr;
                dc = -dc;
            }

        }

        if (!fuck) printf("B cannot be reached from A.\n");
    }
}

