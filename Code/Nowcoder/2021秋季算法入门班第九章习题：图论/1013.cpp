/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-30 16:38:47
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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> dis(2000001, INF);
    [&](int s) -> void {
    	struct Node {
    		int id, d;
    	};
    	std::queue<Node > q;
    	dis[s] = 0;
    	q.push({s, dis[s]});

    	while (!q.empty()) {
    		auto [u, d] = q.front();
    		q.pop();

    		if (u < K) {
	    		if (dis[u + 1] > dis[u] + 1) {
	    			dis[u + 1] = dis[u] + 1;
	    			q.push({u + 1, dis[u + 1]});
	    		}
	    	}
    		if (u > 0) {
	    		if (dis[u - 1] > dis[u] + 1) {
	    			dis[u - 1] = dis[u] + 1;
	    			q.push({u - 1, dis[u - 1]});
	    		}
	    	}
    		if (u < K) {
	    		if (dis[2 * u] > dis[u] + 1) {
	    			dis[2 * u] = dis[u] + 1;
	    			q.push({2 * u, dis[2 * u]});
	    		}
    		}
    	}
    }(N);

    std::cout << dis[K] << '\n';
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

    // xfor (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}