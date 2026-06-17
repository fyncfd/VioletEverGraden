/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-28 14:37:40
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#pragma GCC optimize("O3,unroll-loops,Ofast,inline")
#include "bits/stdc++.h"

using i64 = int64_t;
using i128 =  __int128_t;

using u32 = uint32_t;
using u64 = uint64_t;
using u128 = __uint128_t;

using f32 = float;
using f64 = double;
using f80 = long double;

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998'244'353LL;
constexpr i64 MOD = 1e9 + 7;

static inline void VioletEverGraden() {
    int n, m;
    std::cin >> n >> m;

	// int tot = 1;
	// struct Edge {
	// 	int to; int nxt; int w;
	// };
	// std::vector<int> head(n + 1, -1);
	// std::vector<Edge> G(5e6 + 10);
	// auto AddEdge = [&](int u, int v, int w = 0) -> void {
	// 	G[tot].to = v;
	// 	G[tot].nxt = head[u];
	// 	G[tot].w = w;
	// 	head[u] = tot ++;
	// };
    int tot = n;  // 原节点 1~n
    std::vector<std::vector<int>> g(n + m + 5);
    std::vector<int> deg(n + m + 5, 0);

    while (m--) {
        int s;
        std::cin >> s;

        std::vector<bool> vis(n + 1, false);
        std::vector<int> p(s + 1);

        for (int i = 1; i <= s; i++) {
            std::cin >> p[i];
            vis[p[i]] = true;
        }

        int id = ++tot;  // 虚拟点

        // 未停点 → id
        for (int u = p[1]; u <= p[s]; u++) {
            if (!vis[u]) {
                g[u].push_back(id);
                deg[id]++;
            }
        }

        // id → 停靠点
        for (int i = 1; i <= s; i++) {
            int v = p[i];
            g[id].push_back(v);
            deg[v]++;
        }
    }

	int ans = 0;
	[&]() -> void {
/*		struct Node {
			int id, pts;
		};*/
		std::vector<int> dp(tot + 1, 1);
		std::queue<int> q;

		for (int i = 1; i <= tot; i ++) {
			if (deg[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			
			for (auto v : g[u]) {
			if (v > n) dp[v] = std::max(dp[v], dp[u]);
			else dp[v] = std::max(dp[v], dp[u] + 1); 
				deg[v] --;
				if (deg[v] == 0) {
					q.push(v);
				}
			}
		}

		for (int i = 1; i <= n; i ++) {
			ans = std::max(ans, dp[i]);
		}
	}();

	std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}