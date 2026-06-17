/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-06 16:10:14
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
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    auto check = [&](int l, int r) -> bool {
    	if (l == r) {
    		return false;
    	}
	    for (int i = l; i < r; i ++) {
	        if (s[i] == s[i + 1]) {
	        	return false;
	        }
	    }
	    return true;
    };

    s = " " + s;
    std::vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i ++) {
        for (int j = std::max(0, i - k); j < i; j ++) {
            int len = i - j;
            if (len <= k && !check(j + 1, i)) {
                dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }
    }

    std::cout << dp[n] - 1 << "\n";
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4
5 2
10101
6 3
000111
7 4
1001101
6 3
101100

4
1
1
2


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