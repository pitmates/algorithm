#include <bits/stdc++.h>
using namespace std;

const int N = 2020;

int x[N], y[N];

map<pair<int, int>, int > m;

int main()
{
    int n;
    scanf("%d", &n);
    long long s = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", x+i, y+i);
        for(int j = 0; j < i; ++j) {
            s += m[{x[j]+x[i], y[j]+y[i]}] ++;
        }
    }
    printf("%I64d\n", s);
    return 0;
}
