#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;

const int N = 1010;
const int M = 100101;

struct DLX {
    int n, m;
    int size;
    int U[M], D[M], L[M], R[M], Col[M], Row[M];
    int H[N], C[N];
    int ansd, ans[N];

    void init(int _, int __) {
        n = _; m = __;
        rep(i, 0, m+1) {
            C[i] = 0;
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
        }
        L[0] = m; R[m] = 0;
        size = m;
        rep(i, 1, n+1) H[i] = -1;
    }

    void link(int r, int c) {
        ++C[c];
        Col[++size] = c; Row[size] = r;
        U[size] = U[c];
        D[U[c]] = size;
        D[size] = c;
        U[c] = size;
        if(H[r] < 0) H[r] = L[size] = R[size] = size;
        else {
            L[size] = L[H[r]];
            R[L[H[r]]] = size;
            R[size] = H[r];
            L[H[r]] = size;
        }
    }

    void remove(int c) {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = U[c]; i != c; i = U[i])
            for(int j = L[i]; j != i; j = L[j]) {
                D[U[j]] = D[j];
                U[D[j]] = U[j];
                --C[Col[j]];
            }
    }

    void resume(int c) {
        for(int i = D[c]; i != c; i = D[i])
            for(int j = R[i]; j != i; j = R[j]) {
                U[D[j]] = D[U[j]] = j;
                ++C[Col[j]];
            }
        L[R[c]] = R[L[c]] = c;
    }

    bool dance(int d) {
        if(!R[0]) {
            ansd = d;
            return true;
        }
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i])
            if(C[i] < C[c]) c = i;
        remove(c);
        for(int i = U[c]; i != c; i = U[i]) {
            ans[d] = Row[i];
            for(int j = L[i]; j != i; j = L[j]) remove(Col[j]);
            if(dance(d+1)) return true;
            for(int j = R[i]; j != i; j = R[j]) resume(Col[j]);
        }
        resume(c);
        return false;
    }
};

DLX g;

int main()
{
#ifdef PIT
//freopen("", "r", stdin);
#endif // PIT
    int T, n, m;
    for(scanf("%d", &T); T; --T){
        scanf("%d %d", &n, &m);
        g.init(n,m);
        rep(i, 1, n+1) rep(j, 1, m+1) {
            int a;
            scanf("%d", &a);
            if(a) g.link(i,j);
        }
        if(!g.dance(0)) puts("No");
        else puts("Yes");

    }
    return 0;
}
