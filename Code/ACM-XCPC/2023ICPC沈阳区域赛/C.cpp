#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= r; i ++)
#define lop(x, y) for (auto x : y);

int x, y;
void solve() {
    std::cin >> x >> y;

    int ans = 0;
    for (x; x <= 2; x ++) {
        if (x >= 2 or y >= 2) {
            ans += 2;
        } else {
            ans ++;
        }
    }
    
    std::cout << ans << '\n';
}

auto INIT = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    INIT();

    int _ = 1;

    //for (std::cin >> _; _;_ --) 
        solve();

    return 0;
}

/*
0 1 

4

1 2 

4
*/