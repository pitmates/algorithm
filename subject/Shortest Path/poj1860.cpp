#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 127;

int n, m, s;
double v;

struct edge{
    int from, to;
    double rate;
    double com;
    edge(int a = 0, int b = 0, double r = 0.0, double c = 0.0) : from(a), to(b), rate(r), com(c) {}
};

edge es[N<<1];
double d[N];
int  E;

bool Bellman() {
    for(int i = 1; i <= n; ++i) d[i] = 0.0;
    d[s] = v;

    for(int k = 1; k <= n; ++k) {
        bool update = false;
        for(int i = 0; i < E; ++i) {
            edge e = es[i];
            if(d[e.to] < (d[e.from] - e.com) * e.rate) {
                d[e.to] = (d[e.from] - e.com) * e.rate;
                update = true;
            }
        }
        if(!update) break;
    }

    for(int i = 0; i < E; ++i) {
        edge e = es[i];
        if(d[e.to] < (d[e.from] - e.com) * e.rate)
            return true;
    }
    return false;

}

int main()
{
#ifdef PIT
freopen("poj1860.in", "r", stdin);
#endif // PIT
    while(~scanf("%d %d %d %lf", &n, &m, &s, &v)) {
        E = 0;
        int a, b;
        double rab, cab, rba, cba;
        for(int i = 0; i < m; ++i) {
            scanf("%d %d %lf %lf %lf %lf", &a, &b, &rab, &cab, &rba, &cba);
            es[E++] = edge(a, b, rab, cab);
            es[E++] = edge(b, a, rba, cba);
        }
        puts(Bellman() ? "YES" : "NO");
    }
    return 0;
}

