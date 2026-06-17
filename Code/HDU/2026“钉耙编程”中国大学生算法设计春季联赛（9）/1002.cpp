/*
* @Author: AlgoStruggler
* @Create Time: 2026-05-22 18:36:38
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

    i64 sum1 = 0, sum2 = 0, sum3 = 0;
    i64 tot1 = 0, tot2 = 0, tot3 = 0;
    for (int i = 1; i <= n; i ++) {
    	int a, b, c;
    	std::cin >> a >> b >> c;
    	if (a != 0) {
    		sum1 ++;
    		if (c != 0) {
    			tot1 ++;
    		}
    	}
    	if (b != 0) {
    		sum2 ++;
    		if (c != 0) {
    			tot2 ++;
    		}
    	}
    	if (a != 0 && b != 0) {
    		sum3 ++;
    		if (c != 0) {
    			tot3 ++;
    		}
    	}
    }

    f80 ans1 = -1, ans2 = -1, ans3 = -1;
    if (sum1 != 0) {
    	ans1 = 1.0 * tot1 / sum1;
    }
    if (sum2 != 0) {
    	ans2 = 1.0 * tot2 / sum2;
    }
    if (sum3 != 0) {
    	ans3 = 1.0 * tot3 / sum3;
    }

    std::cout << std::max({ans1, ans2, ans3}) * 100 << "%" << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

1
4
1 0 1
0 1 0
1 0 1
1 0 0

66.67%


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    std::cout << std::fixed << std::setprecision(2), std::cerr << std::fixed << std::setprecision(2);

    for (int _ = [&]() -> int { int T; std::cin >> T; return T; }(); _; _ --)
        VioletEverGraden();

    return 0;
}