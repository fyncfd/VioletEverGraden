/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-16 00:19:23
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

    std::vector<i64> f(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> f[i];
    }

    std::vector<i64> a(n + 1);
    for (int i = 2; i < n; i ++) {
    	a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
    }

    i64 f1 = 0;
    for (int i = 2; i < n; i ++) {
    	f1 += a[i] * (i - 1);
    }
    a[n] = (f[1] - f1) / (n - 1);

    i64 f2 = 0;
    for (int i = 3; i < n; i ++) {
    	f2 += a[i] * (i - 2);
    }
    a[1] =f[2] - f2 - a[n] * (n - 2);

    for (int i = 1; i <= n; i ++) {
    	std::cout << a[i] << " \n"[i == n];
    } 
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

4
4
17 9 9 13
6
-37 -32 -15 4 27 42
5
-26 -32 -24 -4 2
2
420 -69

1 4 2 3
3 6 1 2 -4 -7
-6 7 6 -7 -6
-69 420


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