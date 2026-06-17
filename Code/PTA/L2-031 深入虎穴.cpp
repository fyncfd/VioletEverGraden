/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 15:34:36
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
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> g(N + 1);
    std::vector<int> deg(N + 1, 0);
    for (int i = 1; i <= N; i ++) {
    	int K;
    	std::cin >> K;

    	for (int j = 1; j <= K; j ++) {
    		int D;
    		std::cin >> D;
    		g[i].push_back(D);
    		deg[D] ++;
    	}
    }

    int root = 0;
    for (int i = 1; i <= N; i ++) {
    	if (deg[i] == 0) {
    		root = i;
    	}
    }

    std::vector<int> dep(N + 1, 1);
    dep[root] = 1;
    auto dfs = [&](auto &&dfs, int u, int fa) -> void {
    	for (auto v : g[u]) {
    		if (v == fa) {
    			continue;
    		}
    		dep[v] = dep[u] + 1;
    		dfs(dfs, v, u);
    	}
    };

    dfs(dfs, root, -1);

    int ans = 0; int max = 0;
    for (int i = 1; i <= N; i ++) {
    	if (max < dep[i]) {
    		max = dep[i];
    		ans = i;
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

    // for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}