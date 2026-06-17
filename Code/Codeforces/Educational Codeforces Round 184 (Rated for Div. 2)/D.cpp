/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-16 23:24:12
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

constexpr i64 n = 1000000000000;

static inline void VioletEverGraden() {
    i64 x, y, k;
    std::cin >> x >> y >> k;

    if (x <= y) {
    	if (k <= y - 1) {
    		std::cout << k << '\n';
    	} else {
    		k -= (y - 1);
    		i64 len = y - x;
    		int p = k / len;
    		if (p * y + x > n) {
    			std::cout << -1 << '\n';
    		}  else {
    			std::cout << p * y + x << '\n';
    		}
    	}
    } else {
    	if (k <= y - 1) {
    		std::cout << k << '\n';
    	} else {
    		std::cout << -1 << '\n';
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

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}