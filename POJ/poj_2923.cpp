
#include <cstdio>
#include <algorithm>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

inline bool getBit(int n, int bit) { return n & (1 << bit); }
inline int setBit(int n, int bit) { return n | (1 << bit); }

int T, N, C1, C2, w[11], ans = INF;

int main(){
    scanf("%d", &T);
    for (int fuck = 1; fuck <= T; fuck++){
        ans = INF;

        scanf("%d%d%d", &N, &C1, &C2);
        for (int i = 0; i < N; i++) scanf("%d", &w[i]);

        for (int i = 0; i < (1 << N); i++){
            vector<int> n1, n2;

            bool flag = true;
            for (int j = 0; j < N; j++){
                if (getBit(i, j)){
                    if (w[j] > C1){
                        flag = false;
                        break;
                    }
                    n1.push_back(w[j]);
                } else {
                    if (w[j] > C2){
                        flag = false;
                        break;
                    }
                    n2.push_back(w[j]);
                }
            }

            if (!flag) continue;

            sort(n1.begin(), n1.end());
            sort(n2.begin(), n2.end());

            reverse(n1.begin(), n1.end());
            reverse(n2.begin(), n2.end());

            int cnt1 = 0, cnt2 = 0;
            int cap1 = C1, cap2 = C2;

            while(n1.size() > 0){
                bool fuk = false;

                for (int i = 0; i < n1.size(); i++){
                    if (n1[i] <= cap1){
                        cap1 -= n1[i];
                        n1.erase(n1.begin() + i);
                        fuk = true;
                        break;
                    }
                }

                if (!fuk){
                    cnt1++;
                    cap1 = C1;
                }
            }

            if (cap1 < C1) cnt1++;

            while(n2.size() > 0){
                bool fuk = false;

                for (int i = 0; i < n2.size(); i++){
                    if (n2[i] <= cap2){
                        cap2 -= n2[i];
                        n2.erase(n2.begin() + i);
                        fuk = true;
                        break;
                    }
                }

                if (!fuk){
                    cnt2++;
                    cap2 = C2;
                }
            }

            if (cap2 < C2) cnt2++;

            ans = min(ans, max(cnt1, cnt2));
        }

        printf("Scenario #%d:\n%d\n\n", fuck, ans);
    }
}
