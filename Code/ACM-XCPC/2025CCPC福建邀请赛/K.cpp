#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define red(i, l, r) for (int i = l ;i >= r; i --)
#define FOR(i, l, r, x) for (int i = l; i <= r; i += x)
#define ROF(i, l, r, x) for (int i = l; i >= r; i -= x)


void solve() {
    int n; std::cin >> n;

    int __ = n - 1;
    std::vector<int> p(n + 1, -1);
    struct pii { int v; int w; };
    std::map<int, std::vector<pii>> hash; 
    while (__ --) {
        int u, v, w; std::cin >> u >> v >> w;
        
        hash[u].push_back({v, w});
        hash[v].push_back({u, w});
    }

    for (auto x : hash) {
        auto [p, q] = x;
        if (q.size() == 1) {
            
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int _ = 1;
    //for (std::cin >> _; _; _ --) 
        solve();

    return 0;
}

/*
5
1 2 5
1 3 4
2 5 7
3 4 2

YES
3 2 1 1 5
*/