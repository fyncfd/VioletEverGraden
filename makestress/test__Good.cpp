/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-05 19:01:39
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
    i64 x, y;
    std::cin >> x >> y;

    i64 ans = std::max(x, y);
    for (i64 i = x; i > 0; i /= 2) {
        for (i64 j = y; j > 0; j /= 2) {
            i64 res = i ^ j;
            ans = std::max(res, ans);
        }
    }

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

5
10 12
7 8
0 13
32 32
100 57

14
15
13
48
120


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