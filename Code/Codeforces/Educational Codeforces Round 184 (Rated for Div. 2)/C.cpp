/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-16 22:41:08
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

    std::vector<i64> pre(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
    	pre[i] = pre[i - 1] + a[i];
    }

    auto f = [&](i64 x) -> i64 {
    	return x * x + x - pre[x];
    };

    i64 ans = -INF; i64 fl = f(0);
    for (int R = 1; R <= n; R ++) {
    	ans = std::max(pre[n] + f(R) - fl, ans);
    	fl = std::min(f(R), fl);
    }

    std::cout << ans << '\n';
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4
3
2 5 1
2
4 4
4
1 3 2 1
5
3 2 0 9 10

13
8
20
32


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