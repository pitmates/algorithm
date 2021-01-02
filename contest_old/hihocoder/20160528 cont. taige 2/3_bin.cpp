#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 505;

char s[N][N<<1];
int T, len;
char c[N];
int ans[N<<1], t;

void init() {
    s[1][0] = '0';s[1][1] = '.';s[1][2] = '5';
    rep(i, 2, N) {
        int len = strlen(s[i-1]);
        int m = 0, d;
        rep(j, 0, len) {
            if(s[i-1][j] == '.') { s[i][j] = '.'; continue;}
            d = m * 10 + s[i-1][j] - '0';
            s[i][j] = d / 2 + '0';
            m = d % 2;
        }
        if(m) s[i][len] = '5';
    }
    return ;
}

void sub(char s[]) {
    int le = strlen(s);
    int lend = 0, va, i = le-1;
    if(len < le) {
        for( ; i >= len; --i) {
            va = (i == le-1) ? 10 : 9;
            c[i] = va - s[i]  + '0' + '0';
        }
        va = i;
        while(c[va] == '0') {c[va] = '9'; --va; }
        if(c[va] != '.') c[va] = c[va] - 1;

    }
    for( ; i > 1; --i) {
//printf("i:%d c:%c s:%c \n", i, c[i], s[i]);
        if(c[i] < s[i]) {
            c[i] = 10 + c[i] - s[i] + '0';
            va = i-1;
            while(c[va] == '0') { c[va] = '9'; --va;}
            c[va] = c[va] - 1;
//printf("c:  %s\n", c);
        }
        else c[i] = c[i] - s[i] + '0';
//printf("==> i:%d c:%s  \n", i, c);
    }
    return ;
}

void solve() {
    bool f; t = 1;
    rep(i, 1, N) {
        len = strlen(c); f = 1;
        rep(j, 2, len) if(c[j] != '0') {f = 0; break;}
        if(f) break;
        int v = strcmp(c, s[i]);
        if(v < 0) { ans[t++] = 0; continue; }
        ans[t++] = 1;
        sub(s[i]);
    }
    if(!f) puts("NO");
    else {
        printf("0.");
        rep(i, 1, t) printf("%d", ans[i]);
        puts("");
    }
    return ;
}

int main()
{
#ifdef PIT
freopen("3.in", "r", stdin);
#endif // PIT
    init();
    for(scanf("%d", &T) ; T; --T) {
        scanf("%s", c);
        solve();
    }
    return 0;
}
