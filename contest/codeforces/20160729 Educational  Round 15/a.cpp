#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n;
int a[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int m = 1, z = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] > a[i-1]) ++z;
        else m = max(m, z), z = 1;
    }
    printf("%d\n", max(z, m));
    return 0;
}
