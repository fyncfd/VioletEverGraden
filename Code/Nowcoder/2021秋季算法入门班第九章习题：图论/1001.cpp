/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-27 21:57:20
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
    int n, p;
    std::cin >> n >> p;

    std::vector<int> C(n + 1), U(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> C[i] >> U[i];
    	if (!C[i]) C[i] -= U[i];
    }

    int tot = 1;
    std::vector<int> head(n + 1, -1);
    struct Edge {
    	int to, nxt, w;
    };
    std::vector<Edge> G(p + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
    	G[tot].nxt = head[u];
    	G[tot].to = v;
    	G[tot].w = w;
    	head[u] = tot ++;
    };

    int __ = p;
    std::vector<int> deg(n + 1, 0), outd(n + 1, 0);
    while (__ --) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	AddEdge(u, v, w);
    	deg[v] ++;
    	outd[u] ++;
    }

    std::vector<int> topo;
    [&]() -> void {
    	std::queue<int> q;
    	for (int i = 1; i <= n; i ++) {
    		if (deg[i] == 0) {
    			q.push(i);
    		}
    	}

    	while (!q.empty()) {
    		auto u = q.front();
    		q.pop();
    		topo.push_back(u);
    		for (int i = head[u]; ~i; i = G[i].nxt) {
    			int v = G[i].to;
    			deg[v] --;
    			if (deg[v] == 0) {
    				q.push(v);
    			}
    		}
    	}
    }();

    for (int i = 0; i < topo.size(); i ++) {
    	int u = topo[i];
    	if (C[u] > 0) {
    		for (int k = head[u]; ~k; k = G[k].nxt) {
    			int v = G[k].to, w = G[k].w;
    			C[v] += C[u] * w;
    		}
    	}
    }

    bool ok = true;
    for (int i = 1; i <= n; i ++) {
    	if (!outd[i] && C[i] > 0) {
    		std::cout << i << ' ' << C[i] << '\n';
    		ok = false;
    	}
    }

    if (ok) {
    	std::cout << "NULL\n";
    }

/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

5 6
1 0
1 0
0 1
0 1
0 1
1 3 1
1 4 1
1 5 1
2 3 1
2 4 1
2 5 1

3 1
4 1
5 1


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