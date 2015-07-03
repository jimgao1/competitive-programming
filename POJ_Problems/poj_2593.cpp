
#include <cstdio>
#include <string>
#include <algorithm>
#define MAXN 100001

using namespace std;

int dp_left[MAXN];
int dp_right[MAXN];
int a[MAXN];
int n;

int main()
{
    while (true)
    {
        scanf("%d", &n);

        if (n == 0) break;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        dp_left[0] = a[0];

        for (int i = 1; i <= n; i++)
        {
            if (dp_left[i - 1] > 0)
                dp_left[i] = dp_left[i - 1] + a[i];
            else
                dp_left[i] = a[i];
        }

        for (int i = 1; i < n; i++)
            dp_left[i] = max(dp_left[i], dp_left[i - 1]);


        dp_right[n - 1] = a[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            if (dp_right[i + 1] > 0)
                dp_right[i] = dp_right[i + 1] + a[i];
            else
                dp_right[i] = a[i];
        }

        for (int i = n - 2; i >= 0; i--)
            dp_right[i] = max(dp_right[i + 1], dp_right[i]);

        int ans = dp_left[0] + dp_right[1];

        for (int i = 1; i < n - 1; i++)
        {
            ans = max(dp_left[i]+dp_right[i+1], ans);
        }

        printf("%d\n", ans);
    }
    return 0;
}
