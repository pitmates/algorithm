#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {42, 13, 123, 55, 666, 17};
    vector<int > b(10, 0);
    int x = 0;
    for (int i = 0; i < 6; ++i) {
        x ^= a[i];
        int z = a[i], c = 0;
        while (z) {
            b[c++] += (z&1);
            z >>= 1;
        }
    }
    cout << x << endl;
    a[1] += 11; a[2] += 389; a[3] += 73; a[4] += 6; a[5] += 1;
    int y = 0;
    for (int i = 0; i < 6; ++i) {
        y ^= a[i];
    }
    cout << y << endl;
    for (auto qa : b) cout << qa << " ";
    cout << endl;
}