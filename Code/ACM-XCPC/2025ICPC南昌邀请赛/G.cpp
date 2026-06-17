#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = 1; i <= n; i ++)
#define red(i, l, r) for (int i = l; i >= n; i --)

const int MAXN = 2e5 + 10;
const ll MAXM = 1e9 + 10;
std::vector<pii> e[MAXN];

void solve() {
    int n, m, q; std::cin >> n >> m >> q;
    
    int __ = m;
    while (__ --) {
        int u, v, w; std::cin >> u >> v >> w;
        e[u].push_back({v, w});
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