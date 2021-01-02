#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 511;
int n;
char s[N], c;
int x[N];

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT

    int t = 0;
    int add = 0, sub = 0;
    x[t] = 1;
    while(c = getchar()) {
        if(c == '=') break;
        if(c == ' ' || c == '?') continue;
        s[t++] = c;
        x[t] = 1;
        add += (c == '+');
    }
    sub = t - add;
    ++add;
    cin >> n;
    int s1 = add * n, v1 = sub;
    int s2 = add, v2 = n * sub;
    if(s1 - v1 < n || s2 - v2 > n) puts("Impossible");
    else {
        int v = add - sub - n;
        puts("Possible");
//printf("%d %d %d  == %d\n", add, sub, v, n);
//for(int j = 0; j <= t; ++j) printf("%d ", x[j]); puts("");
        if(v >= 0) {
            printf("1 ");
            for(int i = 0; i < t; ++i) {
                if(s[i] == '+') printf("+ %d ", x[i+1]);
                else {
                    if(v >= n-1) printf("- %d ", n), v -= n-1;
                    else printf("- %d ", v+1), v = 0;
                }
            }
            printf("= %d\n", n);
        }
        else {
            v = -v;
            if(v >= n-1) printf("%d ", n), v -= n-1;
            else printf("%d ", v+1), v = 0;
            for(int i = 0; i < t; ++i) {
                if(s[i] == '-') printf("- 1 ");
                else {
                    if(v >= n-1) printf("+ %d ", n), v -= n-1;
                    else printf("+ %d ", v+1), v = 0;
                }
            }
            printf("= %d\n", n);
        }
    }
    return 0;
}
/**
? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? + ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? + ? - ? - ? - ? - ? + ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? - ? = 32
**/
