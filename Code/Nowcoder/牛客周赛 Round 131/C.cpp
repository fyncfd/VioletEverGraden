/*
* @Author: AlgoStruggler
* @Create Time: 2026-02-15 19:08:14
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

    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i ++) {
    	std::cin >> a[i];
    }

    std::vector<i64> b(m + 1);
    for (int i = 1; i <= m; i ++) {
    	std::cin >> b[i];
    }

    if (m > n) {
    	std::cout << "NO\n";;
    	return ;
    }

    int j = 1;
    for (int i = 1; i <= n && j <= m; i ++) {
        if (a[i] >= b[j]) {
            j ++;
        }
    }

    if (j > m) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
/*
愿幸运女神与最纯粹的前行者同在。 
Test Sample

3
4 3
5 4 3 3
4 3 2
5 3
100 50 30 20 10
50 20 50
4 2
8 4 2 1
4 2

YES
NO
YES


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