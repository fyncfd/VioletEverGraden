#include "bits/stdc++.h"

using ll = long long;
using ull = unsigned long long;
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i --)

#define int long long
int n, k;
ll a[5015];

void solve() {
    std::cin >> n >> k;
    rep(i, 1, n) {
        std::cin >> a[i];
    }

    ll ans = 0;
    if (k == 1) {
        ans = a[1] + a[n];
        if (n > 2) {
            ans = std::max(ans, *max_element(a + 2, a + n) + std::max(a[1], a[n]));
        }
        std::cout << ans << '\n';
        return ;
    }

    std::sort(a + 1, a + 1 + n);
    red(i, n, n - k) {
        ans += a[i];
    }
    std::cout << ans << '\n';
}

signed main() {
    std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    std::cin >> _;

    while (_ --) {
        solve();
    }

    return 0;
}