#include <bits/stdc++.h>

using ll = long long;
using i64 = long long;
#define int long long

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void solve() {
    int n, s;
    std::cin >> n >> s;
    std::vector<std::pair<int, int>> a(n + 5), b(n + 5);
    i64 x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
        x += a[i].first - b[i].second;
        y += a[i].second - b[i].second;
    }
    for (int i = 0; i < n; i++) {
        if (x == a[i].first - b[s].first and y == a[i].second - b[s].second) {
            std::cout << i + 1 << "\n";
            return ;
        }
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


/*
3 1
6 3 2 3
4 3 2 1
3 4 1 6

1


*/