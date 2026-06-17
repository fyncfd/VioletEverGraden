/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-07 20:38:13
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
    int T = 1;
    std::cin >> T;
    for (int _ = 1; _ <= T; _ ++) {
	    int n, m;
	    std::cin >> n >> m;

	    struct Edge {
	    	int v, w;
	    };
		std::vector<std::vector<Edge>> g(n + m + 1);
		int __ = m, N = n;
		while (__ --) {
			int w, x;
			std::cin >> w >> x;

			N ++;
			for (int i = 1; i <= x; i ++) {
				int u, v = N;
				std::cin >> u;
				g[u].push_back({v, 0});
				g[v].push_back({u, w});
			}
		}

		auto Dijkstra = [&](int s) -> std::vector<i64> {
			std::vector<i64> dis(N + 1, INF);
			struct Node {
				i64 id, d;
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

				if (d > dis[u]) {
					continue;
				}

				for (auto [v, w] : g[u]) {
					if (dis[v] > dis[u] + w) {
						dis[v] = dis[u] + w;
						pq.push({v, dis[v]});
					}
				}
			}
			return dis;
		};

		std::vector<i64> dis1 = Dijkstra(1);
		std::vector<i64> dis2 = Dijkstra(n);

		i64 res = INF;
		std::vector<int> ans;
		std::vector<int> D(n + 1, INF);
		for (int u = 1; u <= n; u ++) {
			if (dis1[u] == INF || dis2[u] == INF) {
				continue;
			}
			i64 tmp = std::max(dis1[u], dis2[u]);
			res = std::min(res, tmp);
			D[u] = tmp;
		}

		for (int u = 1; u <= n; u ++) {
			if (D[u] == res) {
				ans.push_back(u);
			}
		}

		if (res == INF) {
			std::cout << "Case #" << _ << ": Evil John\n"; 
			continue;
		}

		std::cout << "Case #" << _ << ": " << res <<  "\n"; 
		for (int i = 0; i < ans.size(); i ++) {
			std::cout << ans[i] << " \n"[i + 1 == ans.size()];
		}
	}
    return 0;
}