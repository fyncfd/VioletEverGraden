#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, y;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    while (_ --) {
        cin >> n >> x >> y;

        if ((y & ~x) != 0) {
            cout << "NO\n";
            continue;
        }

        if (n == 1) {
            if (x == y) {
                cout << "YES\n" << x << '\n';
            } 
            else {
                cout << "NO\n";
            }
            continue;
        }

        int a = 0, b = 0;
        for (int i = 0; i <= 30; ++i) {
            int m = 1 << i;
            if ((x & m) == 0) continue;
            if (y & m) {
                a |= m;
            } 
            else {
                a |= m;
                b |= m;
            }
        }

        if (a < 1 || b < 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        if (n % 2 == 1) {
            cout << y;
            for (int i = 1; i < n; ++i) {
                cout << ' ' << x;
            }
        } 
        else {
            cout << a << ' ' << b;
            for (int i = 2; i < n; ++i) {
                cout << ' ' << x;
            }
        }
        int p = 1;
        cout << " \n"[p == 1];
    }
    return 0;
}