/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-16 14:12:22
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
    int b, n, m, k;
    std::cin >> b >> n >> m >> k;

    struct pii {
    	int to, w1, w2;
    };
    std::vector<std::vector<pii>> g(n + 1);
    for (int i = 1; i <= m; i ++) {
    	int u, v, w1, w2;
    	std::cin >> u >> v >> w1 >> w2;
    	g[u].push_back({v, w1, w2});
    	g[v].push_back({u, w1, w2});
    }

    std::vector<int> dis(n + 1, INF);
    std::vector<int> emo(n + 1, 0);
    auto Dijkstra = [&](int s) -> void {
    	struct Node {
    		int id; int d; int e;
    		bool operator < (const Node &a) const {
	            if (d != a.d) return d > a.d;
	            return e < a.e;
    		}
    	};
    	std::priority_queue<Node> pq;

    	dis[s] = 0; emo[s] = 0;
    	pq.push({s, dis[s], emo[s]});

    	while (!pq.empty()) {
    		auto [u, D, E] = pq.top();
    		pq.pop();
 			if (D != dis[u] || E != emo[u]) continue;
    		for (auto [v, w1, w2] : g[u]) {
    			if (dis[v] > dis[u] + w1) {
    				dis[v] = dis[u] + w1;
    				emo[v] = emo[u] + w2;
    				pq.push({v, dis[v], emo[v]});
    			} else if (dis[v] == dis[u] + w1) {
    				if (emo[v] <  emo[u] + w2) {
    					emo[v] = emo[u] + w2;
    					pq.push({v, dis[v], emo[v]});
    				}
    			}
    		}
    	}
    };

    for (int i = 1; i <= k; i ++) {
    	int s;
    	std::cin >> s;

        dis.assign(n + 1, INF);
        emo.assign(n + 1, 0);
    	Dijkstra(s);

    	std::vector<int> des;
    	for (int j = 1; j <= n; j ++) {
    		if (dis[j] <= b and j != s) {
    			des.push_back(j);
    		}
    	}

    	int max = -1;
    	for (auto x : des) {
    		max = std::max(max, emo[x]);
    	}

    	std::vector<int> ans;
    	for (auto x : des) {
    		if (emo[x] == max) {
    			ans.push_back(x);
    		}
    	}

    	if (des.size() == 0) {
    		std::cout << "T_T\n";
    	} else {
    		for (int k = 0; k < des.size(); k ++) {
    			std::cout << des[k] << " \n"[k + 1 == des.size()];
    		}
    		for (int k = 0; k < ans.size(); k ++) {
    			std::cout << ans[k] << " \n"[k + 1 == ans.size()];
    		}
    	}
    }
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