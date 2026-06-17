#include <bits/stdc++.h>

using ll = long long;

#define rep(i, l, r, x) for (int i = l; i <= r; i += x)

void solve() {
    int n;
    std::cin >> n;

    std::map<int, std::set<int>> hash;
    int __ = n;
    while (__ --) {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (c < 240) {
            if (hash[a].count(b)) {
                std::cout << 0 << '\n';
            } else {
                hash[a].insert(b);
                std::cout << b << '\n';
            }
        } else {
            if ((int)hash[a].size() < 3) {
                if (hash[a].count(b)) {
                    std::cout << 0 << '\n';
                } else {
                    hash[a].insert(b);
                    std::cout << b << '\n';
                }
            } else {
                std::cout << 0 << '\n';
            }
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
8
1 1 10
1 2 20
1 3 30
1 4 250
1 5 260
1 6 270
1 7 280
2 1 290
*/