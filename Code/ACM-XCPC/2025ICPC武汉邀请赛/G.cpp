#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

int n, m;
std::vector<int> g;
void solve() {
    std::cin >> n >> m;
    g.resize(n + 1, std::vector<int> (m + 1));
    rep(i, 1, n) {
        std::cin >> g[i][j];
    }

    
    auto dfs = [&](auto &&self, int x, int y) {
        if (x == n and y == m) {
            return ;
        }


        
        self(self, nx, ny);
    }
}

auto __init__ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
};

signed main() {
    __init__();

    int _ = 1;
    // for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}