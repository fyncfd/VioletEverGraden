/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-04 21:47:57
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
    int N, M, X;
    std::cin >> N >> M >> X;

	int tot = 1;
	struct Edge {
		int to; int nxt; int L, C;
	};
	std::vector<int> head(N + 1, -1);
	std::vector<Edge> G(2 * M + 10);
	auto AddEdge = [&](int u, int v, int L, int C) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].L = L;
		G[tot].C = C;
		head[u] = tot ++;
	};

	std::vector<int> c(M + 1);
	for (int i = 1; i <= M; i ++) {
		int u, v, L, C;
		std::cin >> u >> v >> L >> C;
		AddEdge(u, v, L, C); AddEdge(v, u, L, C);
		c[i] = C;
	}

	auto Dijkstra = [&](int c) -> int {
		std::vector<int> dis(N + 1, INF);
		struct Node {
			int id, d;
			bool operator < (const Node &a) const {
				return d > a.d;
			}
		};
		std::priority_queue<Node> pq;
		int s = 1;
		dis[s] = 0;
		pq.push({s, dis[s]});

		while (!pq.empty()) {
			auto [u, d] = pq.top();
			pq.pop();

			if (d > dis[u]) {
				continue;
			}

			// int C = G[u].C;
			// if (C < c) {
			// 	continue;
			// }

			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to, L = G[i].L, C = G[i].C;
				if (C < c) {
					continue;
				}
				if (dis[v] > dis[u] + L) {
					dis[v] = dis[u] + L;
					pq.push({v, dis[v]});
				}
			}
		}

		return dis[N];
	};

	int ans = INF;
	for (int i = 1; i <= M; i ++) {
		int res = Dijkstra(c[i]);
		if (res == INF) {
			continue;
		}
		ans = std::min(ans, res + X / c[i]);
	}

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