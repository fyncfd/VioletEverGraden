/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-16 16:55:38
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
    int n; i64 a;
    std::cin >> n >> a;

    std::vector<i64> v(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> v[i];
    }

    int ans1 = a + 1; int cnt1 = 0;
    for (int i = 1; i <= n; i ++) {
        if (std::abs(v[i] - ans1) < std::abs(v[i] - a)) {
            cnt1 ++;
        }
    }

    int ans2 = a - 1; int cnt2 = 0;
    for (int i = 1; i <= n; i ++) {
        if (std::abs(v[i] - ans2) < std::abs(v[i] - a)) {
            cnt2 ++;
        }
    }

    if (cnt1 > cnt2) {
        std::cout << ans1 << '\n';
    } else {
        std::cout << ans2 << '\n';
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
7 21
10 20 30 40 50 60 70
6 500
200 200 300 500 600 600
2 7
7 7

pos : 2
22
pos : 3
499
pos : 0
8


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