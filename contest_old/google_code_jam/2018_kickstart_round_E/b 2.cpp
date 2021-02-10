#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

pair <long long, long long> forbid[105], a[105];
int N,M,P,ans,cnt,like[105],c[10005][2];

void DFS(int x, int acc, int dep)
{
    if (c[x][0]) DFS(c[x][0], acc+like[dep], dep+1);
    else if (dep < P)
    {
        int tmp = acc + like[dep];
        for (int i = dep+1; i < P; i ++)
            tmp += (like[i]<N-like[i]?like[i]:N-like[i]);
        if (tmp<ans) ans=tmp;
    }
    if (c[x][1]) DFS(c[x][1], acc+N-like[dep], dep+1);
    else if (dep < P)
    {
        int tmp = acc + N - like[dep];
        for (int i = dep+1; i < P; i ++)
            tmp += (like[i]<N-like[i]?like[i]:N-like[i]);
        if (tmp<ans) ans=tmp;
    }
}

int main()
{
    freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
    int T; scanf("%d", &T);
    for (int cases = 1; cases <= T; cases ++)
    {
        memset(like, 0, sizeof(like));
        scanf("%d%d%d", &N, &M, &P);
        for (int i = 1; i <= N; i++)
        {
            char s[105]; scanf("%s", s);

            for (int j = 0; j < P; j ++)
                if (s[j] == '1')
                    like[j] ++;//, a[i].first |= (1LL << j);
            /*
            for (int j = P/2; j < P; j ++)
                if (s[j] == '1')
                    like[j] ++, a[i].second |= (1LL << (j-P/2));
                    */
        }

        ans = 1e9,cnt=1; memset(c, 0, sizeof(c));
        for (int i = 1; i <= M; i ++)
        {
            char s[105]; scanf("%s", s);
            int x = 1;
            for (int j = 0; j < P; j ++)
                if (c[x][s[j]-48]) x = c[x][s[j]-48];
                    else c[x][s[j]-48] = ++ cnt, x = cnt;
        }
        DFS(1, 0, 0);
        printf("Case #%d: %d\n", cases, ans);
    }
    return 0;
}