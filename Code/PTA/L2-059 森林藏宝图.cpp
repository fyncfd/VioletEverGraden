/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-21 20:43:47
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
    int n;
    std::cin >> n;

    struct pii {
    	int v, w;
    };
    std::vector<std::vector<pii>> g(n);
    std::vector<int> deg(n, 0);
    for (int u = 1; u < n; u ++) {
    	int v, w;
    	std::cin >> v >> w;
    	g[v].push_back({u, w});
    	deg[v] ++;
    }

  	struct ipp {
  		int id, w;
  	};
    std::vector<ipp> ans;
	auto dfs = [&](auto &&dfs, int u, int ma) -> void {
		for (auto [v, w] : g[u]) {
			int maa = std::min(w, ma);
			dfs(dfs, v, maa);
			if (deg[v] == 0)  {
				ans.push_back({v, maa});
			}
		}
	};


	dfs(dfs, 0, 1000);
/*    for (int i = 0; i < ans.size(); i ++) {
    	std::cerr << ans[i].id << ' ' << ans[i].w << "__\n";
    }*/

    if (ans.size()) {
    	sort(ans.begin(), ans.end(), [&](ipp a, ipp b) -> bool {
    		if (a.w == b.w) {
    			return a.id < b.id;
    		}
    		return a.w > b.w;
    	});

    	std::cout << ans[0].w << '\n';

    	std::vector<int> res;
    	for (int i = 0; i < ans.size(); i ++) {
    		if (ans[i].w == ans[0].w) {
    			res.push_back(ans[i].id);
    		}
    	}

    	for (int i = 0; i < res.size(); i ++) {
    		std::cout << res[i] << " \n"[i + 1 == res.size()];
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