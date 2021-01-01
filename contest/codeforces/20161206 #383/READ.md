---
title: codeforces round 383
date: 2016-12-07 10:38:46
tags: algorithm
category:
 - codeforces
 - contest
---

　　[codeforces round 383](http://codeforces.com/contest/742) 

<!-- more -->
## 742A、Arpa’s hard exam and Mehrdad’s naive cheat
### 思路：
　　只需算8的n次方，每次模10去最后一位。找规律或者快速幂均可。

### code

```cpp
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
```


## 742B、Arpa’s hard exam and Mehrdad’s naive cheat
### 解法：
　　统计每个数字 `k` 和 `x xor k` 出现的次数，答案就是所有的count[k] * count[x^k] 的和，注意特判 `k == (x xor k)`的情形（值为`count[k] * (count[k] - 1) / 2`）。答案会超`int`。

### code

```cpp
#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 100100;
int n, x;
int a[N], b[N];

int main()
{
//freopen("", "r", stdin);
//freopen(".out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> x;
    zero(b);
    rep(i, 0, n) cin >> a[i], b[a[i]]++;
    ll ans = 0;
    rep(i, 0, n){
        int y = x ^ a[i];
        if(y >= N || !b[a[i]] || !b[y]) continue;
        if(y == a[i]) ans += 1LL * b[y] * (b[y]-1) / 2;
        else ans += 1LL * b[y] * b[a[i]];
        b[y] = b[a[i]] = 0;
    }
    cout << ans;
    return 0;
}

```

## 741A、Arpa's loud Owf and Mehrdad's evil plan
### 解法：
　　找串中循环串的长度`len[i]`。当长度为偶数时，只需该长度的一半即可实现题目要求（不懂的可自行模拟一番），即`ans[i] = len[i] / 2`；当长度为奇数时，`ans[i] = len[i]`。答案就是ans[i]的最小公倍数。

### code
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
typedef long long ll;

int a[N], b[N];
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    memset(b, 0, sizeof b);
    ll z = 1, y;
    for(int i = 1; i <= n; ++i) {
        int x = a[i];
        if(b[x]) continue;
        y = 0;
        while(!b[x]) {
            b[x] = 1;
            x = a[x];
            ++y;
        }
        if(y % 2 == 0) y /= 2;
        z = z / __gcd(z, y) * y;
    }
    for(int i = 1; i <= n; ++i) if(!b[i]) {
        z = -1;
        break;
    }
    printf("%I64d\n", z);
    return 0;
}
```

## 741B、Arpa's weak amphitheater and Mehrdad's valuable Hoses
### 解法：
　　对于朋友圈，用并查集处理，然后就转化为背包问题。每次取只取朋友圈的根节点进入背包，要么取一个，要么取整体。

### code
```cpp
#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i <= (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f
#define zero(x) memset((x), (0), sizeof (x))
#define zerox(x, y) memset((x), (y), sizeof (x))

using namespace std;
const int N = 1023;

int n, m, W;
pii wb[N];
vector<int > st[N];
int fa[N];
int d[N];

int findset(int x) {
    if(x == fa[x]) return x;
    return x = findset(fa[x]);
}

void unionset(int x, int y) {
    x = findset(x); y = findset(y);
    if(x != y) fa[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> W;
    int w, b, x, y;
    rep(i, 1, n) cin >> w, wb[i].fi = w;
    rep(i, 1, n) cin >> b, wb[i].se = b;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        cin >> x >> y;
        unionset(x, y);
    }
    rep(i, 1, n) st[findset(i)].pb(i);
    w = b = x = y = 0;
    zero(d);
    rep(i, 1, n) {
        if(fa[i] != i) continue;  // only the root used to calculate
        for(int j = W; j >= 0; --j) {
            x = y = 0;
            // only one person takes part in
            for(int k = 0; k < sz(st[i]); ++k) {
                w = wb[st[i][k]].fi, b = wb[st[i][k]].se;
                x += w, y += b;
                if(j >= w) d[j] = max(d[j], d[j-w]+b);
            }
            // all union take part in
            if(j >= x) d[j] = max(d[j], d[j-x]+y);
        }
    }
    int mx = 0;
    rep(i, 0, W) if(d[i] > mx) mx = d[i];
    cout << mx;
    return 0;
}
```



## 7421、Arpa’s overnight party and Mehrdad’s silent entering
### 解法：
　　

### code
```cpp

```


## 739D、739E待解决
