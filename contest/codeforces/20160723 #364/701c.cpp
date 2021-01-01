#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 100100;
char c[N], s[N];
int n;
int v[63];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT

    scanf("%d", &n);
    scanf("%s", c);
    strcpy(s, c);
    sort(s, s+n);
    int m = unique(s, s+n) - s;
    memset(v, 0, sizeof v);
    int mi = n, t = 0, l = -1, r = -1;
    for(; ; ) {
        if(r == n-1 && t < m) break;
        while(r < n-1 && t < m) {
            ++r;
            if(v[c[r]-'A'] == 0) ++t;
            v[c[r]-'A']++;
        }
        while(t == m) {
            ++l;
            if(v[c[l]-'A'] == 1) --t;
            v[c[l]-'A']--;
        }
        mi = min(mi, r-l+1);
    }
    printf("%d\n", mi);
    return 0;
}
