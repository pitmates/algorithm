#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char c[N];
int main()
{
    int T;
    for(scanf("%d", &T); T; --T){
        scanf("%s", c);
        int len = strlen(c);
        int nz = 0, no = 0, l, r, f = 0, ans = 0;
        for(l = 0; l < len; ++l) if(c[l] == '1') break;
        for(r = len-1; r >= 0; --r) if(c[r] == '0') break;
        int t = 0, s = 1;
        int b[N], res;
        for(int i = l+1; i <= r; ++i) {
            if(c[i] != c[i-1]) {
                b[t++] = s;
                s = 1;
            }
            else ++s;
        }
        b[t++] = s;
        for(int i = 1; i < t; i += 2) ans += b[i];
        s = 0; res = ans;
        for(int i = 1; i < t; i += 2) {
            s = b[i] - b[i-1];
            res -= s;
            ans = min(res, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
