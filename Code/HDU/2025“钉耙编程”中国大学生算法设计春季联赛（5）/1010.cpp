#include <bits/stdc++.h>

using ll = long long;

int n;
int u, v, w;

void solve() {
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for (int i = 0; i < n - 1; i ++) {
        std::cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    std::vector<int> p(n + 1, -1);
    std::queue<int> q;
    p[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w] : adj[u]) {
            if (p[v] == -1) {
                p[v] = (p[u] + w) % 2;
                q.push(v);
            }
        }
    }

    ll cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i ++) {
        if (p[i] == 0) {
            cnt0++;
        } 
        else {
            cnt1++;
        }
    }

    ll ans = cnt0 * cnt0 * cnt0 + cnt1 * cnt1 * cnt1;
    std::cout << ans << '\n';
}

signed main() {
    std::cin.tie(nullptr) ->
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int _ = 1;
    std::cin >> _;

    while (_ --) {
        solve();
    }

    return 0;
}