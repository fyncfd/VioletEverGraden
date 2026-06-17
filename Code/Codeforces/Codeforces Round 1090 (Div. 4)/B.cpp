/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-08 18:23:33
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
    int n = 7;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::sort(a.begin() + 1, a.end(), [&](int a, int b) -> bool {
    	return a < b;
    });

    int ans = a[7];
    for (int i = 1; i <= 6; i ++) {
    	ans -= a[i];
    }

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4
41 41 41 41 41 41 41
6 9 4 20 6 7 67
1 2 3 4 5 6 7
6 7 6 7 6 7 6

-205
15
-14
-31


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