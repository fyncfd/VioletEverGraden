/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 12:07:04
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
    int V, E, K;
    std::cin >> V >> E >> K;

    std::vector<std::vector<int>> g(V + 1);
    for (int i = 1; i <= E; i ++) {
    	int u, v;
    	std::cin >> u >> v;

    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    int N;
    std::cin >> N;

    while (N --) {
    	std::vector<int> c(V + 1);
    	std::set<int> hash;
    	for (int i = 1; i <= V; i ++) {
    		std::cin >> c[i];
    		hash.insert(c[i]);
    	}

    	if (hash.size() != K) {
    		std::cout << "No\n";
    		continue;
    	}

    	std::vector<bool> vis(V + 1, false);
    	bool ok = true;
    	auto dfs = [&](auto &&dfs, int u) -> void {
    		vis[u] = true;
    		for (auto v : g[u]) {
				if (c[v] == c[u]) {
					ok = false;
					return ;
				}
    			if (!vis[v]) {
    				dfs(dfs, v);
    			}
    		}
    	};

    	for (int i = 1; i <= V; i ++) {
    		if (!vis[i]) {
    			dfs(dfs, i);
    			if (!ok) {
    				break;
    			}
    		}
    	}
    	if (ok) {
    		std::cout << "Yes\n";
    	} else {
    		std::cout << "No\n";
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