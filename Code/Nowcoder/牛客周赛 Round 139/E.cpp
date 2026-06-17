/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-07 21:10:41
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
    int n;
    std::cin >> n;

/*
* @Author: AlgoStruggler
* 链式前向星建图，AddEdge函数默认构造无边权的边。
* @Create Time: 2025-02-03 13:10:02
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
* 愿幸运女神与最纯粹的前行者同在。
*/
	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(n + 1, -1);
	std::vector<Edge> G(2 * n + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = n - 1;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v;
		// std::cin >> u >> v >> w;
		AddEdge(u, v); AddEdge(v, u);
		// AddEdge(u, v, w); AddEdge(v, u, w);
	}

	std::vector<int> ans(n + 1, 0);
	std::vector<int> sz(n + 1, 1);
	std::vector<std::vector<int>> dp(n + 1, std::vector<int> (2, 0));
	auto dfs = [&](auto &&dfs, int u, int fa) -> void {
		sz[u] = 1;
		dp[u][0] = 0;
		dp[u][1] = 1;

		for (int i = head[u]; ~i; i = G[i].nxt) {
			int v = G[i].to;
			if (v == fa) {
				continue;
			}

			dfs(dfs, v, u);

			sz[u] += sz[v];

	        dp[u][0] += std::max(dp[v][0], dp[v][1]);
	        dp[u][1] += dp[v][0];
		}

	    int max = std::max(dp[u][0], dp[u][1]);
	    ans[u] = sz[u] - max;
	};

	dfs(dfs, 1, -1);


	for (int i = 1; i <= n; i ++) {
		std::cout << ans[i] << " \n"[i == n];
	}
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1
5
1 2
2 3
3 4
3 5

2 1 1 0 0


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    // std::cout << std::fixed << std::setprecision(12), std::cerr << std::fixed << std::setprecision(12);

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}