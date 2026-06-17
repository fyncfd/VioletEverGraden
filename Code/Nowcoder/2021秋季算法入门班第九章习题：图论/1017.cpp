/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-05 14:35:17
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
		int to; int nxt; int w;
	};
	std::vector<int> head(N + 1, -1);
	std::vector<Edge> G(2 * M + 10);
	auto AddEdge = [&](int u, int v, int w)-> void {
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

	int ans = 0;
	[&](int s) -> void {
		std::vector<int> dis(N + 1, INF);
		struct Node {
			int id, d;
			bool operator < (const Node &a) const {
				return d < a.d;
			}
		};
		std::priority_queue<Node> pq;
		dis[s] = 0;
		pq.push({s, dis[s]});

		while (!pq.empty()) {
			auto [u, d] = pq.top();
			pq.pop();

			if (d > dis[u]) {
				continue;
			}

			for (int i = head[u]; ~i; i = G[i].nxt) {
				int v = G[i].to, w = G[i].w;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pq.push({v, dis[v]});
				}
			}
		}

		for (int i = 1; i <= N; i ++) {
			ans = std::max(ans, dis[i]);
		}
	}(X);

	std::cout << 2 * ans << '\n';
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