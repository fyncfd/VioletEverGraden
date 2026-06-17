#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define red(i, l, r) for (int i = l; i >= r; i--)

#define int ll
int n;

void voilet() {
    std::cin >> n;

    ll r = round(cbrt(n));
    if (r * r * r == n) {
        std::cout << -1 << '\n';
        return;
    }

    ll ma = cbrt(n) + 1;
    for (ll a = 1; a <= ma; ++a) {
        if (n % a != 0) {
            continue; 
        }

        ll b = n / a;

        ll temp = 4 * b - a * a;
        if (temp < 0) {
            continue;
        }

        ll d = 3 * temp;
        ll k = sqrt(d);
        if (k * k != d) {
            continue;
        }

        ll num = -3 * a + k;
        if (num <= 0) {
            continue;
        }
        if (num % 6 != 0) {
            continue;
        }

        ll y = num / 6;
        ll x = y + a;

        if (x * x * x - y * y * y == n) {
            std::cout << x << " " << y << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';
}

signed main() {
    std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    // std::cin >> _;

    while (_--) {
        voilet();
    }

    return 0;
}