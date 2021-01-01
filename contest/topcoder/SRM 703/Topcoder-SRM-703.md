---
title: Topcoder SRM 703 (Div.2)
date: 2016-12-15 11:40:19
tags: [ algorithm, topcoder SRM ]
category: contest
---

<!-- more -->
## Problem 250、AlternatingString
### 思路：
　　线性扫描，如果当前位和前一位不同，长度加1；否则重新计算。

### code

``` cpp
class AlternatingString {
    public:
    int maxLength(string s) {
        int n = s.size();
        int m = 0;
        s[n] = s[n-1];
        for(int i = 0, t = 1; i < n; ++i) {
            if(s[i+1] != s[i]) ++t;
            else {
                m = max(t, m);
                t = 1;
            }
        }
        printf("%d\n", m);
        return m;
    }
};
```


## Problem 500、GCDGraph
### 解法：
　　并查集处理 `i∈[k+1, n]` 和i的倍数，将它们归为同一集合。最后如果x的集合和y的集合相同，则可达。 
　　（PS：另外做法：取 `i∈[k+1, n]` 内`gcd(x, i) > k` 的集合Sa，`gcd(y, i) > k` 的集合Sb，只要满足`gcd(Sai, Sbj) > k, (Sai∈Sa, Sbj∈Sb)` 即有解，否则无解。我认为这解法不太严谨（雾。）
### code

``` cpp
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define zero(x) memset((x), (0), sizeof (x))

using namespace std;
const int N = 1000010;

class GCDGraph {
    public:
    //    vector<int > vx, vy;

    int f[N];
    int findset(int z) {
        if(z == f[z]) return z;
        return f[z] = findset(f[z]);
    }
    void unionset(int u, int v) {
        u = findset(u); v = findset(v);
        if(u != v) f[u] = v;
    }

    string possible(int n, int k, int x, int y) {
        if(x == y) return "Possible";
        if(__gcd(x, y) > k) return "Possible";
        if(x <= k || y <= k) return "Impossible";

        for(int i = 0; i <= n; ++i) f[i] = i;
        for(int i = k+1; i <= n; ++i) {
            for(int j = i; j <= n; j += i) unionset(j, i);
        }
        
        return findset(x) == findset(y) ? "Possible" : "Impossible";
    /**
        vx.clear(); vy.clear();
        rep(i, k+1, n+1) if(__gcd(x, i) > k) vx.pb(i);
        rep(i, k+1, n+1) if(__gcd(y, i) > k) vy.pb(i);
        rep(i, 0, sz(vx)) rep(j, 0, sz(vy)){
            if(__gcd(vx[i], vy[j]) > k) return "Possible";
        }
        return "Impossible";
    **/
    }
};

```

## Problem 1000、TreeDiameters
### 解法：
　　建图，对于p[i]点与i+1点相连，引入`n+i+2`点，让p[i]与n+i+2相连，然后n+i+2点与i+1相连。主要处理类似`[0,1,2,2,1]`这类的点的情况。
　　其次计算，dfs计算与当前点u距离d的点的个数k，用容斥计算状况数。首先，连接方式有`k*k`种，其中点集(假设p个点集)共享某一点v到达u的集合（假设有ki个）不能相互到达，以此类推，`ans = k*k - k1*k1 - k2*k2 - ... - ki*ki - .. - kp*kp`。

### code

``` cpp
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define sz(x) ((int) (x).size())
#define ll long long
#define mp make_pair
#define pii pair<int, int >
#define fi first
#define se second
#define pb push_back
#define zero(x) memset((x), (0), sizeof (x))

using namespace std;
const int N = 2020;

class TreeDiameters {
    public:
    vector<int > E[N];
    int dis[N];
    int sum[N], sum2[N];

    void dfs(int x, int parent, int depth) {
        ++dis[depth];
        for(int y : E[x]) if(y != parent) 
            dfs(y, x, depth+1);
    }

    int getMax(vector<int> p) {
        if(sz(p) == 1) return 1;
        for(int i = 0; i < N; ++i) E[i].clear();
        int n = sz(p);
        for(int i = 0; i < n; ++i) {
            E[p[i]].pb(n+i+2); E[n+i+2].pb(p[i]);
            E[i+1].pb(n+i+2); E[n+i+2].pb(i+1);
        }
        int ans = 0;
        rep(i, 0, n+n+2) {
            zero(sum); zero(sum2);
            for(int x : E[i]){
                zero(dis);
                dfs(x, i, 1);
            //rep(j, 1, n+1) printf("%d ", dis[j]); puts("");
                rep(j, 1, n+1) {
                    sum[j] += dis[j];
                    sum2[j] += dis[j] * dis[j];
                }
            }
            rep(j, 1, n+1) 
                ans = max(ans, (sum[j]*sum[j] - sum2[j])/2);
        }
        return ans;
    }
};

```
