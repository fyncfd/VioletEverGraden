#include <bits/stdc++.h>

using i64 = long long;

void VioletEverGraden() {
    int n, m, r;
    std::cin >> n >> m >> r;

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
        int to; int nxt; int w;
    };
    std::vector<Edge> G(2 * m + 10);
    auto AddEdge = [&](int u, int v, int w = 0) -> void {
        G[tot].to = v;
        G[tot].nxt = head[u];
        G[tot].w = w;
        head[u] = tot ++;
    };

    int __ = n - 1;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;
        AddEdge(u, v); AddEdge(v, u);
    }

    std::vector<std::vector<int>> fa(31, std::vector<int> (n + 1, 0));
    std::vector<int> dep(n + 1, 0);
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        fa[0][u] = p;
        dep[u] = dep[p] + 1;

        for (int i = 1; i <= 30; i ++) {
            fa[i][u] = fa[i - 1][fa[i - 1][u]];
        }

        for (int i = head[u]; ~i; i = G[i].nxt) {
            int v = G[i].to;
            if (v == p) {
                continue;
            }
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, r, 0);

    auto LCA = [&](int u, int v) -> int {
        if (dep[u] > dep[v]) {
            std::swap(u, v);
        }
        int dif = dep[v] - dep[u];
        for (int i = 0; dif; dif >>= 1, i ++) {
            if (dif & 1) {
                v = fa[i][v];
            }
        }

        if (u == v) {
            return u;
        }

        for (int i = 30; i >= 0; i --) {
            if (fa[i][u] != fa[i][v]) {
                u = fa[i][u];
                v = fa[i][v];
            }
        }

        return fa[0][u];
    };

    __ = m;
    while (__ --) {
        int u, v;
        std::cin >> u >> v;

        std::cout << LCA(u, v) << '\n';
    }

/*
Test Sample

5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5

4
4
1
4
4


*/
}

signed main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}