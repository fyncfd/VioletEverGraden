/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-15 22:55:08
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

    bool g[7][7] = {false};
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i != j && i + j != 7) {
                g[i][j] = true;
            }
        }
    }

    std::vector<std::vector<int>> dp(n + 1, std::vector<int> (7, INF));
    for (int j = 1; j <= 6; j ++) {
    	dp[1][j] = ((a[1] == j) ? 0 : 1);
    }

    for (int i = 2; i <= n; i ++) {
        for (int v = 1; v <= 6; v ++) {
            dp[i][v] = INF;
            for (int u = 1; u <= 6; u ++) {
                if (g[u][v]) {
                    dp[i][v] = std::min(dp[i][v], dp[i - 1][u] + (a[i] == v ? 0 : 1));
                }
            }
        }
    }

    int ans = *std::min_element(dp[n].begin() + 1, dp[n].end());

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
3
1 4 2
4
3 4 6 3
10
6 1 4 3 1 3 2 5 4 4

0
1
4


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