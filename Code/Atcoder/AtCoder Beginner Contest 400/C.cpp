#include <bits/stdc++.h>

using ll = long long;

ll n;

void solve() {
    std::cin >> n;

    ll temp = 1;
    ll ndd = 0;
    while (temp * 2 <= n) {
        temp *= 2;
        ndd ++;
        ll p = 1LL << e;
        ll x = n / p;
        if (x < 1) {
            continue;
        }
        ll max = sqrt(x);
        while (max * max > x) {
            max --;
    }

    ll ans = 0;
    for (int e = 1; e <= ndd; e ++) {
        }
        while ((max + 1) * (max + 1) <= x) {
            max ++;
        }

        ll odd = (max + 1) / 2;
        ans += odd;
    }

    std::cout << ans << '\n';    
}

signed main() {
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _ = 1;
    //std::cin >> _;

    while (_ --) {
        solve();
    }

    return 0;
}
/*

20

5

400

24

1234567890

42413

*/