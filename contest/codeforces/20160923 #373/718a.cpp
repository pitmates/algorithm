#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 200200;
int g[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;
    int point, de;
    rep(i, 0, n) {
        if(s[i] == '.') point = i, g[i] = -1;
        else g[i] = s[i] - '0';
    }
    for(de = point+1; de < n; ++de) if(g[de] > 4) break;
    int flag = 0;
    for(int i = de, j; i >= 0 && t && !flag; --i) {
        if(i <= point) flag = 1;
        j = i;
        if(g[j] < 5) break;
        else {
            g[j] = 0;
            if(--j == point) --j;
            ++g[j];
        }
        while(g[j] == 10 && j) {
            g[j] = 0;
            if(--j == point) --j;
            ++g[j];
        }
        --t;
    }
    for( ; de > point; --de) if(g[de]) break;
    if(de == point) --de;
    for(int i = 0; i <= de; ++i) {
        if(i == point) printf(".");
        else printf("%d", g[i]);
    }
    puts("");
    return 0;
}
