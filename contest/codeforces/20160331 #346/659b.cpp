#include <bits/stdc++.h>
using namespace std;
const int N = 100100;

struct P{
    int region;
    int score;
    char name[15];
    void in() {scanf("%s %d %d", name, &region, &score); }
}p[N];

inline bool cmp(P a, P b) {
    return a.region < b.region || (a.region == b.region && a.score > b.score);
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) p[i].in();
    sort(p, p+n, cmp);

    bool flag = 0;
    for(int i = 1, v = 1; i < n; ++i) {
        if(p[i].region == p[i-1].region && flag == 1) continue;
        if(p[i].region > p[i-1].region) {
            flag = 0;
        }
        else {
            if(i+1 >= n || p[i+1].region > p[i].region) {
                printf("%s %s\n", p[i-1].name, p[i].name);
            }
            else {
                if(p[i+1].score < p[i].score) printf("%s %s\n", p[i-1].name, p[i].name);
                else puts("?");
            }
            flag = 1;
        }
    }

    return 0;
}
