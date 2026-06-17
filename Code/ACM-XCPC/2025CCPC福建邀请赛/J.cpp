#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l ;i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)


void solve() {
    ll n; std::cin >> n;

    int ans = 0;
    std::vector<int> op;
    std::map<int, bool> vis;
    auto dfs = [&](auto &&self, ll n) {
        ll p = sqrt(n);
        if (p * p == n) {
            return ;
        }

        rep(i, 1, n) {
            if (n % i == 0 and !vis[i]) {
                self(self, n + i);
                ans ++;
                op.push_back(i);
                vis[i] = true;
            }
        }
    };
    std::cerr << ans << '\n';
    dfs(dfs, n);
    std::cout << "YES\n";
    rep(i, 0, ans - 1) {
        std::cout << op[i] << " \n"[i == ans - 1];
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

/*
2
2025
182
*/