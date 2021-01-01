#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
char c[N], s[N];
int main()
{
    while(gets(c)) {
        memset(s, false, sizeof s);
        int n = strlen(c);
        int i, t = 0;
        for(i = 0; i < n; ++i) if((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')) break;
        bool f1 = 0;
        for( ; i < n; ++i) {
            if(f1 && c[i] == ' ') continue;
            if(f1 && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))) {
                s[t++] = c[i]; f1 = 0;
            }
            else if(f1) {
                s[t-1] = c[i];
                f1 = 0;
            }
            else if(!f1 && ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))) s[t++] = c[i];
            else if(!f1 && c[i] == ' ') {
                s[t++] = c[i]; f1 = 1;
            }
            else if(!f1) s[t++] = c[i];
        }
        f1 = 1;
        for(i = 0; i < t; ++i) {
            if(s[i] == ' ') continue;
            if(f1) {
                if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
                f1 = 0;
            }
            else{
                if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
                if(!f1 && s[i] == '.') f1 = 1;
            }
        }
        puts(s);
        memset(c, false, sizeof c);
    }
    return 0;
}
