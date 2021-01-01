#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 110;

int a[N];
int n;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    scanf("%d", &n);
    rep(i, 0, n)scanf("%d", a+i);
    a[n] = 0;
    int x = 0, z = 0;
    rep(i, 0, n) {
        if(a[i] == 0) ++z, x = 0;
        else if(a[i] == 1) {
            if(x == 1) ++z, x = 0;
            else x = 1;
        }
        else if(a[i] == 2) {
            if(x == 2) ++z, x = 0;
            else x = 2;
        }
        else {
            if(x == 1) x = 2;
            else if(x == 2) x = 1;
            else {
                if(a[i+1] == 1) x = 2;
                else if(a[i+1] == 2)x = 1;
                else {
                    int q = 1, p, l;
                    for(int j = i+1; a[j] == 3; p = a[++j]) ++q;
                    if(p == 1) {
                        if(q & 1) x = 2;
                        else x = 1;
                    }
                    else {
                        if(q&1) x = 1;
                        else x = 2;
                    }
                }
            }
        }
    }
    printf("%d\n", z);
    return 0;
}
