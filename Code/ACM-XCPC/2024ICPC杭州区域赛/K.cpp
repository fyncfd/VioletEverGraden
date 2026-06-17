#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)

int n, m; ll k;
std::vector<int> a;

void solve() {
    std::cin >> n >> m >> k;
    a.resize(n * m + 1);
    rep(i, 1, n * m) {
        std::cin >> a[i];
    }

    int ans = 0;
    int temp = std::max(0LL, m - k);
    std::vector<std::vector<int>> p(n + 1);
    rep(i, 1, n * m) {
        //int x; std::cin >> x;
        int j = (a[i] - 1) / m;
        p[j].push_back(a[i]);
        if (p[j].size() == temp) {
            ans = i;
            break;
        }
    }
    std::cout << std::max(ans, m) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int _ = 1;
    std::cin >> _;

    while (_ --) {
        solve();
    }

    return 0;
}