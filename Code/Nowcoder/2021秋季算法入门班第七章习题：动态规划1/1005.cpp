/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-13 02:46:23
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
    int F, V;
    std::cin >> F >> V;

    std::vector<std::vector<int>> a(F + 1, std::vector<int> (V + 1));
    for (int i = 1; i <= F; i ++) {
    	for (int j = 1; j <= V; j ++) {
    		std::cin >> a[i][j];
    	}
    }

    std::vector<std::vector<int>> dp(F + 1, std::vector<int> (V + 1, -INF));
    for (int j = 1; j <= V; j ++) {
        dp[1][j] = a[1][j];
    }
    for (int i = 2; i <= F; i ++) {
    	for (int j = 1; j <= V; j ++) {
    		for (int k = i - 1; k < j; k ++) {
    			dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + a[i][j]);
    		}
    	}
    }

    int ans = -1;
    for (int j = F; j <= V; j ++) {
        ans = std::max(ans, dp[F][j]);
    }
    std::cout << ans << '\n';
    int cnt = F;
    int cur = ans;
    std::vector<int> path(F + 1, 0);
    int lastPos = V + 1;
    for (int i = F; i >= 1; i --) {
        for (int j = 1; j < lastPos; j ++) {
            if (dp[i][j] == cur) {
                path[i] = j;
                cur -= a[i][j];
                lastPos = j;
                break;
            }
        }
    }

    for (int i = 1; i <= F; i ++) {
        std::cout << path[i] << " \n"[i == F];
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3 5
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 -20 20

53
2 4 5


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