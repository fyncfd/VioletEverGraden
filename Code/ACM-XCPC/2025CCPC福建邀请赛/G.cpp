#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define int long long

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l ;i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)


void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<int> a(n + 1);
    rep(i, 1, n) {
        std::cin >> a[i];
    }
    ll k; std::cin >> k;
    int __ = m;
    std::vector<int> b(n + 1);
    b[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] > 0) {
            b[i] = a[i] - a[i - 1];
        } else {
            b[i] = 0;
        }
    }
    std::vector<int> s(n + 1);
    s[1] = 0;
    for (int i = 2; i <= n; i++) {
        s[i] += s[i - 1] + b[i];
    }
    while (__ --) {
        int s1, t; std::cin >> s1 >> t;
        std::cout << s[t] - s[s1] + k << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    // for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}