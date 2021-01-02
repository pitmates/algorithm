#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
typedef long long ll;

int n, b;
ll z[N], u[N];

int main()
{
    scanf("%d %d", &n, &b);
    ll x, y;
    int l = 0, r = 1, p = 1;
    scanf("%I64d %I64d", &x, &y);
    u[0] = z[0] = x+y;
    for(int i = 1; i < n; ++i) {
        scanf("%I64d %I64d", &x, &y);
        if(x < z[l]) {
            if(r - l <= b) {
                z[r] = z[r-1] + y;
                u[p++] = z[r];
                ++r;
            } else {
                u[p++] = -1;
            }
        } else if(x < z[r-1]){
            ++l;
            z[r] = z[r-1] + y;
            u[p++] = z[r];
            ++r;
        } else {
            z[l = r] = x+y;
            u[p++] = z[l];
            ++r;
        }
    }
    printf("%I64d", u[0]);
    for(int i = 1; i < p; ++i) printf(" %I64d", u[i]);
    puts("");
    return 0;
}

