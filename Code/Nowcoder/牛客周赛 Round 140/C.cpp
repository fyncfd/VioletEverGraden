/*
* @Author: AlgoStruggler
* @Create Time: 2026-04-19 19:36:19
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
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);

    for (int i = 0; i < n; i ++) {
    	std::cin >> s[i];
    }

    int ans = 0;
    for (int i = 0; i + 1 < n; i ++) {
        for (int j = 0; j + 1 < m; j ++) {
            char a = s[i][j];
            char b = s[i][j + 1];
            char c = s[i + 1][j];
            char d = s[i + 1][j + 1];

            if (b != c && c != d && b != d) {
                ans ++;
            }

            if (a != c && c != d && a != d) {
                ans ++;
            }

            if (a != b && b != d && a != d) {
                ans ++;
            }

            if (a != b && b != c && a != c) {
                ans ++;
            }
        }
    }
    
    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

2 3
012
210

4


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