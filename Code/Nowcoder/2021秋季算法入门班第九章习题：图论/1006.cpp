/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-28 22:37:14
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
    int N, M, C;
    std::cin >> N >> M >> C;

	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(N + 1, -1);
	std::vector<Edge> G(2 * (M + N * 20) + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = M;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v >> w;
		AddEdge(u, v, w);
	}

	int st, ed;
	std::cin >> st >> ed;

	for (int u = 1; u <= N; u ++) {
		for (int k = 0; (1 << k) <= N; k ++) {
			int v = u ^ (1 << k);
			if (v >= 1 && v <= N) {
				AddEdge(u, v, (u ^ v) * C);
			}
		}
	}

	std::vector<int> dis(N + 1, INF);
	[&](int s) -> void {
		struct Node {
			int id, d;
			bool operator < (const Node &a) const {
				return d > a.d;
			}
		};
		std::priority_queue<Node> pq;
		dis[s] = 0;
		pq.push({s, dis[s]});

		while (!pq.empty()) {
			auto [u, d] = pq.top();
			pq.pop();

			if (d > dis[u]) continue;

			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to, w = G[i].w;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pq.push({v, dis[v]});
				} 
			}
		}
	}(st);

	int ans = dis[ed];
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