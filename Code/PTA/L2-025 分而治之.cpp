/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 19:12:40
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
    std::vector<int> d(N + 1, 0);
    for (int i = 1; i <= M; i ++) {
    	int u, v;
    	std::cin >> u >> v;

    	g[u].push_back(v);
    	g[v].push_back(u);

    	d[u] ++; d[v] ++;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i ++) {
    	if (d[i] == 0) {
    		cnt ++;
    	}
    }

    int K;
    std::cin >> K;

    for (int i = 1; i <= K; i ++) {
    	int Np;
    	std::cin >> Np;

    	int num = cnt;
    	std::vector<int> deg = d;
    	while (Np --) {
    		int u;
    		std::cin >> u;
    		if (deg[u] > 0) {
	    		num ++;
	    		deg[u] = 0;
	    		for (auto v : g[u]) {
	    			if (deg[v] > 0) {
		    			deg[v] --;
		    			if (deg[v] == 0) {
		    				num ++;
		    			}
	    			}
	    		}
	    	}
    	}

    	if (num == N) {
    		std::cout << "YES\n";
    	} else {
    		std::cout << "NO\n";
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