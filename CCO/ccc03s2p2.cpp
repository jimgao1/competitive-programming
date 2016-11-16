
#include <bits/stdc++.h>

#define INF 0x69696969

using namespace std;

inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }

int T, N, W, H;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> W >> H;

        int ans = INF;
        for (int i = 1; i <= N; i++){
            if (N % i == 0){
                //i cards vertically placed
                int w = (N / i) * W;
                int h = i * H;
                ans = min(ans, 2 * w + 2 * h);
            }
        }

        for (int i = 1; i <= N; i++){
            if (N % i == 0 || true){
                //total width of the block
                int w = i * W;
                if (w % H == 0){
                    //how many cards can be placed horizontally
                    int h = w / H;
                    for (int j = 0; h * j <= N; j++){
                        int left = N - j * h;
                        if (left % i == 0){
                            int hh = (left / i) * H + j * W;
                            ans = min(ans, 2 * hh + 2 * w);
                        }
                    }
                }
            }
        }


        cout << ans << endl;
    }
}

