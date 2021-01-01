#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

ll multi_mod(ll a, ll b, ll n) {
    ll x = 0LL;
    while(b) {
        if(b&1) if((x += a) >= n) x -= n;
        if((a += a) >= n) a -= n;
        b >>= 1;
    }
    return x;
}

ll multi_pow(ll a, ll b, ll n) {
    ll x = 1LL;
    while(b) {
        if(b&1) x = multi_mod(x, a, n);
        a = multi_mod(a, a, n);
        b >>= 1;
    }
    return x;
}

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
const int S = 13;

ll ran() { ll ret = rand(); return rand() * ret;}

bool Miller_Rabin(ll n) {
//bool Miller_Rabin(ll n, int t) {
    if(n == 2) return true;
    if(n < 2 || ~n&1) return false;
    int k = 0, cnt;
    ll y = n-1;
    while(~y&1) y >>= 1, ++k;
    rep(i, 0, S) {
//    while(t--){
//        ll v = ran() % (n - 2) + 2;
//        ll x = multi_pow(v, y, n);
        ll x = multi_pow(prime[i], y, n);
        if(x == 1) continue;
        for(cnt = 0; cnt < k; ++cnt){
            if(x == n-1) break;
            x = multi_mod(x, x, n);
        }
        if(cnt >= k) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        ll n;
        scanf("%lld", &n);
//        if(Miller_Rabin(n, 3)) puts("Yes");
        if(Miller_Rabin(n)) puts("Yes");
        else puts("No");
    }
    return 0;
}
