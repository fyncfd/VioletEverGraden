#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l ;i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)


void solve() {
    int n; std::cin >> n;
    std::vector<ll> a(2 * n + 1);
    rep(i, 1, 2 * n) {
        std::cin >> a[i];
    }

    std::vector<ll> oddpre(2 * n + 1);
    std::vector<ll> evenpre(2 * n + 1);
    rep(i, 1, 2 * n) {
        if (i & 1) {
            oddpre[i] = oddpre[i - 2] + a[i];
        } else {
            evenpre[i] = evenpre[i - 2] + a[i];
        }
    }

    rep(i, 1, 2 * n) {
        rep(j, 1, 2 * n) {
            
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}