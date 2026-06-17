#include <bits/stdc++.h>

using ll = long long;
#define rep(i, l, r) for (int i = 1; i <= r; i ++)
#define red(i, l, r) for (int i = l; i >= r; i ++)
#define lop(x, y) for (auto x : y);

int n;
int u, v;
void solve() {
    std::cin >> n;
    
    std::vector<int> deg(n + 1, 0);
    int m = n - 1;
    while (m --) {
        std::cin >> u >> v;
        deg[u] ++; deg[v] ++;
    }

    int ans = 0;
    rep(i, 1, n) {
        if (deg[i] != 1) {
            ans ++;
        }
    }

    if (ans == 0) {
        std::cout << "Bob\n";
        return ;
    }

    if (ans & 1) {
        std::cout << "Bob\n";
    } else {
        std::cout << "Alice\n";
    }
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
4
1 2
2 3
3 4

Alice




4
1 2
1 3
1 4

Bob
*/