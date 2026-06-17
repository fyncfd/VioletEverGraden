/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-14 13:18:00
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
    for (int u = 1; u <= N; u ++) {
    	int K;
    	std::cin >> K;
    	for (int i = 1; i <= K; i ++) {
    		int v;
    		std::cin >> v;

    		g[u].push_back(v);
    	}
    }

    int ans = 1;
    std::vector<int> f(1000006, -1);
    while (M --) {
    	int op;
    	std::cin >> op;

    	if (op == 0) {
    		int j;
    		std::cin >> j;

    		ans = g[ans][j - 1];
    	} else if (op == 1) {
    		int j;
    		std::cin >> j;
    		std::cout << ans << '\n';
    		f[j] = ans;
    	} else if (op == 2) {
    		int j;
    		std::cin >> j;
    		ans = f[j];
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