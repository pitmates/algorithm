#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 100100;
int n;
int arr[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    scanf("%d", &n);
    rep(i, 0, n) scanf("%d", arr+i);
    sort(arr, arr+n);
    n = unique(arr, arr+n) - arr;
    if(n < 3 || (n == 3 && arr[1]-arr[0] == arr[2]-arr[1])) puts("YES");
    else puts("NO");
    return 0;
}
