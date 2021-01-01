#include <iostream>

using namespace std;

const int N = 1010;

int f[N], x[N], y[N];
bool v[N];
int n, d;
string s;

int find(int i) {
    if(i != f[i]) f[i] = find(f[i]);
    return f[i];
}

bool dis(int i, int a) {
    int w = x[i] - x[a];
    int z = y[i] - y[a];
    if(w * w + z * z <= d * d) return true;
    return false;
}

int main()
{
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; ++i) {
        f[i] = i;
        v[i] = false;
    }
    while(cin >> s) {
        int a, b;
        int u1, u2;
        if(s == "O") {
            cin >> a;
            v[a] = true;
            for(int i = 1; i <= n; ++i) {
                if(i != a && v[i] && dis(i, a)) {
                   u1 = find(i);
                   u2 = find(a);
                   f[u1] = u2;
                }
            }
        }
        else {
            cin >> a >> b;
            u1 = find(a);
            u2 = find(b);
            if(u1 == u2) cout << "SUCCESS" << endl;
            else cout << "FAIL" << endl;
        }
    }
    return 0;
}
