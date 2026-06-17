/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-12 23:25:29
* "To the Splendor of ACM-ICPC, We Consecrate Our AC Triumphs."
*/
#define  _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O2")
#include "bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ldb = long double;
typedef __int128 i128;
typedef unsigned __int128 u128;

const double eps = 1e-9;
constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr i64 mod = 998244353;
constexpr i64 MOD = 1e9 + 7;
constexpr int MAXN = 0;

static inline void VioletEverGraden() {
    int n;
    std::cin >> n;

    std::vector<std::vector<i64>> dp(4, std::vector<i64> (n + 1, 0LL));
    dp[1][0] = dp[2][0] = dp[3][0] = 0LL;
    dp[1][1] = dp[2][1] = dp[3][1] = 1LL;
    dp[1][2] = dp[2][2] = dp[3][2] = 3LL;

    for (int i = 3; i <= n; i ++) {
    	dp[1][i] = (dp[2][i - 1] + dp[3][i - 1] + dp[2][i - 2] + dp[3][i - 2]) % MOD;
    	dp[2][i] = (dp[1][i - 1] + dp[3][i - 1] + dp[1][i - 2] + dp[3][i - 2]) % MOD;
    	dp[3][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[1][i - 2] + dp[2][i - 2]) % MOD;
    }

    i64 ans = (dp[1][n] + dp[2][n] + dp[3][n]) % MOD;

    std::cout << ans << '\n';
    
    /* 愿幸运女神与最纯粹的前行者同在。 */
/*
Test Sample

2
3
500

24
544984352


*/
}

signed main() {
#ifdef Algostruggler
    freopen("A.in", "r", stdin);
#endif // Algostruggler

    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

    /*std::cout << std::fixed << std::setprecision(9);
    std::cerr << std::fixed << std::setprecision(9);*/

    int _ = 1;
    for (std::cin >> _; _; _--)
        VioletEverGraden();

    return 0;
}