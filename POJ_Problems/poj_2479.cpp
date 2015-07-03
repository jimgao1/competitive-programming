//poj 2479 Maximum sum
//2013-05-01-17.26
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 50005;
int dplift[maxn];
int dpright[maxn];
int a[maxn];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }

        dplift[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            if (dplift[i-1] > 0)
                dplift[i] = dplift[i-1] + a[i];
            else
                dplift[i] = a[i];
        }
        for (int i = 2; i <= n; i++)
            dplift[i] = max(dplift[i], dplift[i-1]);

        dpright[n] = a[n];
        for (int i = n-1; i >= 1; i--)
        {
            if (dpright[i+1] > 0)
                dpright[i] = dpright[i+1] + a[i];
            else
                dpright[i] = a[i];
        }
        for (int i = n-1; i >= 1; i--)
            dpright[i] = max(dpright[i+1], dpright[i]);

        int ans = dplift[1] + dpright[2];
        for (int i = 2; i < n; i++)
        {
            ans = max(dplift[i]+dpright[i+1], ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
