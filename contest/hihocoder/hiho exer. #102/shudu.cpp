#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (int) j; i < (int) k; ++i)
#define ll long long
#define mp make_pair

using namespace std;
const int N = 400;
const int M = 320000;

struct DLX {
    int n, m;
    int size;
    int U[M], D[M], L[M], R[M], Col[M], Row[M];
    int H[N<<1], C[N];
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
bool cov[N<<1][N];
int t;
int sd[10][10];
int ve[N<<1][2]; // ve[i][0] ==> (x, y); ve[i][1] ==> num

void insert(int x, int y, int k) {
    int z = (x - 1) * 9 + y;
    ve[t][0] = z; cov[t][z] = 1;
    z = (x-1) * 9 + k + 81; //row
    ve[t][1] = z; cov[t][z] = 1;
    z = (y-1) * 9 + k + 162; //col
    cov[t][z] = 1;
    int w = (x-1) / 3 * 3 + (y-1) / 3 + 1;
    z = (w-1) * 9 + k + 243; //gong
    cov[t++][z] = 1;
}

void change() { // sd to cov
    /**
    * 1-81 col: 每个格子填一个数字 N = (x - 1) * 9 + y
    * 82-162 col: 每一行每个数字都出现一次 N = (x-1) * 9 + j + 81
    * 163-243 col: 每一列每个数字都出现一次 N = (y-1) * 9 + j + 162
    * 244-324 col: 每一宫每个数字都出现一次 w = (x-1) / 3 * 3 + (y-1) / 3 + 1; N = (w-1) * 9 + j + 243
    * x = (N - 1 - (0 | 81 | 162 | 243)) / 9 + 1; y = (...) % 9 + 1. {-1 because (j = 1 to 9)}
    **/
    t = 1; memset(cov, 0, sizeof cov);
    rep(x, 1, 10) rep(y, 1, 10) {
        if(sd[x][y]) insert(x, y, sd[x][y]);
        else rep(i, 1, 10) insert(x, y, i);
    }
    return ;
}

int main()
{
#ifdef PIT
freopen("shudu.in", "r", stdin);
//freopen("x.out", "w", stdout);
#endif // PIT

    int T, n, m;
    for(scanf("%d", &T); T; --T) {
        rep(i, 1, 10) rep(j, 1, 10) scanf("%d", sd[i]+j);
        change(); n = 729, m = 324;
        g.init(n, m);
        rep(i, 1, n+1) rep(j, 1, m+1)
            if(cov[i][j]) g.link(i, j);
        g.dance(0);
        rep(i, 0, g.ansd) {
            int z = g.ans[i], w = ve[z][0] - 1;
            int x = w / 9 + 1, y = w % 9 + 1;
            w = ve[z][1] - 1 - 81;
            sd[x][y] = w % 9 + 1;
        }
        rep(i, 1, 10) {
            rep(j, 1, 10) printf(j == 1 ? "%d" : " %d", sd[i][j]);
            puts("");
        }
    }
    return 0;
}
