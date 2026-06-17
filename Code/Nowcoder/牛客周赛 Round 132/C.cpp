/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-22 19:07:07
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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<std::array<int, 2>> dp(n + 1, {INF, INF});
    dp[1][0] = 0; dp[1][1] = 1;
    
    for (int i = 2; i <= n; i ++) {
        if (std::gcd(a[i - 1], a[i]) > 1) {
            dp[i][0] = std::min(dp[i][0], dp[i - 1][0]);
        }
        if (a[i] != 1) {
            dp[i][0] = std::min(dp[i][0], dp[i - 1][1]);
        }
        if (a[i - 1] != 1) {
            dp[i][1] = std::min(dp[i][1], dp[i - 1][0] + 1);
        }
        dp[i][1] = std::min(dp[i][1], dp[i - 1][1] + 1);
    }
    
    int ans = std::min(dp[n][0], dp[n][1]);

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
5
2 3 6 1 10
4
2 2 2 2
6
6 1 5 6 2 15

2
0
3


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