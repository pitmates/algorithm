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
const int N = 2017;
const double eps = 1e-9;
const double pi = acos(-1.0);
#define sqr(x) ((x) * (x))

double R;//定长

struct point{

    double x, y;
    void read() { cin >> x >> y; }
    double friend dis(const point &a,const point &b) {
       return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    }
}p[N];

struct alpha{
    double v;
    bool flag;
    bool friend operator < (const alpha &a,const alpha &b) {
       return a.v < b.v;
    }
}alp[N*N];

void solve(int n, double r){
    R = r;
    rep(i, 0, n) p[i].read();
    int MAX = 0;
    rep(i, 0, n){
       int t = 0;
       rep(j, 0, n) {
           if(i == j) continue;
           double theta, phi, D;
           D = dis(p[i], p[j]);
           if(D > 2.0 * R) continue;

           theta = atan2(p[j].y - p[i].y,p[j].x - p[i].x);
           if(theta < 0) theta += 2 * pi;
           phi = acos(D / (2.0 * R));
           alp[t].v = theta - phi + 2 * pi;
           alp[t].flag = true;
           alp[t + 1].v = theta + phi + 2 * pi;
           alp[t + 1].flag = false;
           t += 2;
       }
       sort(alp,alp + t);
       int sum = 0;
       rep(j, 0, t) {
           if(alp[j].flag) sum ++;
           else sum --;
           if(sum > MAX) MAX = sum;
       }
    }
    cout << MAX + 1 << endl;
}

int main()
{
#ifdef PIT
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
#endif //PIT

    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    double r;
    cin >> n >> r;
    solve(n, r);
    return 0;
}
