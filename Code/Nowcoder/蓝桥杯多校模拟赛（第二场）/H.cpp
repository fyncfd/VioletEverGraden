/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-06 15:03:33
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
	std::vector<Edge> G(2 * m + 10);
	auto AddEdge = [&](int u, int v, int w = 0) -> void {
		G[tot].to = v;
		G[tot].nxt = head[u];
		G[tot].w = w;
		head[u] = tot ++;
	};

	int __ = m;
	while (__ --) {
		int u, v, w;
		std::cin >> u >> v >> w;
		// std::cin >> u >> v >> w;
		// AddEdge(u, v); AddEdge(v, u);
		AddEdge(u, v, w); AddEdge(v, u, w);
	}

	int k;
	std::cin >> k;

	std::vector<int> st(k + 1);
	for (int i = 1; i <= k; i ++) {
		std::cin >> st[i];
	}

	int tot0 = 1;
	struct Edge0 {
		int to; int nxt; int w;
	};
	std::vector<int> head0(n + 1, -1);
	std::vector<Edge0> G0(2 * m + 10);
	auto AddEdge0 = [&](int u, int v, int w = 0) -> void {
		G0[tot0].to = v;
		G0[tot0].nxt = head[u];
		G0[tot0].w = w;
		head0[u] = tot0 ++;
	};

	for (int i = 1; i <= k; i ++) {
		int u = st[i];
		for (int j = head[u]; ~j; j = G[j].nxt) {
			int v = G[j].to; int w = G[j].w;
			AddEdge0(u, v, w); AddEdge0(v, u, 0);
		}
	}

	// std::map<i64, std::map<i64, i64>> dis;
	std::vector<std::vector<i64>> dis(n + 1, std::vector<i64> (n + 1, LINF));
    auto Dijkstra = [&](int s) -> void {
        dis[s][s] = 0;
        struct node {
            int id; i64 d;
            bool operator < (const node &a) const {
                return d > a.d;
            }
        };
        std::priority_queue<node> heap;
        heap.push({s, dis[s][s]});

        while (!heap.empty()) {
            auto [u, d] = heap.top();
            heap.pop();

            if (d > dis[s][u]) continue;
            for (int i = head[u]; ~i; i = G[i].nxt) {
                int v = G[i].to; int w = G[i].w;
                if (dis[s][v] > dis[s][u] + w) {
                    dis[s][v] = dis[s][u] + w;
                    heap.push({v, dis[s][v]});
                }
            }
        }
    };

    for(int i = 1; i <= k; i ++) {
    	Dijkstra(st[i]);
    }

	i64 ans = LINF;
	for (int i = 1; i <= k; i ++) {
	    for (int j = i + 1; j <= k; j ++) {
	        ans = std::min(ans, dis[st[i]][st[j]]);
	    }
	}

	std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1
5 6
1 2 1
2 3 3
3 1 3
2 5 1
2 4 2
4 3 1
3
1 3 5

2


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