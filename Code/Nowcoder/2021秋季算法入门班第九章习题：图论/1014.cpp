/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-04 19:50:58
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
    int D, P, C, F, S;
    std::cin >> D >> P >> C >> F >> S;

    int tot = 1;
    std::vector<int> head(C + 1, -1);
    struct Edge {
    	int to, nxt, w;
    };
    std::vector<Edge> G(P + F + 10);
    auto AddEdge = [&](int u, int v, int w) -> void {
    	G[tot].to = v;
    	G[tot].nxt = head[u];
    	G[tot].w = w;
    	head[u] = tot ++;
    };

    int __ = P;
    while (__ --) {
    	int u, v;
    	std::cin >> u >> v;
    	AddEdge(u, v, D);
    }

    __ = F;
    while (__ --) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	AddEdge(u, v, D - w);
    }

    std::vector<int> dis(C + 1, 0), cnt(C + 1, 0);
    std::vector<bool> vis(C + 1, false);
    bool ok = true;
    [&](int s) -> void {
    	std::queue<int> q;
    	dis[s] = D, vis[s] = true;
    	q.push(s);

    	while(!q.empty()) {
    		int u = q.front();
    		q.pop();
    		vis[u] = false;
    		for (int i = head[u]; ~i; i = G[i].nxt) {
    			int v = G[i].to, w = G[i].w;
    			if (dis[v] < dis[u] + w) {
    				dis[v] = dis[u] + w;
    				cnt[v] = cnt[u] + 1;
    				if (cnt[v] >= C) {
    					ok = false;
    				}
    				if (!vis[v]) {
    					q.push(v);
    					vis[v] = true;
    				}
    			}
    		}
    	}
    }(S);

    int ans = *std::max_element(dis.begin() + 1, dis.end());
    if (ok) {
    	std::cout << ans << '\n';
    } else {
    	std::cout << -1 << '\n';
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