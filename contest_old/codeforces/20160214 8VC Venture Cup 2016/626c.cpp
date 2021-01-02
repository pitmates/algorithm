#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(n <= m) cout << 3*m << endl;
    else {
        int s = 0;
        while(n - m > 1 && n > 2 && m) {
            n -= 3; m -= 1;
            s += 6;
        }
        if(n - m == 1) {
            if(n % 2 == 0) s += (n / 2 * 6  - 2);
            else s += n / 2 * 6 + 2;
        }
        else if( n == m) {
            if(n & 1) s += (n / 2 * 6 + 3);
            else s += n / 2 * 6;
        }
        else if(n) s += n * 2;
        else if(m) s += m * 3;
        cout << s << endl;
    }
    return 0;
}
