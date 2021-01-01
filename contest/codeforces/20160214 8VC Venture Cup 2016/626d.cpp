#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n;
int a[N];
double ct[N], cnt[N];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", a+i);
    sort(a, a+n);
    memset(cnt, 0, sizeof cnt);

    for(int i = 0; i < n; ++i) for(int j = 0; j < i; ++j) cnt[a[i] - a[j]]++;

    double r = (n - 1) * n * 1. / 2;

    for(int i = 5000; i >= 0; --i) ct[i] += ct[i+1] + (cnt[i] /= r);

    double ans = 0.0;
    for(int i = 1; i < 5000; ++i) for(int j = 1; j + i < 5000; ++j) ans += cnt[i] * cnt[j] * ct[i+j+1];

    printf("%.12f\n", ans);

    return 0;
}
