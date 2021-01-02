#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+3;
const int M = 1e6+3;

char P[N], S[M];
int next[N];

void getnext(int next[], char* p, int pLen) {
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < pLen) {
        if(k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
}

int kmp(char* s, char* p, int cnt) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    getnext(next, p, pLen);
    int i = 0, j = 0;
    while(i < sLen) {
        if(j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
        if(j == pLen) ++cnt, j = next[j];
    }
    return cnt;
}


int main()
{
    int T;
    for(scanf("%d", &T); T; --T) {
        scanf("%s", P);
        scanf("%s", S);
        printf("%d\n", kmp(S, P, 0));
    }
    return 0;
}
