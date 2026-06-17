/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-04 15:55:20
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
    int n, m;
    std::cin >> n >> m;

    if (n == 1 && m == 1) {
    	std::cout << -1 << '\n';
    	return ;
    }

    if (n >= 2 && m >= 2) {
    	std::cout << -1 << '\n';
    	return ;
    }

   	if (n == 1 && m != 1) {
   		std::cout << '1';
   		for (int i = 1; i < m; i ++) {
   			std::cout << '0';
   		}
   	} else if (n != 1 && m == 1) {
   		std::cout << "1\n";
   		for (int i = 1; i < n; i ++) {
   			std::cout << "0\n";
   		}
   	}
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1 2

10

114 514

-1

2 1

1
0


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