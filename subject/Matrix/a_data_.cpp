#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair
#define ui unsigned int
using namespace std;
const ui mo = 1e9+1;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
freopen("uva11651.in", "w", stdout);
#endif // PIT
    srand(time(NULL));
    int t = 50;
    printf("50\n");
    for(int i = 0; i < t; ++i) {
        int base = rand() % 5 + 2;
        ui b = 1;
        for(int j = 0, x; j < 62; ++j) {
            x = rand() % 2;
            b = ((b * 2) + x) % mo;
        }
        printf("%d %u\n", base, b);
    }
    return 0;
}
