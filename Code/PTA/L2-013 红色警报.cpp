/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 11:32:40
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

    std::vector<std::vector<int>> g(N + 1);
    std::vector<int> deg(n + 1, 0);
    int __ = M;
    while (__ --) {
    	int u, v;
    	std::cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	deg[u] ++; deg[v] ++;
    }

    for (int i = 1; i <= n; i ++) {

    }

    int K;
    std::cin >> K;

    for (int i = 1; i <= K; i ++) {
    	int u;
    	std::cin >> u;
    	deg[u] = -1;
    	for (auto v : g[u]) {
    		deg[v] --;
    		bool ok = false;
    		if (deg[v] == 0) {
    			std::cout << "Red Alert: City k is lost!\n";
    			ok = true;
    		}
    		if (!ok) {
    			std::cout << "City k is lost.\n";
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