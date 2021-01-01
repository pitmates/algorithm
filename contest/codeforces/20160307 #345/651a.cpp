#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c = 0;
    cin >> a >> b;
    if(a == b && a == 1) c = 0;
    else {
        while(b) {
    //        printf("=== %d %d      ", a, b);
            if(a > b) swap(a, b);
    //        printf("=== %d %d \n", a, b);
            if(a < 1) break;

            if(b&1) {
                int d = (b / 2);
                a += d;
                c += d;
                b = 1;
            }
            else {
                int d;
                if(b > 2) d = b / 2 - 1, b = 2;
                else d = 1, b = 0;
                a += d;
                c += d;
              //  cout << "d = " << d << endl;
            }
        }
    }

    cout << c << endl;
    return 0;
}
