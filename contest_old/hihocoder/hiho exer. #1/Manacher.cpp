#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

char c[N], s[N<<1];
int n;
int RL[N<<1];

int Manacher() {
    memset(RL, 0, sizeof RL);
    int maxRight = 0, center = 0;
    int maxLen = 0;
    for(int i = 1; i < n; ++i) {
        if(maxRight > i) RL[i] = min(RL[center+center-i], maxRight-i);
        else RL[i] = 1;
        for( ; s[i+RL[i]] == s[i-RL[i]]; ++RL[i]) ;
        if(RL[i]+i > maxRight) {
            center = i;
            maxRight = RL[i] + i;
        }
        maxLen = max(maxLen, RL[i]);
    }
    return maxLen-1;
}

int main()
{
    int T;
    for(scanf("%d", &T); T; --T) {
        scanf("%s", c);
        int len = strlen(c);
        n = 0; memset(s, false, sizeof s);
        s[n++] = '$';
        for(int i = 0; i < len; ++i) s[n++] = '#', s[n++] = c[i];
        s[n++] = '#';
        printf("%d\n", Manacher());
    }
    return 0;
}
