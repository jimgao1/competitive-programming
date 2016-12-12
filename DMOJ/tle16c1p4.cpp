
#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

int N, M, K, matrix[MAXN][MAXN], value[MAXN];

int main(){
	memset(matrix, 0x3f, sizeof matrix);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> value[i];
	for (int i = 0, a, b, w; i < M; i++){
		cin >> a >> b >> w;
		a--, b--;
		if (w < matrix[a][b]){
			matrix[a][b] = matrix[b][a] = w;
		}
	}

	for (int i = 0; i < N; i++) matrix[i][i] = 0;

	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]){
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			for (int k = j + 1; k < N; k++){
				int tmp = 0;
				for (int l = 0; l < N; l++){
					int dist = min(matrix[i][l], min(matrix[j][l], matrix[k][l]));
					if (dist <= K) tmp += value[l];
				}

				ans = max(ans, tmp);
			}
		}
	}

	cout << ans << endl;
}
