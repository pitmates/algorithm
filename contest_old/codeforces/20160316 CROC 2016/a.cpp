#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int x[101][101];

int main()
{
    scanf("%d %d %d", &n, &a, &b);
    int i, j, k = 1;
    if(n > a*b) {
        puts("-1");
    } else {
        if(b & 1) {
            for(i = 0; i < a && k; ++i) {
                for(j = 0; j < b && k; ++j) {
                    int y = i * b + j + 1;
                    if(y > n) k = 0;
                    else x[i][j] = y;
                }
            }
        } else {
            bool f = 0;
            for(i = 0; i < a && k ; ++i) {
                if(i&1) {
                    for(j = 0; j < b; ++j) {
                        int y = (i + 1) * b-j;
                        if(y >= n) f = 1;
                        if(y <= n) x[i][j] = y;
                    }
                    if(f) k = 0;
                } else {
                    for(j = 0; j < b && k ; ++j) {
                        int y = i * b + j + 1;
                        if(y > n) k = 0;
                        else x[i][j] = y;
                    }
                }
            }
        }
        for(i = 0; i < a; ++i) {
            printf("%d", x[i][0]);
            for(j = 1; j < b; ++j) printf(" %d", x[i][j]);
            puts("");
        }
    }
    return 0;
}
