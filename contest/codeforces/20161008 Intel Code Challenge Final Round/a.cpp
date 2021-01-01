#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char w1[10], w2[10];

int init(char s[]) {
    if(s[0] == 'm') return 0;
    if(s[0] == 't' && s[1] == 'u') return 1;
    if(s[0] == 'w') return 2;
    if(s[0] == 't' && s[1] == 'h') return 3;
    if(s[0] == 'f') return 4;
    if(s[0] == 's' && s[1] == 'a') return 5;
    return 6;
}

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);
#endif // PIT
    while(scanf("%s", w1) != EOF) {
        scanf("%s", w2);
        int d1 = init(w1), d2 = init(w2);
        int f = 0;
        for(int i = 0; i < 11; ++i){
            int x = d1;
            for(int j = 1; j <= mon[i]; ++j) {
                x = (x + 1) % 7;
            }
            if(x == d2) {
                f = 1;
                break;
            }
        }
        puts((f) ? "YES" : "NO");
    }
    return 0;
}
