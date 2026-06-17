/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-18 21:47:32
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

    std::vector<i64> a(n + 1);
    i64 xorsum = 0;
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    	xorsum ^= a[i];
    }

    if (xorsum == 0) {
    	int cnt = 0;
    	int xorcnt = 0;
    	for (int i = 1; i <= n; i ++) {
    		xorcnt ^= a[i];
    		if (xorcnt == 0) {
    			cnt ++;
    		}
    	}

    	std::cout << std::max(2, cnt) << '\n';
    } else {
    	int cnt = 0;
    	int xorcnt = 0;
    	for (int i = 1; i <= n; i ++) {
    		xorcnt ^= a[i];
    		if (xorcnt == xorsum) {
    			cnt ++;
    			xorcnt = 0;
    		}
    	}

    	std::cout << cnt << '\n';
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
5
1 1 1 1 1
3
1 3 2
4
1 2 3 4

5
2
1


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