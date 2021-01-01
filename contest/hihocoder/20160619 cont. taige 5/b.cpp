#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 100100;
int cnt[30];
char c[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%s", c);
    int len = strlen(c);
    memset(cnt, 0, sizeof cnt);
    rep(i, 0, len) ++cnt[c[i]-'a'];
    int ma = 0, x = -1;
    rep(i, 0, 26) if(ma < cnt[i]) ma = cnt[i], x = i;
    if(ma > len / 2 + 1) puts("INVALID");
    else {
        int t = 0, pre = -1;
        while(len) {
            ma = 0, x = -1, pre;
            rep(i, 0, 26) if(ma < cnt[i]) ma = cnt[i], x = i;
            if(ma + ma > len) c[t] = 'a' + x, --cnt[x], pre = x;
            else {
                rep(i, 0, 26) if(cnt[i] && pre != i) {
                    c[t] = 'a' + i;
                    --cnt[i];
                    pre = i;
                    break;
                }
            }
            ++t, --len;
        }
        puts(c);
    }
    return 0;
}

