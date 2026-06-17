#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

void solve() {
    int n, k; std::cin >> n >> k;
    vector<double> r(n + 10, 0), c(n + 10, 0);
    double lo, hi; double p;
    std::cin >> r[0] >> c[0] >> p >> lo >> hi;

    int __ = k;
    while (__ --) {
        int x; double y;
        std::cin >> x >> y;
        r[x] = y;
    }

    rep(i, 1, n) {
        if (!r[i]) {
            r[i] = lo;
        }
    }

    rep(i, 1, n) {
        c[i] = 1.0 * p * c[i - 1] + (1 - p) * r[i - 1];
    }

    double ans = 0;
    rep(i, 1, n) {
        ans += (c[i] - r[i]);
    }

    std::cout << ans << '\n';
}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    std::cout << std::fixed << std::setprecision(12);

    int _ = 1;
    for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}


/*
2
3 2
5 6 0.5 1 10
1 4
2 5
5 2
10 5 0.5 3 12
1 4 
3 6


5.1250000000
7.9062500000

5.1250000000
7.9062500000

*/