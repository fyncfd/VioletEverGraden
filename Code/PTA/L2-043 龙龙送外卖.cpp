/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 13:29:57
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
    int N, M;
    std::cin >> N >> M;

    int root = -1;
    std::vector<std::vector<int>> g(N + 1);
    std::vector<int> fa(N + 1, -1);
    for (int u = 1; u <= N; u ++) {
    	int v;
    	std::cin >> v;


    	if (v == -1) {
    		root = u;
    	} else {
    		g[u].push_back(v);
    		g[v].push_back(u);
    		fa[u] = v;
    	}
    }

    std::vector<int> dep(N + 1, 0);
    dep[root] = 1;
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
    	for (auto v : g[u]) {
    		if (v == p) {
    			continue;
    		}
    		dep[v] = dep[u] + 1;
    		dfs(dfs, v, u);
    	}
    };

    dfs(dfs, root, -1);

    std::vector<bool> vis(N + 1, false);
    vis[root] = true;
    int ans = 0, max = 0;
    int __ = M;
    while (__ --) {
    	int k;
    	std::cin >> k;

    	if (vis[k]) {
    		std::cout << 2 * ans - max + 1 << '\n';
    		continue;
    	}

    	int cnt = 0, cur = k;
    	while (!vis[cur]) {
    		vis[cur] = true;
    		cnt ++;
    		cur = fa[cur];
    		if (cur == -1) {
    			break;
    		}
    	}
    	ans += cnt;
    	max = std::max(max, dep[k]);

    	std::cout << 2 * ans - max + 1 << '\n';
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