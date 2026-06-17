/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-30 14:25:46
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
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;

	int tot = 1;
	struct Edge {
		int to; int nxt; int w;
	};
	std::vector<int> head(2e6, -1);
	std::vector<Edge> G(2e6);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int N = n;
	for (int i = 1; i <= m; i ++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		int st = N + 1;
		for (int j = 1; j <= c; j ++) {
			int x;
			std::cin >> x;
			N ++;
			AddEdge(x, N, a);
			AddEdge(N, x, 0);
		}

		for (int j = st; j < N; j ++) {
			AddEdge(j, j + 1, b);
			AddEdge(j + 1, j, b);
		}
	}

	std::vector<int> dis(N + m + 1, INF);
	[&](int s) -> void {
		dis[s] = 0;
		struct Node {
			int id, d;
			bool operator < (const Node &a) const {
				return d > a.d;
			}
		};

		std::priority_queue<Node> pq;
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
	}(s);

	std::cout << (dis[t] == INF ? -1 : dis[t]) << '\n';
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