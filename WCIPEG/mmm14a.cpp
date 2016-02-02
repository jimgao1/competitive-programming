
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

int p[1000010];
int a, b;

int main(){
	memset(p, 0, sizeof(1000010) * sizeof(int));

	cin >> a >> b;

	for (int i = 2; i <= b; i++)
		if (p[i] == 0)
			for (int j = i; j <= b; j += i)
				p[j]++;

	for (int i = a; i <= b; i++)
		printf("%d\n", p[i]);

	return 0;
}
