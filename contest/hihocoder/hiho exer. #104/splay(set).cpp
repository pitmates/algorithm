#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    char c[2];
    set<int > s;
    for(scanf("%d", &n); n--; ) {
        scanf("%s %d", c, &a);
        if(c[0] == 'I') s.insert(a);
        else if(c[0] == 'Q') printf("%d\n", *--s.upper_bound(a));
        else {
            scanf("%d", &b);
            set<int >::iterator st, ed;
            st = s.lower_bound(a);
            ed = s.upper_bound(b);
            s.erase(st, ed);
        }
    }
    return 0;
}
