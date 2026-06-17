#include <bits/stdc++.h>

using ll = long long;
using i64 = long long;
#define int long long

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void solve() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    std::vector<int> x(n * m + 5, 0);
    for (int i = 1; i <= n * m; i++) {
        int k;
        std::cin >> k;
        x[k]++;
    }
    sort(x.begin() + 1, x.end(), std::greater<int>());
    std::vector<int> pre(n * m + 5, 0);
    i64 ans = 0;
    for (int i = n * m; i >= 1; i--) {
        pre[i] = pre[i + 1] + a * x[i];
        ans = std::max((i64)pre[i], ans);
    }
    i64 k = 0;
    for (int i = 1; i <= n * m; i++) {
        k += std::min(a, b * (i - 1)) * x[i];
        ans = std::min(ans, pre[i + 1] + b * i * x[0] + k);
    }
    std::cout << ans << "\n";
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
3
1 2 3 2
0 1
2 2 1 1
1 0
2 3
3 3 5 3
2 4 4
4 1 4
4 4 2

2
3
11



*/