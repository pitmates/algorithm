#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef PIT
    freopen("poj2253.in", "w", stdout);
    #endif // PIT
    int t = 10;
    for(int tt = 0; tt < 10; ++tt){
        int n = rand() % 198 + 2;
        printf("%d\n", n);
        int x, y;
        for(int i = 0; i < n; ++i) {
            x = rand() % 1000;
            y = rand() % 1000;
            printf("%d %d\n", x, y);
        }
        puts("");
    }
    puts("0");
    return 0;
}
