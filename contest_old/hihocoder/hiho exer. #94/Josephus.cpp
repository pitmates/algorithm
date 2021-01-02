#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 解法1
int kth(int n, int m, ll k) {
    if(n == 1) return 0;
    for(k = k*m+m-1; k >= n; k = k-n+(k-n)/(m-1)) ;
    return (int)k;
}

//解法2_1
int Josephus(int n, int m) { // 非全递归
    if(n == 1) return 0;
    if(n < m) {
        int ret = 0;
        for(int i = 2; i <= n; ++i) ret = (ret + m) % i;
        return ret;
    }
    int ret = Josephus(n - n/m, m);
    if(ret < n % m) ret = ret - n % m + n;
    else ret = ret - n % m + (ret - n%m) / (m-1);
    return ret;
}

// 2_2
int Josephus2(int n, int m) {
    if(n == 1) return 0;
    if(n < m) return (Josephus2(n-1, m) + m) % n;
    int ret = Josephus2(n - n/m, m) - n%m;
    return ret < 0 ? ret + n : ret + ret / (m-1);
}

int main()
{
    int T, ic = 0;
    int n, m;
    for(scanf("%d", &T); ic < T; ++ic) {
        scanf("%d %d", &n, &m);
        //printf("%d\n", kth(n, m, n-1)); //1
        //printf("%d\n", Josephus(n, m)); //2_1
        printf("%d\n", Josephus2(n, m)); //2_2
    }
    return 0;
}
