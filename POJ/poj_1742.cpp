
#include <iostream>
#include <cstring>

using namespace std;

int N, M, a[101], c[101], counter[100010];
bool dp[100010];

int main(){
	while(true){
		cin >> N >> M;

		if (N == 0 && M == 0) break;

		for (int i=0; i<N; i++) cin >> a[i];
		for (int i=0; i<N; i++) cin >> c[i];

		for (int i=0; i<100010; i++) dp[i] = false;
		dp[0] = true;

		for (int i=0; i<N; i++){
			for (int j=0; j<100010; j++) counter[j] = 0;

			for (int j=a[i]; j<=M; j++){
                if (dp[j]) continue;

                if (dp[j - a[i]] && counter[j - a[i]] < c[i]){
                    dp[j] = true;
                    counter[j] = counter[j - a[i]] + 1;
                }
			}
		}

        int cunt = 0;
        for (int i=1; i<=M; i++)
            if (dp[i]) cunt++;

        cout << cunt << endl;
	}
}
