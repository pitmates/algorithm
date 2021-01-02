#include <bits/stdc++.h>
using namespace std;

int n;

int multi_mod(int x, int y) {
    int t = 1;
    while(y){
        if(y&1) t = (t * x) % 10;
        x = (x * x) % 10;
        y >>= 1;
    }
    return t;
}

int main()
{
    scanf("%d", &n);
    printf("%d\n", multi_mod(8, n));
    return 0;
}