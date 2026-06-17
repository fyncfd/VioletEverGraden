/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-28 15:58:15
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
    int N, M;
    std::cin >> N >> M;

	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(N + 1, -1);
	std::vector<Edge> G(2 * M + 10);
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
		AddEdge(u, v, w); AddEdge(v, u, w);
	}

	std::vector<std::vector<int>> dis(N + 1, std::vector<int> (N + 1, INF));
	auto Dijkstra = [&](int s) -> void {
		dis[s][s] = 0;
		struct Node {
			int id, d;
			bool operator < (const Node &a) const {
				return d > a.d;
			}
		};
		std::priority_queue<Node> pq;
		pq.push({s, dis[s][s]});

		while (!pq.empty()) {
			auto [u, d] = pq.top();
			pq.pop();

			if (d > dis[s][u]) {
				continue;
			}

			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to, w = G[i].w;
				if (dis[s][v] > dis[s][u] + w) {
					dis[s][v] = dis[s][u] + w;
					pq.push({v, dis[s][v]});
				}
			}
		}
	};

	for (int i = 1; i <= N; i ++) {
		Dijkstra(i);
	}

/*	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= N; j ++) {
			std::cout << dis[i][j] << " \n"[j == dis[i].size()];
		}
	}*/

	int ans = -1;
	for (int j = 1; j <= N; j ++) {
		int i1 = -1, i1d = -1;
		for (int i = 1; i <= N; i ++) {
			if (i == j || dis[i][j] == INF) {
				continue;
			}
			int d = dis[i][j];
			if (d > i1d) {
				i1 = i;
				i1d = d;
			}
		}

		int i2 = -1, i2d = -1;
		for (int i = 1; i <= N; i ++) {
			if (i == j || dis[i][j] == INF || i == i1) {
				continue;
			}
			int d = dis[i][j];
			if (d > i2d) {
				i2 = i;
				i2d = d;
			}
		}

		int k1 = -1, k1d = -1;
		for (int k = 1; k <= N; k ++) {
			if (k == j || dis[j][k] == INF) {
				continue;
			}
			int d = dis[j][k];
			if (d > k1d) {
				k1 = k;
				k1d = d;
			}
		}

		int k2 = -1, k2d = -1;
		for (int k = 1; k <= N; k ++) {
			if (k == j || dis[j][k] == INF || k == k1) {
				continue;
			}
			int d = dis[j][k];
			if (d > k2d) {
				k2 = k;
				k2d = d;
			}
		}

		if (i1 != -1 && k1 != -1) {
			if (i1 != k1) {
				ans = std::max(ans, dis[i1][j] + dis[j][k1]);
			} else {
				if (i2 != -1) {
					ans = std::max(ans, dis[i2][j] + dis[j][k1]);
				}
				if (k2 != -1) {
					ans = std::max(ans, dis[i1][j] + dis[j][k2]);
				}
			}
		}
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

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}