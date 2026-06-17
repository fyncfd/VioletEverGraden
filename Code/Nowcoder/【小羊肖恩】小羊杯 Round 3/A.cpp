/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-18 21:02:52
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
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    int m = n / 2;
    if (m == 0) {
    	std::cout << 0 << '\n';
    	return ;
    }

    std::vector<i64> dif(m + 1, 0);
    for (int i = 1; i <= m; i ++) {
    	dif[i] = a[i] - a[n - i + 1];
    }

    i64 ans = 0; i64 pre = 0;
    for (int i = 1; i <= m; i ++) {
    	ans += std::abs(dif[i] - pre);
    	pre = dif[i];
    }

    ans += std::abs(0 - pre);
    ans /= 2;

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4
2
3 5
1
9
4
1 2 3 4
5
1 4 5 2 3

2
0
3
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